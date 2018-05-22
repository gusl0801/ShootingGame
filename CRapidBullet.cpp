#include "stdafx.h"
#include "CRapidBullet.h"

CRapidBullet::CRapidBullet(const Vector2d & position)
{
	m_position = position;

	m_direction.x = 0;
	m_direction.y = 1;
	m_direction.Normalize();

	m_endPos.x = position.x;
	m_endPos.y = CLIENT_HEIGHT;

	init();
}

CRapidBullet::CRapidBullet(const Vector2d & position, const Vector2d target)
{
	m_position = position;

	m_direction = target - position;
	m_direction.Normalize();

	m_endPos = target;

	init();
}

CRapidBullet::~CRapidBullet()
{
}

void CRapidBullet::Update()
{
	(this->*((*m_updater.find(m_phase)).second))();
}

void CRapidBullet::Draw(HDC hdc)
{
	(this->*((*m_drawer.find(m_phase)).second))(hdc);
}

void CRapidBullet::updatePhaseWarn()
{
	m_warnCounter.Increase();
	if (m_warnCounter.isLimit())
	{
		m_warnCounter.ResetCount();
		m_phase = PHASE::ATTACK;
	}
}

void CRapidBullet::updatePhaseAttack()
{
	Move();
}

void CRapidBullet::drawPhaseWarn(HDC hdc)
{
	HPEN hPen, oldPen;

	hPen = CreatePen(PS_SOLID, 30, RGB(255, 255, 255));
	oldPen = (HPEN)SelectObject(hdc, hPen);

	MoveToEx(hdc, m_position.x, m_position.y, nullptr);
	LineTo(hdc, m_endPos.x, m_endPos.y);

	SelectObject(hdc, oldPen);
	DeleteObject(hPen);
}

void CRapidBullet::drawPhaseAttack(HDC hdc)
{
	DrawSimple(hdc);
}

void CRapidBullet::init()
{
	m_phase = PHASE::WARN;
	m_warnCounter.SetLimit(CCounter::SecondToFrame(1.0f));

	m_updater.insert(make_pair(PHASE::WARN, &CRapidBullet::updatePhaseWarn));
	m_updater.insert(make_pair(PHASE::ATTACK, &CRapidBullet::updatePhaseAttack));
	
	m_drawer.insert(make_pair(PHASE::WARN, &CRapidBullet::drawPhaseWarn));
	m_drawer.insert(make_pair(PHASE::ATTACK, &CRapidBullet::drawPhaseAttack));
}
