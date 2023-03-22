#pragma once
#include <qvector.h>

#include "File.h"

class Display : public QObject
{
	Q_OBJECT

public:
	Display();
	~Display();

public slots:
	void update(QVector<File> files);
};