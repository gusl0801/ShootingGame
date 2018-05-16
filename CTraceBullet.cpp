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
	DrawSimple(hdc);
}

void CTraceBullet::TraceTarget()
{
	m_direction = m_target->GetPosition() - m_position;
	m_direction.Normalize();
}
