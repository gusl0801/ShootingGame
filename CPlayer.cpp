#include "stdafx.h"
#include "CPlayer.h"


CPlayer::CPlayer()
	:CGameObject()
{
	m_position.x = CLIENT_WIDTH * 0.1f;
	m_position.y = CLIENT_HEIGHT * 0.45f;

	pos = Collide(1, 2, 3, 4, 5);

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

void CPlayer::TakeDamage(int dmg)
{
	hp -= dmg;
}