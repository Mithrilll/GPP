#pragma once
#include <qvector.h>
#include <qthread.h>
#include "File.h"

class FileMonitor
{
public:
	FileMonitor();
	~FileMonitor();

	void addFile(QString filepath);
	void removeFile(QString filepath);

	bool contains(QString filepath);

	void update();

	void start();

private:
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

	QVector<File> files_to_watch;
	ThreadWorker* thread;
};