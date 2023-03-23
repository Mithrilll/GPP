#pragma once
#include <qvector.h>

#include "File.h"

class Display : public QObject
{
	Q_OBJECT

public:
	virtual ~Display();

	static Display& get() { return instance; }

public slots:
	void update(QVector<File> files);

private:
	static Display instance;

	explicit Display(QObject *parent = nullptr);
};