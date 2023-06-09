#pragma once
#include <qvector.h>
#include <qthread.h>
#include <functional>
#include <memory>

#include "File.h"

class ThreadWorker;

class FileMonitor : public QObject
{
	Q_OBJECT

public:
	virtual ~FileMonitor();

	static FileMonitor& get() { return instance; }

	void addFile(QString filepath);
	void removeFile(QString filepath);

	bool contains(QString filepath);

	void update();

signals:
	void onUpdate(File files);

private:
	class ThreadWorker : public QThread
	{
	public:
		ThreadWorker();
		~ThreadWorker();

	protected:
		void run() override;
	};

	static FileMonitor instance;

	explicit FileMonitor(QObject *parent = nullptr);

	QVector<File> files_to_watch;
	ThreadWorker* thread;

	friend class ThreadWorker;
};