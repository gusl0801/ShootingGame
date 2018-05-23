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
	DrawSimple(hdc);
}
