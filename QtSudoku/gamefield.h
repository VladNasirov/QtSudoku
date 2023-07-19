#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QObject>
#include <QVector>
#include "Tile.h"
class GameField : public QObject
{
    Q_OBJECT
public:
    explicit GameField(QObject *parent = nullptr);
    void shuffleField();
    void generateSudoku();
    bool checkRows();
    bool checkColumns();
    bool checkBoxes();
    void generateBaseField();
    void printField();

    void swapCols(int index1, int index2);
    void swapRows(int index1, int index2);
    void transpose();
    void swapRowsSmall();
    void swapColsSmall();
    void swapRowsArea();
    void swapColsArea();

    void fillVecFunc();
signals:



private:
    QVector<QVector<Tile>> field;
    QVector<QVector<Tile>> correctAnswer;
    QVector<void(GameField::*)()> funcVec;
    int numRows;
    int numCols;
    int sudokuPower;
};

#endif // GAMEFIELD_H
