#ifndef TILEWIDGET_H
#define TILEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QColor>
#include "Tile.h"
#include <QValidator>
class TileWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TileWidget(Tile til, int corvalue, QWidget *parent = nullptr);
    void setValue(int val);//validator
    void clearValue();
    ~TileWidget();
public slots:
    //TODO slot for value changed textEdit and add validator here
    void checkValue(QString value);
signals:
    void wrongAns(QString val);
private:
    QColor backgroundClr;
    Tile t;
    int correctValue;
    int value;
    QLineEdit* text;
    QValidator* validator;
};

#endif // TILEWIDGET_H
