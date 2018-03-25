#include "stdafx.h"
#include "CTitleScene.h"
#include "CTestScene.h"
#include "CGameApp.h"
#include "CMainScene.h"

CTitleScene::CTitleScene()
{
	Viewport viewport = CGameApp::Get()->GetViewport();

	m_textPosX = viewport.right * 0.5;
	m_textPosY = viewport.bottom * 0.5f;

	m_isMoveRight = false;

	m_text = TEXT("CTitleScene");
	m_textLen = lstrlen(m_text);

	m_textPosX -= m_textLen;
	m_textPosY -= 20;
	
	m_background.Load(TEXT("resource/backgrounds/sample_background.bmp"));
	
	m_soundPlayer.AddStream("resource/sounds/bgm/title_sample.mp3", Sound_Name::BGM_TITLE);
	m_soundPlayer.PlayBgm(Sound_Name::BGM_TITLE);
}


CTitleScene::~CTitleScene()
{
}

void CTitleScene::Update()
{
	Viewport viewport = CGameApp::Get()->GetViewport();
	
	m_soundPlayer.OnUpdate();

	if (m_isMoveRight)
	{
		m_textPosX += 5;
		if (m_textPosX + m_textLen * 5 >= viewport.right)
			m_isMoveRight = false;
	}
	else
	{
		m_textPosX -= 5;
		if (m_textPosX <= viewport.left)
			m_isMoveRight = true;
	}
}

void CTitleScene::Draw(HDC hdc)
{
	Viewport viewport = CGameApp::Get()->GetViewport();

	m_background.StretchBlt(hdc, 0, 0, viewport.right, viewport.bottom,
		0, 0, m_background.GetWidth(), m_background.GetHeight());
	//TextOut(hdc, m_textPosX, m_textPosY, m_text, m_textLen);
}

void CTitleScene::ProcessInput(CInput * input)
{
}

LRESULT CTitleScene::ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_KEYDOWN:
		if (wParam == VK_SPACE)
			CGameApp::Get()->ChangeScene(CScene::NewScene<CTestScene>());
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
