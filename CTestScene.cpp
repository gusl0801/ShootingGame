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

void CTestScene::ProcessInput()
{	
	if (IS_KEY_DOWN(VK_LEFT))  { m_player->Test(-1,0);}
	if (IS_KEY_DOWN(VK_RIGHT)) { m_player->Test(1,0); }
	if (IS_KEY_DOWN(VK_UP))    { m_player->Test(0,-1);}
	if (IS_KEY_DOWN(VK_DOWN))  { m_player->Test(0,1); }
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
