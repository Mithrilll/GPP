#include <QtCore/QCoreApplication>
#include <iostream>
#include <QDir>
#include <QStringList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    QDir dir(QString("./"));
    QStringList list = dir.entryList();
    foreach(QString s, list) {
        qDebug() << s;
    }

    return a.exec();
}
