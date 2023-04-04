#include "FileMonitor.h"

FileMonitor FileMonitor::instance;

FileMonitor::FileMonitor(QObject *parent) : QObject(parent)
{
	thread = new ThreadWorker();
	thread->start();
}

FileMonitor::~FileMonitor()
{
	thread->terminate();
	thread->wait();
	delete thread;
}

void FileMonitor::addFile(QString filepath)
{
	if (contains(filepath))
		return;

	files_to_watch.push_back({filepath});

	emit onUpdate(files_to_watch[files_to_watch.size()-1]);
}

void FileMonitor::removeFile(QString filepath)
{
	for (int i = 0; i < files_to_watch.size(); i++)
	{
		if (files_to_watch[i] == filepath)
		{
			auto file = files_to_watch[i];
			files_to_watch.remove(i);
			break;
		}
	}
}

bool FileMonitor::contains(QString filepath)
{
	bool ans = false;
	for (int i = 0; i < files_to_watch.size(); i++)
	{
		if (files_to_watch[i] == filepath)
		{
			ans = true;
			break;
		}
	}

	return ans;
}

void FileMonitor::update()
{
	for (int i = 0; i < files_to_watch.size(); i++)
	{
		if (files_to_watch[i].update())
		{
			emit onUpdate(files_to_watch[i]);
		}
	}
}

FileMonitor::ThreadWorker::ThreadWorker()
{
}

FileMonitor::ThreadWorker::~ThreadWorker()
{
}

void FileMonitor::ThreadWorker::run()
{
	while (true)
	{
		FileMonitor::get().update();
		sleep(5);
	}
}
