#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include "Area.h"

class Widget_Drawer : public QWidget
{
    Q_OBJECT

public:
    Widget_Drawer(QWidget *parent = nullptr);
    ~Widget_Drawer();

protected:
    QTextCodec* codec;
    Area* area;
    QPushButton* btn;
};
