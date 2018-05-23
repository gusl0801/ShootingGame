#pragma once
#include "stdafx.h"

class Collide
{
public:
	Collide() {}
	Collide(int x1, int x2, int y1, int y2) : x1(x1), x2(x2), y1(y1), y2(y2), radius(NULL) {}
	Collide(int x1, int x2, int y1, int y2, int radius) : x1(x1), x2(x2), y1(y1), y2(y2), radius(radius) {}
	~Collide();

	bool IsCollide(Collide bullet);

private:
	int x1, x2;
	int y1, y2;
	int radius;
};