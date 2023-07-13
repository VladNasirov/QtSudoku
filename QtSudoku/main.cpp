//#include "mainwindow.h"

#include <QApplication>
#include "gamefield.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;

    //w.show();
    GameField g;
    g.printField();
    return a.exec();
}
