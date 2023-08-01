#include "mainwindow.h"

#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
//    GameField gf;
//    Solver s;
//    gf.printField();
//    gf.shuffleField();
//    gf.checkField();

//    qInfo()<<" swapped : ";
//    gf.printField();
//    gf.hideField();
//    s.setField(&gf);
//    qInfo()<<s.countSudokuSolutions();
    return a.exec();
}
