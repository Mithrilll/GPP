#include "Widget_Drawer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget_Drawer w;
    w.show();
    return a.exec();
}
