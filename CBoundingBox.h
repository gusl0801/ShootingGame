#pragma once
#include "Collidable.h"

class CBoundingCircle;

class CBoundingBox :
	public Collidable
{
public:
	CBoundingBox(const Vector2d & leftTop, const Vector2d & rightBot);
	CBoundingBox(RECT rect);
	CBoundingBox(const Vector2d &center, double radius);
	~CBoundingBox();

	virtual bool IsCollide(const Collidable &other) const override;
	virtual bool IsInScreen() const override;
	virtual bool collisionCheck(const Vector2d &position) const override;
private:
	bool collisionCheck(const CBoundingCircle &other) const;
	bool collisionCheck(const CBoundingBox &other) const;

	Vector2d m_leftTop;
	Vector2d m_rightBot;
};

