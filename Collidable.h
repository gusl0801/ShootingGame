#pragma once
#include "stdafx.h"

enum class Collision_Type : int
{
	None = 0,
	Box = 1,
	Circle = 2,
	Count = 3,
};

// 인터페이스용 클래스로 변경

class Collidable
{
public:
	Collidable() {}
	//Collision(int x1, int x2, int y1, int y2) : x1(x1), x2(x2), y1(y1), y2(y2), radius(NULL) {}
	//Collision(int x1, int x2, int y1, int y2, int radius) : x1(x1), x2(x2), y1(y1), y2(y2), radius(radius) {}
	
	virtual ~Collidable();

	virtual bool IsCollide(const Collidable &other) = 0;

	Collision_Type getType() const { return m_type; }
protected:	
	Collision_Type m_type;
};