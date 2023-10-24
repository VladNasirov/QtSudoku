#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    connect(ui->pushButtonEasy, SIGNAL(clicked()), this, SLOT(toggleTableLayout()));
    ui->setupUi(this);

    centralWidget= new QWidget;
    setCentralWidget(centralWidget);

    TabletWidget=new QWidget;
    QVBoxLayout* TableLayout=new QVBoxLayout;
    TableLayout->addWidget(ui->SudokuTable);
    TabletWidget->setLayout(TableLayout);


    DifficultyWidget=new QWidget;
    QVBoxLayout* DifficultyLayout=new QVBoxLayout;
    DifficultyLayout->addWidget(ui->pushButtonEasy);
    DifficultyLayout->addWidget(ui->pushButtonNormal);
    DifficultyLayout->addWidget(ui->pushButtonHard);
    DifficultyLayout->addWidget(ui->pushButtonExpert);
    DifficultyWidget->setLayout(DifficultyLayout);

    stackedLayout=new QStackedLayout;
    stackedLayout->addWidget(DifficultyWidget);
    stackedLayout->addWidget(TabletWidget);
    ui->SudokuTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->SudokuTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->SudokuTable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->SudokuTable->setVisible(false);
    ui->SudokuTable->setFixedSize(QSize(700, 700));
    centralWidget->setLayout(stackedLayout);
        stackedLayout->setCurrentIndex(0);
}
void MainWindow::toggleTableLayout() {
     bool isVisible = ui->SudokuTable->isVisible(); // Проверяем, видим ли макет
     ui->SudokuTable->setVisible(!isVisible); // Инвертируем видимость макета
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonEasy_clicked()
{
    gf.setDifficulty(difficulty::Easy);
    gf.start();
    ui->SudokuTable->setRowCount(gf.getNumRows());
    ui->SudokuTable->setColumnCount(gf.getNumCols());
    ui->SudokuTable->horizontalHeader()->hide();
    ui->SudokuTable->verticalHeader()->hide();

    toggleTableLayout();
    stackedLayout->setCurrentIndex(1);

}


void MainWindow::on_pushButtonNormal_clicked()
{
    gf.setDifficulty(difficulty::Normal);
    ui->SudokuTable->show();
}


void MainWindow::on_pushButtonHard_clicked()
{
    gf.setDifficulty(difficulty::Hard);
    ui->SudokuTable->show();
}


void MainWindow::on_pushButtonExpert_clicked()
{
    gf.setDifficulty(difficulty::Expert);
    ui->SudokuTable->show();
}

