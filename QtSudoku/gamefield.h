#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QObject>
#include <QVector>
#include "Tile.h"

enum class difficulty
{
    Easy,
    Normal,
    Hard,
    Expert
};

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

    bool checkRow(int r);
    bool checkColumn(int c);
    bool checkBox(int bn);


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

    int getSudokuPower();
    void setSudokuPower(int pow);

    int getNumRows();
    void setNumRows(int r);

    int getNumCols();
    void setNumCols(int c);

    void setValue(int r, int c, int num);


    void hideField();
    void hideTiles(int hidenumber);
    QVector<QVector<Tile>> getField();
    void setField(QVector<QVector<Tile>> f);

signals:



private:
    QVector<QVector<Tile>> field;
    QVector<QVector<Tile>> correctAnswer;
    QVector<void(GameField::*)()> funcVec;
    int numRows;
    int numCols;
    int sudokuPower;
    difficulty dif;
};

#endif // GAMEFIELD_H
