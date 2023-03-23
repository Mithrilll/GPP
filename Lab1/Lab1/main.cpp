#include <QtCore/QCoreApplication>

#include "FileMonitor.h"
#include "Display.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileMonitor::get().addFile("D:/Test/Folder1/file.txt");
    FileMonitor::get().addFile("D:/Test/FolderWithBigName/file1.txt");
    FileMonitor::get().addFile("D:/Test/FolderWithBigName1/filefile.txt");

    FileMonitor::get().addUpdateCallback([](QVector<File> files) -> void {Display::get().update(files); });

    return a.exec();
}
