#include "solver.h"
#include <iostream>
Solver::Solver(QObject *parent)
    : QObject{parent}
{
}
bool Solver::findEmptyCell(int& row, int& col)//переписать
{
    for(int i=0; i<copyfield.getNumRows(); i++)
    {
        for(int j=0; j<copyfield.getNumCols(); j++)
        {
            if(copyfield.getField()[i][j].value==0)
            {
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}

void Solver::setField(GameField* gf)
{
    copyfield.setField(gf->getField());
    copyfield.setNumCols(gf->getNumCols());
    copyfield.setNumRows(gf->getNumRows());
    copyfield.setSudokuPower(gf->getSudokuPower());
    //copyfield.printField();
}
bool Solver::isValidMove(int row, int col, int num) {
    // Проверьте, что num не нарушает правила судоку для строки, столбца и малого квадрата 3x3
    // ...
    GameField tmp;
    tmp.setField(copyfield.getField());
    tmp.setValue(row, col, num);

    if(tmp.checkBoxes())
    {
        if(tmp.checkRows())
        {
            if(tmp.checkColumns())
            {
                std::cout<<"Found the right number!"<<row<<col<<num<<std::endl;
                copyfield.setValue(row, col, num);
                std::cout<<std::endl;
                tmp.printField();
                std::cout<<std::endl;
                return true;
            }
        }
    }
    return false;
}

bool Solver::solveSudoku() {
    int row, col;
    if (!findEmptyCell(row, col)) {
        return true;
    }
    for (int num = 1; num <= 9; ++num) {
         if (isValidMove(row, col, num)) {
                // Присваиваем num в текущую пустую клетку
             copyfield.setValue(row, col, num);

                // Рекурсивно продолжаем заполнять оставшиеся клетки
                if (solveSudoku()) {
                    return true;
                }

                // Если не получилось, отменяем изменение и пробуем следующее число
               copyfield.setValue(row, col, 0);
            }
        }
    // Нет решения
    return false;
}

int Solver::countSudokuSolutions() {
    int solutions = 0;
    if(solveSudoku())
    {
        solutions++;
    }
    return solutions;
}
