#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonEasy_clicked()
{
    gf.setDifficulty(difficulty::Easy);
}


void MainWindow::on_pushButtonNormal_clicked()
{
    gf.setDifficulty(difficulty::Normal);
}


void MainWindow::on_pushButtonHard_clicked()
{
    gf.setDifficulty(difficulty::Hard);
}


void MainWindow::on_pushButtonExpert_clicked()
{
    gf.setDifficulty(difficulty::Expert);
}

