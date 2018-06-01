#include "stdafx.h"
#include "CBoundingCircle.h"
#include "CBoundingBox.h"

CBoundingCircle::CBoundingCircle(Vector2d center, double radius)
	:m_center(center), m_radius(radius)
{
	m_type = Collision_Type::Circle;
}


CBoundingCircle::~CBoundingCircle()
{
}

bool CBoundingCircle::IsCollide(const Collidable & other) const
{
	switch (other.getType())
	{
	case Collision_Type::Box:
		return collisionCheck((const CBoundingCircle&)other);
		break;
	case Collision_Type::Circle:
		return collisionCheck((const CBoundingBox&)other);
		break;
	default:
		assert(!"undefined type error");
		return false;
	}
}

bool CBoundingCircle::IsInScreen() const
{
	bool left = (m_center.x + m_radius) > 0;
	bool top = (m_center.y + m_radius) > 0;
	bool right = (m_center.x - m_radius) < CLIENT_WIDTH;
	bool bottom = (m_center.y - m_radius) < CLIENT_HEIGHT;

	return (left && top && right && bottom);
}

bool CBoundingCircle::collisionCheck(const Vector2d & position) const
{
	return m_center.Length(position) <= m_radius;
}

bool CBoundingCircle::collisionCheck(const CBoundingCircle & other) const
{
	return collisionCheck(other.GetCenter());
}

bool CBoundingCircle::collisionCheck(const CBoundingBox & other) const
{
	return false;
}
