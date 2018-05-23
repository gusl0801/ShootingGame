#pragma once
#include "Collidable.h"

class CBoundingBox;

class CBoundingCircle :
	public Collidable
{
public:
	CBoundingCircle(Vector2d center, double radius);
	~CBoundingCircle();

	virtual bool isCollide(const Collidable &other);

private:
	bool collisionCheck(const CBoundingCircle &other);
	bool collisionCheck(const CBoundingBox &other);

	double m_radius;
	Vector2d m_center;
};



