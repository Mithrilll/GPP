#include "Widget_Counter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget_Counter w;
    w.show();
    return a.exec();
}
