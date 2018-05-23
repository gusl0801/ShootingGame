#pragma once
#include "stdafx.h"

class Collision
{
public:
	Collision() {}
	Collision(int x1, int x2, int y1, int y2) : x1(x1), x2(x2), y1(y1), y2(y2), radius(NULL) {}
	Collision(int x1, int x2, int y1, int y2, int radius) : x1(x1), x2(x2), y1(y1), y2(y2), radius(radius) {}
	~Collision();

	bool IsCollide(Collision bullet);

private:
	int x1, x2;
	int y1, y2;
	int radius;
};