#include "gamefield.h"
#include <iostream>
#include <QDebug>
#include <QRandomGenerator>
GameField::GameField(QObject *parent)
    : QObject{parent}
{
    sudokuPower=3;
    maxWrongCounter=3;
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
    funcVec.push_back(&GameField::swapRowsSmall);//
    funcVec.push_back(&GameField::swapColsSmall);//weird
}

int GameField::getSudokuPower()
{
    return sudokuPower;
}

void GameField::setSudokuPower(int pow)
{
    sudokuPower=pow;
}

int GameField::getNumRows()
{
    return numRows;
}

void GameField::setNumRows(int r)
{
    numRows=r;
}

int GameField::getNumCols()
{
    return numCols;
}

Tile GameField::getValue(int r, int c)
{
    return field[r][c];
}

Tile GameField::getCorrectValue(int r, int c)
{
    return correctAnswer[r][c];
}

void GameField::setNumCols(int c)
{
    numCols=c;
}

void GameField::setValue(int r, int c, int num)
{
    field[r][c].value=num;
}

void GameField::setDifficulty(difficulty d)
{
    dif=d;
}

QVector<QVector<Tile> > GameField::getField()
{
    return field;
}
QVector<QVector<Tile>> GameField::getCorrectField()
{
    return correctAnswer;
}
void GameField::setField(QVector<QVector<Tile>> f)
{
    field=f;
}

GameField::GameField(const GameField &gf)
{
//    this->setField(gf.getField());
//    this->setNumCols(gf.getNumCols());
//    this->setNumRows(gf.getNumRows());
//    this->setSudokuPower(gf.getSudokuPower());
    field=gf.field;
    numCols=gf.numCols;
    numRows=gf.numRows;
    sudokuPower=gf.sudokuPower;
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

//void GameField::generateSudoku()
//{
//    shuffleField();
//    correctAnswer=field;
//}


void GameField::transpose()
{
    qInfo()<<Q_FUNC_INFO;
    //printField();
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
     //printField();
    int Area = QRandomGenerator::global()->bounded(0, sudokuPower);
    int randomR1 = QRandomGenerator::global()->bounded(Area*sudokuPower, Area*sudokuPower+sudokuPower);
    int randomR2;
    do
    {
        randomR2 = QRandomGenerator::global()->bounded(Area*sudokuPower, Area*sudokuPower+sudokuPower);
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
    // printField();
    int Area = QRandomGenerator::global()->bounded(0, sudokuPower);
    int randomR1 = QRandomGenerator::global()->bounded(Area*sudokuPower, Area*sudokuPower+sudokuPower);
    int randomR2;
    do
    {
        randomR2 = QRandomGenerator::global()->bounded(Area*sudokuPower, Area*sudokuPower+sudokuPower);
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
     //printField();
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
    //printField();
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

bool GameField::checkRow(int r)
{
    QVector<int> tmp_r;
    for(int c=0; c<numCols; c++)
    {
        tmp_r.push_back(field[r][c].value);
    }
    for (int num : tmp_r) {
        if (num == 0) {
            continue;
        }
        if (tmp_r.count(num) > 1) {
            return false; // Найдено совпадающее число, кроме целевого
        }
    }
    return true;
}

bool GameField::checkColumn(int c)
{
    QVector<int> tmp_c;
    for(int r=0; r<numRows; r++)
    {
        tmp_c.push_back(field[r][c].value);
    }

    for (int num : tmp_c) {
        if (num == 0) {
            continue;
        }
        if (tmp_c.count(num) > 1) {
            return false; // Найдено совпадающее число, кроме целевого
        }
    }
    return true;
}

bool GameField::checkBox(int bn)
{
    QVector<int> box;
    int bc=bn%sudokuPower*sudokuPower;
    int br=bn/sudokuPower*sudokuPower;
    int bcMax=bc+sudokuPower;
    int brMax=br+sudokuPower;
    //qInfo()<<"bc= "<<bc<<", br= "<<br<<", bcMax= "<<bcMax<<", brMax= "<<brMax;
    for(int r=br; r<brMax; r++)
    {
        for(int c=bc; c<bcMax; c++)
        {
            box.push_back(field[r][c].value);
        }
    }
//    std::cout<<"Box№ "<<bn<<std::endl;
//    for (int num : box)
//    {
//        std::cout<<num<<" ";
//    }
//     std::cout<<std::endl;
    for (int num : box) {
        if (num == 0) {
            continue;
        }
        if (box.count(num) > 1) {
            return false; // Найдено совпадающее число, кроме целевого
        }
    }
    return true;

}

bool GameField::checkRows()
{
    for(int r=0; r<numRows; r++)
    {
        if(!checkRow(r))
        {
            return false;
        }
    }
    return true;
}

bool GameField::checkColumns()
{
    for(int c=0; c<numCols; c++)
    {
        if(!checkColumn(c))
        {
            return false;
        }
    }
    return true;
}

bool GameField::checkBoxes()
{
    for(int b=0; b<sudokuPower*sudokuPower; b++)
    {
        if(!checkBox(b))
        {
            return false;
        }

    }
    return true;
}

void GameField::generateBaseField()
{
    int num=1;
     QVector<int> tmp;
    tmp.resize(numRows);
     for(int i=0; i<tmp.size(); i++)
    {
        tmp[i]=num;
        num++;
    }
    num=1;
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
            field[r][c].value=num;
            num++;
        }
        num=1;
    }
    for(int i=1; i<numRows; i++)
    {
        shiftRow(i, sudokuPower*i);
        if(i>sudokuPower-1)
        {

            int tmpshift=i/sudokuPower;
            shiftRow(i, tmpshift);
        }
    }
}

void GameField::shiftRow(int row, int shift)
{
    shift = shift % numCols; // Убедимся, что сдвиг находится в пределах размера строки
    QVector<Tile> tempRow = field[row];
    for (int i = 0; i < numCols; ++i) {
        int newIndex = (i + numCols - shift) % numCols;
        field[row][newIndex] = tempRow[i];
    }
}

void GameField::setRightAnswer()
{
    correctAnswer=field;
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

void GameField::printCorrectField()
{
    for (int r=0; r<numRows; r++)
    {
        for (int c=0; c<numCols; c++)
        {
            correctAnswer[r][c].row=r;
            correctAnswer[r][c].column=c;
            std::cout<<"["<<correctAnswer[r][c].row<<correctAnswer[r][c].column<<"]"<<"="<<correctAnswer[r][c].value<<" ";
        }
        std::cout<<std::endl;
    }
}

void GameField::hideField()//добавить в зависимости от размера судоку
{

    if(dif==difficulty::Easy)//10...20
    {
        int lowerBound = QRandomGenerator::global()->bounded(10, 21);
        hideTiles(lowerBound);
    }
    else if(dif==difficulty::Normal)//21...35
    {
        int lowerBound = QRandomGenerator::global()->bounded(21, 36);
        hideTiles(lowerBound);
    }
    else if(dif==difficulty::Hard)//36...50
    {
        int lowerBound = QRandomGenerator::global()->bounded(36, 51);
        hideTiles(lowerBound);
    }
    else if(dif==difficulty::Expert)//51...64 //min 17
    {
        int lowerBound = QRandomGenerator::global()->bounded(51, 65);
        hideTiles(lowerBound);
    }
}

void GameField::hideTiles(int hidenumber)
{
    while(hidenumber>0)
    {
    int r = QRandomGenerator::global()->bounded(0, 9);
    int c = QRandomGenerator::global()->bounded(0, 9);
    if(field[r][c].value!=0)
    {
        field[r][c].value=0;
        hidenumber--;
    }
    }
}

void GameField::start()
{
    shuffleField();
    setRightAnswer();
    if(checkField())
    {
        hideField();
    }
    else
    {
        qDebug()<<"Problem with the field!!";
    }

}

void GameField::wrongAnswer(QString val)
{
    if(val.isEmpty())
    {
        qDebug()<<"SLOT recieved "<<val;
        return;
    }
    else
    {

        //qDebug()<<maxWrongCounter;
        maxWrongCounter--;
         qDebug()<<"SLOT recieved "<<val<<" wrong counter="<<maxWrongCounter;
        if(maxWrongCounter<=0)
        {
            emit gameOver();
            return;
        }
    }
}
bool GameField::checkField()
{
    if(checkBoxes())
    {
        if(checkRows())
        {
            if(checkColumns())
            {
                std::cout<<"Everything is alright!"<<std::endl;
                return true;
            }
            else
            {
                std::cout<<"Collumns are wrong!"<<std::endl;
            }
        }
        else
        {
             std::cout<<"Rows are wrong!"<<std::endl;
        }
    }
    else
    {
        std::cout<<"Boxes are wrong!"<<std::endl;
    }
    return false;
}

