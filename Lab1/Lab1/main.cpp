#include <QtCore/QCoreApplication>

#include "FileMonitor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileMonitor inst;

    inst.addFile("Lol");

    return a.exec();
}
