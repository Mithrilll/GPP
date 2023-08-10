#pragma once
#include <QtWidgets/QWidget>
#include "Figura.h"

class Area : public QWidget
{
public:
	Area(QWidget* parent = 0);
	~Area();

	MyLine* myline;
	MyRect* myrect;

protected:
	// обработчики событий
	void paintEvent(QPaintEvent* event);
	void timerEvent(QTimerEvent* event);
	void showEvent(QShowEvent* event);
	void hideEvent(QHideEvent* event);

private:
	int myTimer; // идентификатор таймера
	float alpha; // угол поворота
};