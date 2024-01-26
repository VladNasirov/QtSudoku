#include "sudokutimer.h"

SudokuTimer::SudokuTimer(QWidget *parent)
    : QWidget{parent}
{
    lab=new QLabel(this);
    timer=new QElapsedTimer(this);
}

void SudokuTimer::timerStarted()
{
    timer->start();
}

void SudokuTimer::timerStoped()
{
    //timer->stop();
}
