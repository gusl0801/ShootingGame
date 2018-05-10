#include "stdafx.h"
#include "CTraceBullet.h"


CTraceBullet::CTraceBullet(CGameObject *target, const Vector2d &position)
{
	m_target = target;
	m_position = position;
	m_count = 0;
	TraceTarget();
}


CTraceBullet::~CTraceBullet()
{
}

void CTraceBullet::Update()
{
	const int PERIOD = 6;
	++m_count;
	++m_isDelete;
	if (m_count > PERIOD) {
		m_count = 0;
		TraceTarget();
	}
	Move();
}

void CTraceBullet::Draw(HDC hdc)
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

void CTraceBullet::TraceTarget()
{
	m_direction = m_target->GetPosition() - m_position;
	m_direction.Normalize();
}
