#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QPushButton>
#include "gamefield.h"
#include "solver.h"
#include "tilewidget.h"


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

    void createEmptyField();

    void showField();
signals:
    void fieldCreated();
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

    QVector<TileWidget*> tiles;


    GameField gf;
    Solver s;
};
#endif // MAINWINDOW_H
