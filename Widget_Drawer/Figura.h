#pragma once

#include <QPainter>

class Figura
{
public:
	Figura(int X, int Y, int Halflen);

	void move(float Alpha, QPainter* Painter);

protected:
	int x, y, halflen, dx, dy, r;

	virtual void draw(QPainter* Painter) = 0;
};

class MyLine :public Figura
{
public:
	MyLine(int x, int y, int halflen);

protected:
	void draw(QPainter* Painter) override;
};

class MyRect :public Figura
{

public:
	MyRect(int x, int y, int halflen);

protected:
	void draw(QPainter* Painter) override;
};