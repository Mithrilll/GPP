#pragma once
#include <qvector.h>
#include "File.h"

class FileMonitor
{
public:
	FileMonitor();
	~FileMonitor();

	void addFile(QString filepath);
	void removeFile(QString filepath);

	bool contains(QString filepath);

private:

	QVector<File> files_to_watch;
};