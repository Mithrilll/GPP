#pragma once
#include <qvector.h>
#include <qthread.h>
#include <functional>

#include "File.h"

class ThreadWorker;

class FileMonitor : public QObject
{
	Q_OBJECT

public:
	FileMonitor();
	~FileMonitor();

	void addFile(QString filepath);
	void removeFile(QString filepath);

	bool contains(QString filepath);

	void update();

	void addUpdateCallback(std::function<void(QVector<File>)> callback);

signals:
	void onUpdate(QVector<File> files);

private:

	QVector<File> files_to_watch;
	ThreadWorker* thread;
};

class ThreadWorker : public QThread
{
public:
	ThreadWorker(FileMonitor* instance);
	~ThreadWorker();

protected:
	void run() override;

private:
	FileMonitor* monitor;
};