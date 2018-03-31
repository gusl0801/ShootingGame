#include "stdafx.h"
#include "CScene.h"

CScene::~CScene()
{
	if (m_soundPlayer) m_soundPlayer->StopBGM();
}
