#include "File.h"

File::File(QDir dir, QString name)
{
	directory = dir;
	filename = name;
	QFileInfo info = {directory, filename};
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
	directory = other.directory;
	filename = other.filename;
	size = other.size;
	current_state = other.current_state;
}

File::File(File&& other) noexcept
{
	directory = other.directory;
	filename = other.filename;
	size = other.size;
	current_state = other.current_state;
}

void File::update()
{
	QFileInfo info = { directory, filename };

	if (info.exists())
	{
		int current_size = info.size();
		switch (current_state)
		{
		case FileState::NOT_EXIST:
			current_state = FileState::CREATED;
			size = current_size;
			break;
		case FileState::EXIST:
			if (size != current_size)
			{
				current_state = FileState::SIZE_CHANGED;
				size = current_size;
			}
			break;
		case FileState::CREATED:
		case FileState::SIZE_CHANGED:
			if (size == current_size)
			{
				current_state = FileState::EXIST;
			}
			else
			{
				current_state = FileState::SIZE_CHANGED;
				size = current_size;
			}
			break;
		case FileState::DELETED:
			current_state = FileState::CREATED;
			size = current_size;
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
		case FileState::DELETED:
			current_state = FileState::DELETED;
			size = 0;
			break;
		default:
			break;
		}
	}
}

File::FileState File::getState()
{
	return current_state;
}

void File::operator=(const File& other)
{
	if (this == &other)
		return;

	directory = other.directory;
	filename = other.filename;
	size = other.size;
	current_state = other.current_state;
}

void File::operator=(File&& other)
{
	if (this == &other)
		return;

	directory = other.directory;
	filename = other.filename;
	size = other.size;
	current_state = other.current_state;
}

bool File::operator==(const QString& filepath)
{
	return (directory.absolutePath() + filename) == filepath;
}
