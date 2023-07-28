#ifndef SOLVER_H
#define SOLVER_H

#include "gamefield.h"
#include <QObject>
#include <QSharedPointer>
class Solver : public QObject
{
    Q_OBJECT
public:
    explicit Solver(QObject *parent = nullptr);
    bool findEmptyCell(int& row, int& col);
    void setField(GameField& gf);
    bool isValidMove(int row, int col, int num);
    bool solveSudoku();
    int countSudokuSolutions();
signals:

private:
    int solutionNumber;
    GameField copyfield;
};

#endif // SOLVER_H
