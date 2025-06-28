#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include "winlinewidget.h"
#include <QRandomGenerator>
#include <QTimer>
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleButtonClick();
    void resetGame();
    void checkWin();
    void disableButtons();

private:
    Ui::MainWindow *ui;
    bool xTurn = true;

    QList<QPushButton*> winningButtons;
    QList<QPropertyAnimation*> activeAnimations;
    QList<QGraphicsOpacityEffect*> activeEffects;
    QString defaultStyle;
    WinLineWidget* winLine = nullptr;

    enum GameMode { TwoPlayers, VsAI };

    QString playerXName;
    QString playerOName;
    GameMode currentMode = TwoPlayers;

    void makeAIMove();
    bool gameOver = false;
};

#endif // MAINWINDOW_H
