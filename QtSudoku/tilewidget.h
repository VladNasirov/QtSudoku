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
    explicit TileWidget(Tile til, QWidget *parent = nullptr);
    void setValue(int val);//validator
    void clearValue();
    ~TileWidget();
public slots:
    //TODO slot for value changed textEdit and add validator here
signals:

private:
    QColor backgroundClr;
    Tile t;
    int value;
    QLineEdit* text;
    QValidator* validator;
};

#endif // TILEWIDGET_H
