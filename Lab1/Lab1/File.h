#pragma once
#include <qobject.h>
#include <qstring.h>
#include <qlist.h>
#include <qdir.h>

class File : public QObject
{
	Q_OBJECT

public:
	enum class FileState
	{
		NOT_EXIST = 0,
		CREATED,
		EXIST,
		SIZE_CHANGED,
		DELETED
	};

	File() = default;
	File(QString path);
	File(const File& other) noexcept;
	File(File&& other) noexcept;
	~File() = default;

	bool update();
	FileState getState();
	QString getFilePath();

	void operator=(const File& other)noexcept;
	void operator=(File&& other)noexcept;

	bool operator==(const QString& path);

private:
	int size;
	QString filepath;
	FileState current_state;
};


