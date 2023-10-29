#include "Figura.h"
#include <cmath>

Figura::Figura(int X, int Y, int Halflen) :
	x(X), y(Y), halflen(Halflen) {}

void Figura::move(float Alpha, QPainter* Painter)
{
	dx = halflen * cos(Alpha);
	dy = halflen * sin(Alpha);
	draw(Painter);
}

MyLine::MyLine(int x, int y, int halflen) :
	Figura(x, y, halflen) {}

void MyLine::draw(QPainter* Painter)
{
	Painter->drawLine(x + dx, y + dy, x - dx, y - dy);
}

MyRect::MyRect(int x, int y, int halflen) :
	Figura(x, y, halflen) {}

void MyRect::draw(QPainter* Painter)
{
	Painter->drawLine(x + dx, y + dy, x + dy, y - dx);
	Painter->drawLine(x + dy, y - dx, x - dx, y - dy);
	Painter->drawLine(x - dx, y - dy, x - dy, y + dx);
	Painter->drawLine(x - dy, y + dx, x + dx, y + dy);
}
