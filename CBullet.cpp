#include "stdafx.h"
#include "CBullet.h"


CBullet::CBullet()
{
	m_position.x = rand() % CLIENT_WIDTH;

	m_position.y = 50;
	m_direction.x = 0;
	m_direction.y = 1;
	m_direction.Normalize();
}

CBullet::CBullet(const Vector2d &position, const Vector2d &direction)
{
	m_position = position;
	m_direction = direction;
}


CBullet::~CBullet()
{
}

void CBullet::Update()
{
	Move();
}

void CBullet::Draw(HDC hdc)
{
	const int BULLET_SIZE = 5;
	POINT size{ BULLET_SIZE, BULLET_SIZE };
	HBRUSH oldBrush, hBrush;

	hBrush = CreateSolidBrush(RGB(255, 170, 170));
	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	
	Ellipse(hdc, m_position.x - size.x, m_position.y - size.y,
		m_position.x + size.x, m_position.y + size.y);

	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);
}

void CBullet::Rotate(const Vector2d & center, int angle, int radius)
{
	m_position.x = center.x + radius * cos(angle);
	m_position.y = center.y + radius * sin(angle);
}
