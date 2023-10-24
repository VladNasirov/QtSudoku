/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButtonEasy;
    QPushButton *pushButtonNormal;
    QPushButton *pushButtonHard;
    QLabel *label;
    QPushButton *pushButtonExpert;
    QTableWidget *SudokuTable;
    QMenuBar *menubar;
    QMenu *menuQTSudoku;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButtonEasy = new QPushButton(centralwidget);
        pushButtonEasy->setObjectName("pushButtonEasy");
        pushButtonEasy->setGeometry(QRect(330, 200, 89, 25));
        pushButtonNormal = new QPushButton(centralwidget);
        pushButtonNormal->setObjectName("pushButtonNormal");
        pushButtonNormal->setGeometry(QRect(330, 260, 89, 25));
        pushButtonHard = new QPushButton(centralwidget);
        pushButtonHard->setObjectName("pushButtonHard");
        pushButtonHard->setGeometry(QRect(330, 320, 89, 25));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(320, 150, 111, 20));
        pushButtonExpert = new QPushButton(centralwidget);
        pushButtonExpert->setObjectName("pushButtonExpert");
        pushButtonExpert->setGeometry(QRect(330, 380, 89, 25));
        SudokuTable = new QTableWidget(centralwidget);
        SudokuTable->setObjectName("SudokuTable");
        SudokuTable->setGeometry(QRect(30, 10, 150, 150));
        SudokuTable->setMaximumSize(QSize(16777213, 16777215));
        SudokuTable->setInputMethodHints(Qt::ImhDigitsOnly);
        SudokuTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        SudokuTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        MainWindow->setCentralWidget(centralwidget);
        SudokuTable->raise();
        label->raise();
        pushButtonEasy->raise();
        pushButtonExpert->raise();
        pushButtonHard->raise();
        pushButtonNormal->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuQTSudoku = new QMenu(menubar);
        menuQTSudoku->setObjectName("menuQTSudoku");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuQTSudoku->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonEasy->setText(QCoreApplication::translate("MainWindow", "Easy", nullptr));
        pushButtonNormal->setText(QCoreApplication::translate("MainWindow", "Normal", nullptr));
        pushButtonHard->setText(QCoreApplication::translate("MainWindow", "Hard", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Select difficulty:", nullptr));
        pushButtonExpert->setText(QCoreApplication::translate("MainWindow", "Expert", nullptr));
        menuQTSudoku->setTitle(QCoreApplication::translate("MainWindow", "QTSudoku", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
