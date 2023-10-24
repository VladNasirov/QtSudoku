#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QPushButton>
#include "gamefield.h"
#include "solver.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonEasy_clicked();
    void toggleTableLayout();
    void on_pushButtonNormal_clicked();

    void on_pushButtonHard_clicked();

    void on_pushButtonExpert_clicked();

private:
    Ui::MainWindow *ui;
    QWidget *centralWidget;
    QStackedLayout *stackedLayout;
    QWidget *DifficultyWidget;
    QWidget *TabletWidget;
    QTableWidget *SudokuTable;
    QPushButton *pushButtonEasy;
    QPushButton *pushButtonNormal;
    QPushButton *pushButtonHard;
    QPushButton *pushButtonExpert;

    GameField gf;
    Solver s;
};
#endif // MAINWINDOW_H
