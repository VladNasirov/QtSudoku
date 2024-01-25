#include "tilewidget.h"

TileWidget::TileWidget(Tile til, QWidget *parent)
    : QWidget{parent}
{
    text=new QLineEdit(this);
    validator=new QIntValidator(1, 9, this);
    text->setFixedSize(QSize(30, 30));
    t=til;
    //text->setAlignment(Qt::AlignCenter);
    //text->setTextBackgroundColor(Qt::gray);
    //text->setFrameStyle(QFrame::Plain);
    //text->setStyleSheet();
    //text->
    value=0;
    //text->setMax
    qDebug()<<"created";
    this->setVisible(true);
    this->setStyleSheet("background: white");
    //text->
    text->setStyleSheet("border: 1px solid black");
    text->setAlignment(Qt::AlignCenter);
    text->setValidator(validator);
    text->setText(t.value==0?" ":QString::number(t.value));

    QFont f("Courier New",15);
    text->setFont(f);
}

void TileWidget::setValue(int val)
{

    value=val;
}

TileWidget::~TileWidget()
{
    qDebug()<<"deleted";
    delete text;
    delete validator;
}
