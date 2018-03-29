#include "stdafx.h"
#include "CPlayer.h"


CPlayer::CPlayer()
	:CGameObject()
{
	m_position.x = 100;
	m_position.y = 100;

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
	m_renderer->Draw(hdc, m_position);
}
