#include "FileMonitor.h"

FileMonitor::FileMonitor()
{
}

FileMonitor::~FileMonitor()
{
}

void FileMonitor::addFile(QString filepath)
{
	QString dir_path;
	QString filename;

	int i = filepath.size() - 1;
	while (filepath[i] != '\\') i--;

	if (i == filepath.size() - 1)
		return;

	dir_path = filepath.left(i);
	filename = filepath.right(filepath.size() - i - 1);

	files_to_watch.push_back({ QDir(dir_path), filename });
}

void FileMonitor::removeFile(QString filepath)
{
	for (int i = 0; i < files_to_watch.size(); i++)
	{
		if (files_to_watch[i] == filepath)
		{
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