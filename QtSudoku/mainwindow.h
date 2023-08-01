#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

    void on_pushButtonNormal_clicked();

    void on_pushButtonHard_clicked();

    void on_pushButtonExpert_clicked();

private:
    Ui::MainWindow *ui;
    GameField gf;
    Solver s;
};
#endif // MAINWINDOW_H
