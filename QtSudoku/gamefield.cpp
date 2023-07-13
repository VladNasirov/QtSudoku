#include "gamefield.h"
#include <iostream>
#include <QDebug>
GameField::GameField(QObject *parent)
    : QObject{parent}
{
    generateBaseField(9, 9);
}

void GameField::shuffleField()
{

}

void GameField::generateSudoku(unsigned int difficulty)
{


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

void GameField::generateBaseField(int nR, int nC)
{

    field.resize(nR);
     for (int i = 0; i < nR; ++i) {
         field[i].resize(nC);
    }
    for (int r=0; r<9; r++)
    {
        for (int c=0; c<9; c++)
        {
            field[r][c].row=r;
            field[r][c].column=c;
            if((c+r*8+1)>9)
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
    for (int r=0; r<9; r++)
    {
        for (int c=0; c<9; c++)
        {
            field[r][c].row=r;
            field[r][c].column=c;
            std::cout<<"["<<field[r][c].row<<field[r][c].column<<"]"<<"="<<field[r][c].value<<" ";
        }
        std::cout<<std::endl;
    }
}
