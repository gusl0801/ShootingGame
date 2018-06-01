#include "stdafx.h"
#include "CBoundingBox.h"
#include "CBoundingCircle.h"

CBoundingBox::CBoundingBox(const Vector2d & leftTop, const Vector2d & rightBot)
	:m_leftTop(leftTop), m_rightBot(rightBot)
{
	m_type = Collision_Type::Box;
}

CBoundingBox::CBoundingBox(RECT rect)
{
	m_leftTop.x = rect.left;
	m_leftTop.y = rect.top;
	m_rightBot.x = rect.right;
	m_rightBot.y = rect.bottom;
}

CBoundingBox::CBoundingBox(const Vector2d & center, double radius)
{
	m_leftTop.x = center.x - radius;
	m_leftTop.y = center.y - radius;
	m_rightBot.x = center.x + radius;
	m_rightBot.y = center.y + radius;
}


CBoundingBox::~CBoundingBox()
{
}

bool CBoundingBox::IsCollide(const Collidable &other) const
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

bool CBoundingBox::IsInScreen() const
{
	bool left = (m_leftTop.x > 0);
	bool top = (m_leftTop.y > 0);
	bool right = (m_rightBot.x < CLIENT_WIDTH);
	bool bottom = (m_rightBot.y < CLIENT_HEIGHT);
	
	return (left && top && right && bottom);
}

bool CBoundingBox::collisionCheck(const Vector2d & position) const
{
	if (m_leftTop.x > position.x)
		return false;
	if (m_rightBot.x < position.x)
		return false;
	if (m_leftTop.y > position.y)
		return false;
	if (m_rightBot.y < position.y)
		return false;
	return true;
}

bool CBoundingBox::collisionCheck(const CBoundingCircle & other) const
{
	double radius = other.GetRadius();
	Vector2d center = other.GetCenter();

	if (center.Length(m_leftTop) > radius)
		return false;
	if (center.Length(m_rightBot) > radius)
		return false;
	if (center.Length({ m_rightBot.x, m_leftTop.y }) > radius)
		return false;
	if (center.Length({ m_leftTop.x, m_rightBot.y }) > radius)
		return false;

	CBoundingBox extendedBox( center, radius );

	if (extendedBox.collisionCheck(center))
		return true;

	return false;
}

bool CBoundingBox::collisionCheck(const CBoundingBox & other) const
{
	// left
	if (this->m_rightBot.x < other.m_leftTop.x)
		return false;
	// right
	if (this->m_leftTop.x > other.m_rightBot.x)
		return false;
	// top
	if (this->m_rightBot.y < other.m_leftTop.y)
		return false;
	// bottom
	if (this->m_leftTop.y > other.m_rightBot.y)
		return false;
	return true;
}
