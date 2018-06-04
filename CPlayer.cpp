#include "stdafx.h"
#include "CPlayer.h"

#include "CBoundingBox.h"

CPlayer::CPlayer()
	:CGameObject()
{
	m_position.x = CLIENT_WIDTH * 0.42f;
	m_position.y = CLIENT_HEIGHT * 0.45f;

	Vector2d leftTop = m_position;
	Vector2d rightBot = { m_position.x + m_width, m_position.y + m_height };

	m_boundary = new CBoundingBox(leftTop, rightBot);

	m_image.Load(TEXT("resource/characters/ship_1.png"));

	counter.SetLimit(CCounter::SecondToFrame(0.5));

	m_shape = 2;
}


CPlayer::~CPlayer()
{
}

void CPlayer::Update()
{
	
}

void CPlayer::Draw(HDC hdc)
{
	m_image.TransparentBlt(hdc, m_position.x, m_position.y, 52, 60, m_shape * 26, 0, 26, 30, RGB(255, 0, 255));
}

void CPlayer::Move(const Point2D & direction)
{
	m_position.x += direction.x;
	m_position.y += direction.y;
}

void CPlayer::Attack()
{
}
