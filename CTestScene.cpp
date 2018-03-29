#include "stdafx.h"
#include "CTestScene.h"
#include "CGameApp.h"
#include "CPlayer.h"

CTestScene::CTestScene()
{
	cout << "CTestScene" << endl;
	Viewport viewport = CGameApp::Get()->GetViewport();

	BuildObjects();
}


CTestScene::~CTestScene()
{
	ReleaseObjects();
}

void CTestScene::Update()
{
	m_background.Update();
	m_player->Update();
}

void CTestScene::Draw(HDC hdc)
{
	m_background.Draw(hdc);
	m_player->Draw(hdc);
}

void CTestScene::ProcessInput(CInput * input)
{

}

LRESULT CTestScene::ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, message, wParam, lParam);
}

void CTestScene::BuildObjects()
{
	m_player = new CPlayer;
}

void CTestScene::ReleaseObjects()
{
}
