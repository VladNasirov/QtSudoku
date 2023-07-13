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
    void generateSudoku(unsigned int difficulty);
    bool checkRows();
    bool checkColumns();
    bool checkBoxes();
    void generateBaseField(int nR, int nC);
    void printField();
signals:



private:
    QVector<QVector<Tile>> field;
    QVector<QVector<Tile>> correctAnswer;
    int numRows;
    int numCols;
};

#endif // GAMEFIELD_H
