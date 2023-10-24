#include "mainwindow.h"

#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    GameField gf;
    Solver s;
    gf.start();
    s.setField(&gf);
    qInfo()<<s.countSudokuSolutions();
    return a.exec();
}
