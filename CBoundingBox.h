#pragma once
#include "Collidable.h"

class CBoundingCircle;

class CBoundingBox :
	public Collidable
{
public:
	CBoundingBox(Vector2d leftTop, Vector2d rightBot);
	~CBoundingBox();

	virtual bool isCollide(const Collidable &other);
	
private:
	bool collisionCheck(const CBoundingCircle &other);
	bool collisionCheck(const CBoundingBox &other);

	Vector2d m_leftTop;
	Vector2d m_rightBot;
};

