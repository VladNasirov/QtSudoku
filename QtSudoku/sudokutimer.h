#ifndef SUDOKUTIMER_H
#define SUDOKUTIMER_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QElapsedTimer>
class SudokuTimer : public QWidget
{
    Q_OBJECT
public:
    explicit SudokuTimer(QWidget *parent = nullptr);

signals:
    void startTimer();
    void stopTimer();
public slots:
    void timerStarted();
    void timerStoped();
private:
    //QTimer* timer;
    QElapsedTimer* timer;
    QLabel* lab;
};

#endif // SUDOKUTIMER_H
