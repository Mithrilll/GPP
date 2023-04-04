#pragma once
#include <qvector.h>
#include <qsharedpointer.h>

#include "File.h"

class Display : public QObject
{
	Q_OBJECT

public:
	virtual ~Display();

	static Display& get() { return instance; }

public slots:
	void show(File file);

private:
	static Display instance;

	explicit Display(QObject *parent = nullptr);
};