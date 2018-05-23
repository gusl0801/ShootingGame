#include "stdafx.h"
#include "CBoundingBox.h"
#include "CBoundingCircle.h"

CBoundingBox::CBoundingBox(Vector2d leftTop, Vector2d rightBot)
	:m_leftTop(leftTop), m_rightBot(rightBot)
{
	m_type = Collision_Type::Box;
}


CBoundingBox::~CBoundingBox()
{
}

bool CBoundingBox::isCollide(const Collidable &other)
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

bool CBoundingBox::collisionCheck(const CBoundingCircle & other)
{
	return false;
}

bool CBoundingBox::collisionCheck(const CBoundingBox & other)
{
	return false;
}
