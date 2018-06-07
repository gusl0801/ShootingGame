#include "stdafx.h"
#include "CTraceEnemy.h"

#include "CBoundingBox.h"
#include "CNWayBullet.h"

CTraceEnemy::CTraceEnemy()
{
	m_position.x = rand() % CLIENT_WIDTH;
	m_position.y = 20;

	Vector2d leftTop = m_position;
	Vector2d rightBot = { m_position.x + m_width, m_position.y + m_height };

	m_boundary = new CBoundingBox(leftTop, rightBot);

	m_image.Load(TEXT("resource/characters/enemy_1.png"));

	m_traceCounter.SetLimit(CCounter::SecondToFrame(0.0f));
	attackCounter.SetLimit(CCounter::SecondToFrame(0.5));
	spriteCounter.SetLimit(CCounter::SecondToFrame(0.5));

	m_direction = { 0, 1 };
}

CTraceEnemy::CTraceEnemy(CGameObject *target)
{
	m_target = target;
	m_position = target->GetPosition();
	m_position.y = 20;

	Vector2d leftTop = m_position;
	Vector2d rightBot = { m_position.x + m_width, m_position.y + m_height };

	m_boundary = new CBoundingBox(leftTop, rightBot);

	m_image.Load(TEXT("resource/characters/enemy_1.png"));

	attackCounter.SetLimit(CCounter::SecondToFrame(0.5));
	spriteCounter.SetLimit(CCounter::SecondToFrame(0.5));

	m_direction = { 0, 1 };
}

CTraceEnemy::~CTraceEnemy()
{
}

void CTraceEnemy::Update()
{
	Move();
	SimpleMove();

	SpriteUpdate();
	AttackUpdate();

	m_bullets.Update();
}

void CTraceEnemy::Draw(HDC hdc)
{
	m_image.TransparentBlt(hdc, m_position.x, m_position.y, 52, 60, m_shape * 26, 0, 26, 30, RGB(255, 0, 255));

	m_bullets.Draw(hdc);
}

void CTraceEnemy::SpriteUpdate()
{

}

void CTraceEnemy::AttackUpdate()
{
	attackCounter.Increase();
	if (attackCounter.isLimit())
	{
		Attack();

		attackCounter.ResetCount();
	}
}

void CTraceEnemy::Move()
{
	m_traceCounter.Increase();

	if (m_traceCounter.isLimit()) {
		m_traceCounter.ResetCount();
		TraceTarget();
	}
}

void CTraceEnemy::Attack()
{
	m_bullets.AddObject(new CBullet(m_position));
}

void CTraceEnemy::TraceTarget()
{
	Vector2d pos = m_target->GetPosition();

	if (m_position.y <= pos.y) {
		m_direction = m_target->GetPosition() - m_position;
		m_direction.Normalize();
	}
	else
		m_direction = { 0, 1 };
}