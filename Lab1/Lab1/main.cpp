#include <QtCore/QCoreApplication>

#include "FileMonitor.h"
#include "Display.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileMonitor monitor;
    Display display;

    monitor.addFile("D:/Test/Folder1/file.txt");
    monitor.addFile("D:/Test/FolderWithBigName/file1.txt");
    monitor.addFile("D:/Test/FolderWithBigName1/filefile.txt");

    monitor.addUpdateCallback([&display](QVector<File> files) -> void {display.update(files); });

    return a.exec();
}
