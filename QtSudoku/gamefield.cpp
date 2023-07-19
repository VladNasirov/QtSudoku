#include "gamefield.h"
#include <iostream>
#include <QDebug>
#include <QRandomGenerator>
GameField::GameField(QObject *parent)
    : QObject{parent}
{
    sudokuPower=3;
    numRows=sudokuPower*sudokuPower;
    numCols=sudokuPower*sudokuPower;
    fillVecFunc();
    generateBaseField();
}

void GameField::fillVecFunc()
{
    funcVec.push_back(&GameField::transpose);
    funcVec.push_back(&GameField::swapColsArea);
    funcVec.push_back(&GameField::swapRowsArea);
    funcVec.push_back(&GameField::swapRowsSmall);
    funcVec.push_back(&GameField::swapColsSmall);
}

void GameField::shuffleField()
{
    int shuffleNumber = QRandomGenerator::global()->bounded(0, 100);
    qInfo()<<"ShuffleNumb = "<<shuffleNumber;
    for(int i=0; i<shuffleNumber; i++)
    {
        int funcNum=QRandomGenerator::global()->bounded(0, funcVec.size());
        (this->*funcVec[funcNum])();
    }
}

void GameField::generateSudoku()
{
    shuffleField();
    correctAnswer=field;
}


void GameField::transpose()
{
    qInfo()<<Q_FUNC_INFO;
    QVector<QVector<Tile>> tmp;
    tmp.resize(numRows);
    for (int i = 0; i < numRows; ++i) {
        tmp[i].resize(numCols);
    }
    for (int r=0; r<numRows; r++)
    {
        for (int c=0; c<numCols; c++)
        {
            tmp[r][c].value=field[c][r].value;
        }
    }
    field=tmp;
}
void GameField::swapRowsSmall()
{
    qInfo()<<Q_FUNC_INFO;
    int lowerBound = QRandomGenerator::global()->bounded(0, sudokuPower);
    int randomR1 = QRandomGenerator::global()->bounded(lowerBound, lowerBound+sudokuPower);
    int randomR2;
    do
    {
        randomR2 = QRandomGenerator::global()->bounded(lowerBound, lowerBound+sudokuPower);
    }while(randomR1==randomR2);

    swapRows(randomR1, randomR2);
}
void GameField::swapRows(int index1, int index2)
{
    QVector<Tile> tmp;
    tmp=field[index1];
    field[index1]=field[index2];
    field[index2]=tmp;
}
void GameField::swapColsSmall()
{
    qInfo()<<Q_FUNC_INFO;
    int lowerBound = QRandomGenerator::global()->bounded(0, sudokuPower);
    int randomR1 = QRandomGenerator::global()->bounded(lowerBound, lowerBound+sudokuPower);
    int randomR2;
    do
    {
        randomR2 = QRandomGenerator::global()->bounded(lowerBound, lowerBound+sudokuPower);
    }while(randomR1==randomR2);
    swapCols(randomR1, randomR2);
}
void GameField::swapCols(int index1, int index2)
{
    for (int row = 0; row < numRows; ++row)
    {
        Tile temp = field[row][index1];
        field[row][index1] = field[row][index2];
        field[row][index2] = temp;
    }
}

void GameField::swapRowsArea()
{
    qInfo()<<Q_FUNC_INFO;
    int randomR1 = QRandomGenerator::global()->bounded(0, sudokuPower);
    int randomR2;
    do
    {
        randomR2 = QRandomGenerator::global()->bounded(0, sudokuPower);
    }while(randomR1==randomR2);
    for(int i=0; i<sudokuPower; i++)
    {
        swapRows(randomR1*sudokuPower+i, randomR2*sudokuPower+i);
    }
}

void GameField::swapColsArea()
{
    qInfo()<<Q_FUNC_INFO;
    int randomR1 = QRandomGenerator::global()->bounded(0, sudokuPower);
    int randomR2;
    do
    {
        randomR2 = QRandomGenerator::global()->bounded(0, sudokuPower);
    }while(randomR1==randomR2);
    for(int i=0; i<sudokuPower; i++)
    {
        swapCols(randomR1*sudokuPower+i, randomR2*sudokuPower+i);
    }
}

bool GameField::checkRows()
{
    return true;
}

bool GameField::checkColumns()
{
     return true;
}

bool GameField::checkBoxes()
{
     return true;
}

void GameField::generateBaseField()
{

    field.resize(numRows);
     for (int i = 0; i < numRows; ++i) {
         field[i].resize(numCols);
    }
    for (int r=0; r<numRows; r++)
    {
        for (int c=0; c<numCols; c++)
        {
            field[r][c].row=r;
            field[r][c].column=c;
            if((c+r*8+1)>9)//for other value
            {
                if((c+r*8+1)%9==0)
                {
                    field[r][c].value=9;
                }
                else
                {
                    field[r][c].value=(c+r*8+1)%9;
                }
            }
            else
            {
             field[r][c].value=c+r*8+1;
            }
        }
    }
}

void GameField::printField()
{
    for (int r=0; r<numRows; r++)
    {
        for (int c=0; c<numCols; c++)
        {
            field[r][c].row=r;
            field[r][c].column=c;
            std::cout<<"["<<field[r][c].row<<field[r][c].column<<"]"<<"="<<field[r][c].value<<" ";
        }
        std::cout<<std::endl;
    }
}
