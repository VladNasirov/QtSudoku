#include "solver.h"

Solver::Solver(QObject *parent, QSharedPointer<GameField> gf)
    : QObject{parent}
{
    copyfield=gf;
}
bool Solver::findEmptyCell(int& row, int& col)//переписать
{
    for(int i=0; i<copyfield->getNumRows(); i++)
    {
        for(int j=0; j<copyfield->getNumCols(); j++)
        {
            if(copyfield->getField()[i][j].value==0)
            {
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}
bool Solver::isValidMove(int row, int col, int num) {
    // Проверьте, что num не нарушает правила судоку для строки, столбца и малого квадрата 3x3
    // ...
    GameField tmp;
    tmp.setField(copyfield->getField());
    tmp.setValue(row, col, num);
    if(tmp.checkBoxes())
    {
        if(tmp.checkRows())
        {
            if(tmp.checkColumns())
            {
                copyfield->getField()[row][col].value=num;
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
                copyfield->getField()[row][col].value = num;

                // Рекурсивно продолжаем заполнять оставшиеся клетки
                if (solveSudoku()) {
                    return true;
                }

                // Если не получилось, отменяем изменение и пробуем следующее число
                copyfield->getField()[row][col].value = 0;
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
