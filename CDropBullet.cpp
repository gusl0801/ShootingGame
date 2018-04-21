#include "stdafx.h"
#include "CDropBullet.h"

const double CDropBullet::DROP_SPEED = 0.5f;

CDropBullet::CDropBullet(const Vector2d &position, const Vector2d &speed)
{
	m_position = position;
	m_direction = speed;
}


CDropBullet::~CDropBullet()
{
}

void CDropBullet::Update()
{
	Move();

	m_direction.y += DROP_SPEED;
}

void CDropBullet::Draw(HDC hdc)
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
