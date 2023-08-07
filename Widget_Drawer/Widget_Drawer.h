#pragma once

#include <QtWidgets/QWidget>
#include "ui_Widget_Drawer.h"

class Widget_Drawer : public QWidget
{
    Q_OBJECT

public:
    Widget_Drawer(QWidget *parent = nullptr);
    ~Widget_Drawer();

private:
    Ui::Widget_DrawerClass ui;
};
