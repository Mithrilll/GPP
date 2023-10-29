#include <QTextCodec>
#include <QtWidgets/QVBoxLayout>
#include "Widget_Drawer.h"

Widget_Drawer::Widget_Drawer(QWidget *parent)
    : QWidget(parent)
{
    codec = QTextCodec::codecForName("Windows-1251");
    this->setWindowTitle(codec->toUnicode("Event serve"));
    area = new Area(this);
    btn = new QPushButton(codec->toUnicode("Quit"), this);
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(area);
    layout->addWidget(btn);

    connect(btn, SIGNAL(clicked(bool)), this, SLOT(close()));
}

Widget_Drawer::~Widget_Drawer()
{}
