//#include "mainwindow.h"

#include <QApplication>
#include "gamefield.h"
#include "solver.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;

    //w.show();
    GameField gf;
    Solver s;
    gf.printField();
    gf.shuffleField();
    qInfo()<<" swapped : ";
    gf.printField();
    gf.hideField();
    qInfo()<<"With hidden tiles: ";
    gf.printField();
    s.setField(&gf);
    qInfo()<<s.countSudokuSolutions();
    return a.exec();
}
