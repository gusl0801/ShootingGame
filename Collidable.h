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
	virtual ~Collidable();

	virtual bool collisionCheck(const Vector2d &position) const = 0;
	virtual bool IsCollide(const Collidable &other) const = 0;
	virtual bool IsInScreen() const = 0;
	Collision_Type getType() const { return m_type; }

protected:	
	Collision_Type m_type;
};