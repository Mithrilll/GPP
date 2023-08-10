#include "Widget_Square.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget_Square w;
    w.show();
    return a.exec();
}
