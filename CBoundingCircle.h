#pragma once
#include "Collidable.h"

class CBoundingBox;

class CBoundingCircle :
	public Collidable
{
public:
	CBoundingCircle(Vector2d center, double radius);
	~CBoundingCircle();


	Vector2d GetCenter() const { return m_center; }
	double GetRadius() const { return m_radius; }

	virtual bool IsCollide(const Collidable &other) const override;
	virtual bool IsInScreen() const override;
	virtual bool collisionCheck(const Vector2d &position) const override;
private:
	bool collisionCheck(const CBoundingCircle &other) const;
	bool collisionCheck(const CBoundingBox &other) const;

	double m_radius;
	Vector2d m_center;
};



