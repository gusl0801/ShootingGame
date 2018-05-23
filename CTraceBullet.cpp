#include "stdafx.h"
#include "CTraceBullet.h"


CTraceBullet::CTraceBullet(CGameObject *target, const Vector2d &position)
{
	m_target = target;
	m_position = position;
	m_traceCounter.SetLimit(CCounter::SecondToFrame(0.2f));
	m_deleteCounter.SetLimit(CCounter::SecondToFrame(2.0f));
	TraceTarget();
}


CTraceBullet::~CTraceBullet()
{
}

void CTraceBullet::Update()
{
	const int PERIOD = 6;
	m_traceCounter.Increase();
	m_deleteCounter.Increase();

	if (m_traceCounter.isLimit()) {
		m_traceCounter.ResetCount();
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
