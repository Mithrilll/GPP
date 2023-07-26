#include <QtCore/QCoreApplication>

#include "FileMonitor.h"
#include "Display.h"

Q_DECLARE_METATYPE_IMPL(File);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qRegisterMetaType<File>();

    QObject::connect(&FileMonitor::get(), &FileMonitor::onUpdate, &Display::get(), &Display::show, Qt::QueuedConnection);

    FileMonitor::get().addFile("D:/Test/Folder1/file.txt");
    FileMonitor::get().addFile("D:/Test/FolderWithBigName/file1.txt");
    FileMonitor::get().addFile("D:/Test/FolderWithBigName1/filefile.txt");

    return a.exec();
}
