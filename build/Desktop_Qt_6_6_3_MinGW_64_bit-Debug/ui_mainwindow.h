/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QPushButton *button02;
    QPushButton *button20;
    QPushButton *button22;
    QPushButton *button10;
    QPushButton *resetButton;
    QPushButton *button01;
    QPushButton *button21;
    QPushButton *button12;
    QPushButton *button11;
    QPushButton *button00;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(443, 496);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName("gridLayout_3");
        button02 = new QPushButton(centralwidget);
        button02->setObjectName("button02");
        button02->setMinimumSize(QSize(100, 100));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe MDL2 Assets")});
        font.setBold(true);
        button02->setFont(font);
        button02->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 1px solid gray;\n"
"    border-radius: 9px;\n"
"    font-size: 24px;\n"
"}"));

        gridLayout_3->addWidget(button02, 0, 2, 1, 1);

        button20 = new QPushButton(centralwidget);
        button20->setObjectName("button20");
        button20->setMinimumSize(QSize(100, 100));
        button20->setFont(font);
        button20->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 1px solid gray;\n"
"    border-radius: 9px;\n"
"    font-size: 24px;\n"
"}"));

        gridLayout_3->addWidget(button20, 2, 0, 1, 1);

        button22 = new QPushButton(centralwidget);
        button22->setObjectName("button22");
        button22->setMinimumSize(QSize(100, 100));
        button22->setFont(font);
        button22->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 1px solid gray;\n"
"    border-radius: 9px;\n"
"    font-size: 24px;\n"
"}"));

        gridLayout_3->addWidget(button22, 2, 2, 1, 1);

        button10 = new QPushButton(centralwidget);
        button10->setObjectName("button10");
        button10->setMinimumSize(QSize(100, 100));
        button10->setFont(font);
        button10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 1px solid gray;\n"
"    border-radius: 9px;\n"
"    font-size: 24px;\n"
"}"));

        gridLayout_3->addWidget(button10, 1, 0, 1, 1);

        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");
        resetButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: lightgray;\n"
"    border-radius: 10px;\n"
"    padding: 6px 12px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: silver;\n"
"}"));

        gridLayout_3->addWidget(resetButton, 4, 0, 1, 1);

        button01 = new QPushButton(centralwidget);
        button01->setObjectName("button01");
        button01->setMinimumSize(QSize(100, 100));
        button01->setFont(font);
        button01->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 1px solid gray;\n"
"    border-radius: 9px;\n"
"    font-size: 24px;\n"
"}"));

        gridLayout_3->addWidget(button01, 0, 1, 1, 1);

        button21 = new QPushButton(centralwidget);
        button21->setObjectName("button21");
        button21->setMinimumSize(QSize(100, 100));
        button21->setFont(font);
        button21->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 1px solid gray;\n"
"    border-radius: 9px;\n"
"    font-size: 24px;\n"
"}"));

        gridLayout_3->addWidget(button21, 2, 1, 1, 1);

        button12 = new QPushButton(centralwidget);
        button12->setObjectName("button12");
        button12->setMinimumSize(QSize(100, 100));
        button12->setFont(font);
        button12->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 1px solid gray;\n"
"    border-radius: 9px;\n"
"    font-size: 24px;\n"
"}"));

        gridLayout_3->addWidget(button12, 1, 2, 1, 1);

        button11 = new QPushButton(centralwidget);
        button11->setObjectName("button11");
        button11->setMinimumSize(QSize(100, 100));
        button11->setFont(font);
        button11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 1px solid gray;\n"
"    border-radius: 9px;\n"
"    font-size: 24px;\n"
"}"));

        gridLayout_3->addWidget(button11, 1, 1, 1, 1);

        button00 = new QPushButton(centralwidget);
        button00->setObjectName("button00");
        button00->setMinimumSize(QSize(100, 100));
        button00->setFont(font);
        button00->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 1px solid gray;\n"
"    border-radius: 9px;\n"
"    font-size: 24px;\n"
"}"));

        gridLayout_3->addWidget(button00, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(0, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout_3->addItem(verticalSpacer, 3, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        button02->setText(QString());
        button20->setText(QString());
        button22->setText(QString());
        button10->setText(QString());
        resetButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        button01->setText(QString());
        button21->setText(QString());
        button12->setText(QString());
        button11->setText(QString());
        button00->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
