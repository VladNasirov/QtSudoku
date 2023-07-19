#include "solver.h"

Solver::Solver(QObject *parent)
    : QObject{parent}
{

}
bool Solver::findEmptyCell()
{

}
bool Solver::isValidMove(const QVector<QVector<Tile>>& sudoku, int row, int col, Tile num) {
    // Проверьте, что num не нарушает правила судоку для строки, столбца и малого квадрата 3x3
    // ...
}

bool Solver::solveSudoku(QVector<QVector<Tile>>& sudoku) {
    int row, col;
    if (!findEmptyCell(sudoku, row, col)) {
        // Найдено решение, если нет пустых клеток
        return true;
    }

    for (Tile num = 1; num <= 9; ++num) {
        if (isValidMove(sudoku, row, col, num)) {
            // Присваиваем num в текущую пустую клетку
            sudoku[row][col] = num;

            // Рекурсивно продолжаем заполнять оставшиеся клетки
            if (solveSudoku(sudoku)) {
                return true;
            }

            // Если не получилось, отменяем изменение и пробуем следующее число
            sudoku[row][col] = 0;
        }
    }

    // Нет решения
    return false;
}

int Solver::countSudokuSolutions(QVector<QVector<Tile>> sudoku) {
    int solutions = 0;
    solveSudoku(sudoku, solutions);
    return solutions;
}
