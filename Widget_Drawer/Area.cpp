#include <qcoreevent.h>

#include "Area.h"

Area::Area(QWidget* parent) :
	QWidget(parent)
{
	setFixedSize(QSize(300, 200));
	myline = new MyLine(80, 100, 50);
	myrect = new MyRect(220, 100, 50);
	alpha = 0;
}

Area::~Area()
{
	delete myline;
	delete myrect;
}

void Area::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setPen(Qt::red);
	myline->move(alpha, &painter);
	myrect->move(alpha * (-0.5), &painter);
}

void Area::timerEvent(QTimerEvent* event)
{
	if (event->timerId() == myTimer) // если наш таймер
	{
		alpha = alpha + 0.2;
		update(); // обновить внешний вид
	}
	else
		QWidget::timerEvent(event);
}

void Area::showEvent(QShowEvent* event)
{
	myTimer = startTimer(50);
}

void Area::hideEvent(QHideEvent* event)
{
	killTimer(myTimer);
}
