#include "stdafx.h"
#include "CBullet.h"


CBullet::CBullet()
{
	m_position.x = rand() % CLIENT_WIDTH;

	m_position.y = 50;
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
