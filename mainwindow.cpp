#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QIcon>
#include <QSoundEffect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/tictactoe.png"));
    QStringList modes = { "Two Players", "Vs AI" };
    bool ok;
    QString choice = QInputDialog::getItem(this, "Select Game Mode", "Mode:", modes, 0, false, &ok);

    if (!ok) {
        QApplication::quit();
        return;
    }

    if (choice == "Two Players") {
        currentMode = TwoPlayers;

        playerXName = QInputDialog::getText(this, "Player X", "Enter name for Player X:");
        playerOName = QInputDialog::getText(this, "Player O", "Enter name for Player O:");

    } else {
        currentMode = VsAI;

        playerXName = QInputDialog::getText(this, "Your Name", "Enter your name:");
        playerOName = "AI";
    }
    this->setWindowTitle("TicTacToe");

    defaultStyle = "QPushButton {"
                   "border: 1px solid gray;"
                   "border-radius: 9px;"
                   "font-size: 28px;"
                   "font-weight: bold;"
                   "}";

    QList<QPushButton*> buttons = {
        ui->button00, ui->button01, ui->button02,
        ui->button10, ui->button11, ui->button12,
        ui->button20, ui->button21, ui->button22
    };

    for (QPushButton* btn : buttons) {
        btn->setStyleSheet(defaultStyle);
        connect(btn, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
    }

    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::resetGame);
    this->adjustSize();
    this->setFixedSize(this->size());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::makeAIMove() {
    if (gameOver) return;

    QList<QPushButton*> buttons = {
        ui->button00, ui->button01, ui->button02,
        ui->button10, ui->button11, ui->button12,
        ui->button20, ui->button21, ui->button22
    };

    // 1. Попробовать победить самому (ИИ играет за "O")
    for (QPushButton* btn : buttons) {
        if (btn->text().isEmpty()) {
            btn->setText("O");

            // Проверим, победил ли ИИ
            QPushButton* b[3][3] = {
                {ui->button00, ui->button01, ui->button02},
                {ui->button10, ui->button11, ui->button12},
                {ui->button20, ui->button21, ui->button22}
            };
            bool win = false;

            for (int i = 0; i < 3; ++i) {
                if (b[i][0]->text() == "O" && b[i][1]->text() == "O" && b[i][2]->text() == "O") win = true;
                if (b[0][i]->text() == "O" && b[1][i]->text() == "O" && b[2][i]->text() == "O") win = true;
            }
            if (b[0][0]->text() == "O" && b[1][1]->text() == "O" && b[2][2]->text() == "O") win = true;
            if (b[0][2]->text() == "O" && b[1][1]->text() == "O" && b[2][0]->text() == "O") win = true;

            if (win) {
                xTurn = true;
                checkWin();
                return;
            }
            btn->setText("");
        }
    }

    // 2. Блокируем победный ход X (игрока)
    for (QPushButton* btn : buttons) {
        if (btn->text().isEmpty()) {
            btn->setText("X");

            // Проверим, победил бы игрок
            QPushButton* b[3][3] = {
                {ui->button00, ui->button01, ui->button02},
                {ui->button10, ui->button11, ui->button12},
                {ui->button20, ui->button21, ui->button22}
            };
            bool blockNeeded = false;

            for (int i = 0; i < 3; ++i) {
                if (b[i][0]->text() == "X" && b[i][1]->text() == "X" && b[i][2]->text() == "X") blockNeeded = true;
                if (b[0][i]->text() == "X" && b[1][i]->text() == "X" && b[2][i]->text() == "X") blockNeeded = true;
            }
            if (b[0][0]->text() == "X" && b[1][1]->text() == "X" && b[2][2]->text() == "X") blockNeeded = true;
            if (b[0][2]->text() == "X" && b[1][1]->text() == "X" && b[2][0]->text() == "X") blockNeeded = true;

            btn->setText("");

            if (blockNeeded) {
                btn->setText("O");
                xTurn = true;
                checkWin();
                return;
            }
        }
    }

    // 3. Если нет угроз и нет возможности выиграть - ходим в случайную свободную клетку
    QList<QPushButton*> freeButtons;
    for (QPushButton* btn : buttons) {
        if (btn->text().isEmpty())
            freeButtons.append(btn);
    }

    if (!freeButtons.isEmpty()) {
        int index = QRandomGenerator::global()->bounded(freeButtons.size());
        freeButtons[index]->setText("O");
        xTurn = true;
        checkWin();
    }
}
void MainWindow::handleButtonClick() {
    if (gameOver) return;
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if (btn->text() != "") return;

    // Звук нажатия
    QSoundEffect* clickSound = new QSoundEffect(this);
    clickSound->setSource(QUrl("qrc:/sounds/click.wav"));
    clickSound->setVolume(0.5);  // Громкость от 0.0 до 1.0
    clickSound->play();

    btn->setText(xTurn ? "X" : "O");
    xTurn = !xTurn;
    checkWin();

    if (!gameOver && currentMode == VsAI && !xTurn) {
        QTimer::singleShot(300, this, &MainWindow::makeAIMove);
    }
}

void MainWindow::checkWin() {
    QPushButton* b[3][3] = {
        {ui->button00, ui->button01, ui->button02},
        {ui->button10, ui->button11, ui->button12},
        {ui->button20, ui->button21, ui->button22}
    };

    QString winner = "";
    winningButtons.clear();

    // строки
    for (int i = 0; i < 3; ++i) {
        if (b[i][0]->text() != "" && b[i][0]->text() == b[i][1]->text() && b[i][0]->text() == b[i][2]->text()) {
            winner = b[i][0]->text();
            winningButtons = { b[i][0], b[i][1], b[i][2] };
        }
    }
    // столбцы
    for (int i = 0; i < 3; ++i) {
        if (b[0][i]->text() != "" && b[0][i]->text() == b[1][i]->text() && b[0][i]->text() == b[2][i]->text()) {
            winner = b[0][i]->text();
            winningButtons = { b[0][i], b[1][i], b[2][i] };
        }
    }
    // диагонали
    if (b[0][0]->text() != "" && b[0][0]->text() == b[1][1]->text() && b[0][0]->text() == b[2][2]->text()) {
        winner = b[0][0]->text();
        winningButtons = { b[0][0], b[1][1], b[2][2] };
    }
    if (b[0][2]->text() != "" && b[0][2]->text() == b[1][1]->text() && b[0][2]->text() == b[2][0]->text()) {
        winner = b[0][2]->text();
        winningButtons = { b[0][2], b[1][1], b[2][0] };
    }

    if (winner != "") {
        for (QPushButton* btn : winningButtons) {
            btn->setStyleSheet(
                "QPushButton {"
                "background-color: wheat;"
                "border: 3px solid orange;"
                "font-weight: bold;"
                "font-size: 37px;"
                "}"
                );

            QGraphicsOpacityEffect* effect = new QGraphicsOpacityEffect(btn);
            btn->setGraphicsEffect(effect);
            activeEffects.append(effect);

            QPropertyAnimation* anim = new QPropertyAnimation(effect, "opacity", this);
            anim->setDuration(1000);
            anim->setStartValue(1.0);
            anim->setEndValue(0.3);
            anim->setEasingCurve(QEasingCurve::InOutQuad);
            anim->setLoopCount(-1);
            anim->start();

            activeAnimations.append(anim);
        }
        if (winLine) {
            winLine->deleteLater();
            winLine = nullptr;
        }

        // Вычисляем координаты начала и конца линии
        QPoint start, end;
        int offset = 6;

        QPushButton* first = winningButtons.first();
        QPushButton* last = winningButtons.last();

        QPoint firstPos = first->mapTo(this, QPoint(0, 0));
        QPoint lastPos = last->mapTo(this, QPoint(0, 0));

        if (first->y() == last->y()) {
            // Горизонталь
            start = QPoint(firstPos.x() + offset, firstPos.y() + first->height() / 2);
            end = QPoint(lastPos.x() + last->width() - offset, lastPos.y() + last->height() / 2);
        } else if (first->x() == last->x()) {
            // Вертикаль
            start = QPoint(firstPos.x() + first->width() / 2, firstPos.y() + offset);
            end = QPoint(lastPos.x() + last->width() / 2, lastPos.y() + last->height() - offset);
        } else {
            // Диагонали
            if (first == ui->button00) {
                start = QPoint(firstPos.x() + offset, firstPos.y() + offset);
                end = QPoint(lastPos.x() + last->width() - offset, lastPos.y() + last->height() - offset);
            } else {
                start = QPoint(firstPos.x() + first->width() - offset, firstPos.y() + offset);
                end = QPoint(lastPos.x() + offset, lastPos.y() + last->height() - offset);
            }
        }

        // Создаём линию
        winLine = new WinLineWidget(this);
        winLine->setLine(start, end);
        winLine->show();

        QString winnerName = (winner == "X") ? playerXName : playerOName;
        QMessageBox::information(this, "Game Over", winnerName + " wins!");
        gameOver = true;
        disableButtons();
        return;
    }

    // ничья
    bool isDraw = true;
    for (auto& row : b)
        for (auto& btn : row)
            if (btn->text() == "")
                isDraw = false;

    if (isDraw) {
        QMessageBox::information(this, "Game Over", "It's a draw!");
        disableButtons();
        gameOver = true;
    }
}

void MainWindow::disableButtons() {
    QList<QPushButton*> buttons = {
        ui->button00, ui->button01, ui->button02,
        ui->button10, ui->button11, ui->button12,
        ui->button20, ui->button21, ui->button22
    };

    for (QPushButton* btn : buttons) {
        btn->setEnabled(false);
    }
}

void MainWindow::resetGame() {
    gameOver = false;
    for (QPropertyAnimation* anim : activeAnimations) {
        if (anim) anim->stop();
    }
    activeAnimations.clear();

    for (QGraphicsOpacityEffect* eff : activeEffects) {
        for (QPushButton* btn : {
                                 ui->button00, ui->button01, ui->button02,
                                 ui->button10, ui->button11, ui->button12,
                                 ui->button20, ui->button21, ui->button22 }) {

            if (btn->graphicsEffect() == eff) {
                btn->setGraphicsEffect(nullptr);
                break;
            }
        }
    }
    activeEffects.clear();

    if (winLine) {
        winLine->deleteLater();
        winLine = nullptr;
    }

    QList<QPushButton*> buttons = {
        ui->button00, ui->button01, ui->button02,
        ui->button10, ui->button11, ui->button12,
        ui->button20, ui->button21, ui->button22
    };

    for (QPushButton* btn : buttons) {
        btn->setText("");
        btn->setEnabled(true);
        btn->setStyleSheet(defaultStyle);
    }

    xTurn = true;
}
