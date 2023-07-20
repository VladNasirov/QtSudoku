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
    bool findEmptyCell();
    bool isValidMove(const QVector<QVector<Tile>>& sudoku, int row, int col, Tile num);
    bool solveSudoku(QVector<QVector<Tile>>& sudoku);
    int countSudokuSolutions(QVector<QVector<Tile>> sudoku);
signals:

private:
    int solutionNumber;
    QSharedPointer<GameField> field;
};

#endif // SOLVER_H
