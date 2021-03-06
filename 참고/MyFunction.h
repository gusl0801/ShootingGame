#pragma once

#include <windows.h>
#include <math.h>

enum WindowsFrameCollision
{
	COLLISION_NON,
	COLLISION_X,
	COLLISION_Y
};


class Click_2D
{

  public:
 
	static bool contains(RECT a, float x, float y)
	{
		return a.left < a.right && a.top < a.bottom
			&& x >= a.left && x < a.right && y >= a.top && y < a.bottom;
	}

	static bool contain(RECT a, RECT b)
{
	return a.left < a.right && a.top < a.bottom
		&& a.left <= b.left && a.top <= b.top && a.right >= b.right && a.bottom >= b.bottom;
}


};

class BoundingBox_2D
{

public:
	float			left;
	float			right;
	float			top;
	float			bot;

	float			cx;
	float			cy;
	float			w;
	float			h;

public:

	void SetBoxLTRD(float _left, float _right, float _top, float _bot)
	{
		left = _left; right = _right, top = _top; bot = _bot;
		w = right - left;
		h = bot = top;
		cx = left + (left + right)/ 2;
		cy = top + (top + bot) / 2;
	}

	void SetBoxCenter(float cx, float cy, float _w, float _h)
	{
		w = _w;
		h = _h;
		BoundingBox_2D::cx = cx;
		BoundingBox_2D::cy = cy;
		left = cx - w / 2;
		right = cx + w / 2;
		top = cy - h / 2;
		bot = cy + h / 2;
	}

	bool Collision(BoundingBox_2D col)
	{
		if (left > col.right)return false;
		if (right < col.left)return false;
		if (top > col.bot)return false;
		if (bot < col.top)return false;
		return true;
	}

	bool Contains(float x, float y)
	{
		return left < right && top < bot
			&& x >= left && x < right && y >= top && y < bot;
	}


	WindowsFrameCollision WidownsBoxCollision(int WidndowsWidth, int WindowsHeight)
	{
		if (left < 0.0f || right > WidndowsWidth)
			return COLLISION_X;
		if (top < 0.0f || bot > WindowsHeight)
			return COLLISION_Y;

		return COLLISION_NON;
	}

	void Update(int cx, int cy)
	{
		left  = cx - w / 2;
		right = cx + w / 2;
		top   = cy - h / 2;
		bot   = cy + h / 2;
		BoundingBox_2D::cx = cx;
		BoundingBox_2D::cy = cy;
	}

};

