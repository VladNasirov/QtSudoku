//#include "mainwindow.h"

#include <QApplication>
#include "gamefield.h"
#include "solver.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;

    //w.show();
    QSharedPointer<GameField> sharedPtrGF(new GameField);
    Solver s(&a, sharedPtrGF);
    sharedPtrGF->printField();
    sharedPtrGF->shuffleField();
    qInfo()<<" swapped : ";
    sharedPtrGF->printField();
    qInfo()<<s.countSudokuSolutions();
    return a.exec();
}
