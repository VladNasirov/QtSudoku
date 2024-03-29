#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QObject>
#include <QVector>
#include "Tile.h"

enum class difficulty
{
    Unset,
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
    bool checkField();

    void generateBaseField();
    void printField();
    void printCorrectField();

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

    Tile getValue(int r, int c);
    Tile getCorrectValue(int r, int c);

    void setNumCols(int c);

    void setValue(int r, int c, int num);
    void setDifficulty(difficulty d);
    void shiftRow(int r, int num);

    void setRightAnswer();
    void hideField();
    void hideTiles(int hidenumber);

    void start();

    Q_INVOKABLE QVector<QVector<Tile>> getField();
    QVector<QVector<Tile>> getCorrectField();
    void setField(QVector<QVector<Tile>> f);
    explicit GameField(const GameField& gf);
signals:

    void gameOver();
public slots:
    void wrongAnswer(QString val);
private:
    QVector<QVector<Tile>> field;
    QVector<QVector<Tile>> correctAnswer;
    QVector<void(GameField::*)()> funcVec;
    int numRows;
    int numCols;
    int sudokuPower;
    difficulty dif;
    int maxWrongCounter;

};

#endif // GAMEFIELD_H
