#include "stdafx.h"
#include "CSimpleShooter.h"

#include "CBoundingBox.h"
#include "CNWayBullet.h"

CSimpleShooter::CSimpleShooter()
{
	m_position.x = rand() % CLIENT_WIDTH;
	m_position.y = 20;
	m_direction = rand() % 2;

	//m_width = width;
	//m_height = height;

	Vector2d leftTop = m_position;
	Vector2d rightBot = { m_position.x + m_width, m_position.y + m_height };

	m_boundary = new CBoundingBox(leftTop, rightBot);

	m_image.Load(TEXT("resource/characters/enemy_1.png"));

	attackCounter.SetLimit(CCounter::SecondToFrame(0.5));
	spriteCounter.SetLimit(CCounter::SecondToFrame(0.5));
}


CSimpleShooter::~CSimpleShooter()
{
}

void CSimpleShooter::Update()
{
	Move();
	
	SpriteUpdate();
	AttackUpdate();

	m_bullets.Update();
}

void CSimpleShooter::Draw(HDC hdc)
{
	m_image.TransparentBlt(hdc, m_position.x, m_position.y, 52, 60, shape * 26, 0, 26, 30, RGB(255, 0, 255));

	m_bullets.Draw(hdc);
}

void CSimpleShooter::SpriteUpdate()
{
	spriteCounter.Increase();
	if (spriteCounter.isLimit())
	{
		if (isRight) shape += 1;
		else shape -= 1;
		if (shape >= 4) isRight = false;
		if (shape <= 0) isRight = true;

		spriteCounter.ResetCount();
	}
}

void CSimpleShooter::AttackUpdate()
{
	attackCounter.Increase();
	if (attackCounter.isLimit())
	{
		Attack();

		attackCounter.ResetCount();
	}
}

void CSimpleShooter::Move()
{
	if (m_direction == 1) {
		m_position.x += ENEMY_SPEED;
		if (m_position.x >= CLIENT_WIDTH - 50)
			m_direction = 0;
	}
	else {
		m_position.x -= ENEMY_SPEED;
		if (m_position.x <= 0)
			m_direction = 1;
	}
}

void CSimpleShooter::Attack()
{
	m_bullets.AddObject(new CNWayBullet(m_position, { m_position.x, CLIENT_HEIGHT }, 3));
}