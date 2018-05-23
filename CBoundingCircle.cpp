#include "stdafx.h"
#include "CBoundingCircle.h"


CBoundingCircle::CBoundingCircle(Vector2d center, double radius)
	:m_center(center), m_radius(radius)
{
	m_type = Collision_Type::Circle;
}


CBoundingCircle::~CBoundingCircle()
{
}

bool CBoundingCircle::isCollide(const Collidable & other)
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

bool CBoundingCircle::collisionCheck(const CBoundingCircle & other)
{
	return false;
}

bool CBoundingCircle::collisionCheck(const CBoundingBox & other)
{
	return false;
}
