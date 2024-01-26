#include "tilewidget.h"

TileWidget::TileWidget(Tile til, int corvalue, QWidget *parent)
    : QWidget{parent}
{

    text=new QLineEdit(this);
    validator=new QIntValidator(1,9, this);
    text->setFixedSize(QSize(30, 30));
    correctValue=corvalue;
    t.value=til.value;
    t.row=til.row;
    t.column=til.column;
    qDebug()<<"created";
    this->setVisible(true);
    this->setStyleSheet("background: white");
    text->setStyleSheet("border: 1px solid black");
    text->setAlignment(Qt::AlignCenter);
    text->setValidator(validator);
    text->setText(t.value==0?"":QString::number(t.value));
    if(!(text->text().isEmpty()))
    {
        text->setReadOnly(true);
    }
    QFont f("Courier New",15);
    //connect(text, SIGNAL(textChanged(const QString &value)), this, SLOT(checkValue(const QString &value)));
    connect(text, SIGNAL(textChanged(QString)), this, SLOT(checkValue(QString)));
    //connect(text, SIGNAL(textEdited(QString)), this, SLOT(checkValue(QString)));
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

void TileWidget::checkValue(QString value)
{
    if(text->hasAcceptableInput()||text->text().isEmpty())
    {
        qDebug()<<"Acceptable!";
    }
    else
    {
        qDebug()<<"Not!";
        return;
    }
    qDebug()<<value;
    qDebug()<<value.toInt()<<"and cor="<<correctValue;
    if(!(value.toInt()==correctValue))
    {
        text->setStyleSheet("background: red");
        qDebug()<<"Wrong value at"<<t.row<<" "<<t.column;
        emit wrongAns(value);
    }
    else
    {
        text->setStyleSheet("background: white");
    }
}
