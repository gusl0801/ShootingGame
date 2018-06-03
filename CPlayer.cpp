#include "stdafx.h"
#include "CPlayer.h"

#include "CBoundingBox.h"

CPlayer::CPlayer()
	:CGameObject()
{
	m_position.x = CLIENT_WIDTH * 0.42f;
	m_position.y = CLIENT_HEIGHT * 0.45f;
	
	//m_width = width;
	//m_height = height;

	Vector2d leftTop = m_position;
	Vector2d rightBot = { m_position.x + m_width, m_position.y + m_height };

	m_boundary = new CBoundingBox(leftTop, rightBot);

	m_image.Load(TEXT("resource/characters/ship_1.png"));

	counter.SetLimit(CCounter::SecondToFrame(0.5));

	shape = 2;
}


CPlayer::~CPlayer()
{
}

void CPlayer::Update()
{
	/*counter.Increase();
	if (counter.isLimit())
	{
		if (isRight) shape += 1;
		else shape -= 1;
		if (shape >= 4) isRight = false;
		if (shape <= 0) isRight = true;

		counter.ResetCount();
	}*/
}

void CPlayer::Draw(HDC hdc)
{
	m_image.TransparentBlt(hdc, m_position.x, m_position.y, 52, 60, shape * 26, 0, 26, 30, RGB(255, 0, 255));
}
