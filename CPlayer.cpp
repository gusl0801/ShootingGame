#include "stdafx.h"
#include "CPlayer.h"


CPlayer::CPlayer()
	:CGameObject()
{
	m_position.x = CLIENT_WIDTH * 0.42f;
	m_position.y = CLIENT_HEIGHT * 0.45f;

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
