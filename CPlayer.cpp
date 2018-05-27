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

	m_renderer->Load(TEXT("resource/characters/sprite_test.png"), {6,8});
}


CPlayer::~CPlayer()
{
}

void CPlayer::Update()
{
	m_renderer->Update();
}

void CPlayer::Draw(HDC hdc)
{
	Point2D position = { (int)m_position.x, (int)m_position.y };
	m_renderer->Draw(hdc, position);
}
