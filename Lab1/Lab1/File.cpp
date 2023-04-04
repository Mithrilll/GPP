#include "File.h"

File::File(QString path)
{
	filepath = path;
	QFileInfo info = { filepath };
	if (info.exists())
	{
		size = info.size();
		current_state = FileState::EXIST;
	}
	else
	{
		size = 0;
		current_state = FileState::NOT_EXIST;
	}
}

File::File(const File& other) noexcept
{
	filepath = other.filepath;
	size = other.size;
	current_state = other.current_state;
}

File::File(File&& other) noexcept
{
	filepath = other.filepath;
	size = other.size;
	current_state = other.current_state;
}

bool File::update()
{
	QFileInfo info = { filepath };

	bool stateChanged = false;

	if (info.exists())
	{
		int current_size = info.size();
		switch (current_state)
		{
		case FileState::NOT_EXIST:
		case FileState::DELETED:
			current_state = FileState::CREATED;
			size = current_size;
			stateChanged = true;
			break;
		case FileState::EXIST:
		case FileState::CREATED:
		case FileState::SIZE_CHANGED:
			if (size != current_size)
			{
				current_state = FileState::SIZE_CHANGED;
				size = current_size;
				stateChanged = true;
			}
			break;
		default:
			break;
		}
	}
	else
	{
		switch (current_state)
		{
		case FileState::NOT_EXIST:
			break;
		case FileState::EXIST:
		case FileState::CREATED:
		case FileState::SIZE_CHANGED:
			current_state = FileState::DELETED;
			size = 0;
			stateChanged = true;
			break;
		case FileState::DELETED:
			break;
		default:
			break;
		}
	}

	return stateChanged;
}

File::FileState File::getState()
{
	return current_state;
}

QString File::getFilePath()
{
	return filepath;
}

void File::operator=(const File& other)noexcept
{
	if (this == &other)
		return;

	filepath = other.filepath;
	size = other.size;
	current_state = other.current_state;
}

void File::operator=(File&& other)noexcept
{
	if (this == &other)
		return;

	filepath = other.filepath;
	size = other.size;
	current_state = other.current_state;
}

bool File::operator==(const QString& path)
{
	return  path == filepath;
}
