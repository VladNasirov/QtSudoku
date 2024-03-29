#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    gf=new GameField(this);
    //connect(ui->pushButtonEasy, SIGNAL(clicked()), this, SLOT(toggleTableLayout()));
    connect(this, SIGNAL(fieldCreated()), this, SLOT(createEmptyField()));
    //connect(this, SIGNAL(fieldCreated()), this, SLOT(showField()));

    ui->setupUi(this);
    ui->GameTab->setCurrentIndex(0);
    setCentralWidget(ui->GameTab);
}
void MainWindow::toggleTableLayout() {
     //bool isVisible = ui->SudokuTable->isVisible(); // Проверяем, видим ли макет
    //ui->SudokuTable->setVisible(!isVisible); // Инвертируем видимость макета
}
MainWindow::~MainWindow()
{
    delete gf;
    delete ui;
}


void MainWindow::on_pushButtonEasy_clicked()
{
    gf->setDifficulty(difficulty::Easy);
    gf->start();
    emit fieldCreated();
    //ui->SudokuTable->setRowCount(gf->getNumRows());
    //ui->SudokuTable->setColumnCount(gf->getNumCols());
    //ui->SudokuTable->horizontalHeader()->hide();
   // ui->SudokuTable->verticalHeader()->hide();

    //toggleTableLayout();
    //stackedLayout->setCurrentIndex(1);

}


void MainWindow::on_pushButtonNormal_clicked()
{
    gf->setDifficulty(difficulty::Normal);
    gf->start();
    emit fieldCreated();
    //ui->SudokuTable->show();
}


void MainWindow::on_pushButtonHard_clicked()
{
    gf->setDifficulty(difficulty::Hard);
    gf->start();
    emit fieldCreated();
    //ui->SudokuTable->show();
}


void MainWindow::on_pushButtonExpert_clicked()
{
    gf->setDifficulty(difficulty::Expert);
    gf->start();
    emit fieldCreated();
    //ui->SudokuTable->show();
}

void MainWindow::createEmptyField()
{
    QGridLayout* layout = new QGridLayout(this);
    QVBoxLayout* vlay = new QVBoxLayout(this);
    QFrame* fieldFrame= new QFrame(this);
    vlay->addWidget(fieldFrame);

    fieldFrame->setLayout(layout);
    fieldFrame->setStyleSheet("background-color: rgb(90,90,90)");
    fieldFrame->setFrameShadow(QFrame::Plain);
    vlay->setSpacing(0);
    vlay->setAlignment(Qt::AlignCenter);
    fieldFrame->setFixedSize(340, 340);

    ui->FieldTab->setLayout(vlay);
    vlay->addWidget(fieldFrame);

    //maybe also fill
    gf->printField();
    gf->printCorrectField();
    for(int r=0; r<gf->getNumRows(); r++)
        for(int c=0; c<gf->getNumCols(); c++)
    {

        TileWidget* tile=new TileWidget(gf->getValue(r, c), gf->getCorrectValue(r, c).value,this);
        connect(tile, SIGNAL(wrongAns(QString)), gf, SLOT(wrongAnswer(QString)));
        qDebug()<<"At r="<<r<<" and c="<<c<<" Field val="<<gf->getValue(r, c).value<<"Correct field val"<<gf->getCorrectValue(r, c).value;
        layout->addWidget(tile, r, c);
        tiles.push_back(tile);
    }
    ui->GameTab->setCurrentIndex(1);

}

void MainWindow::showField()
{

}

