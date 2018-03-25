#include "stdafx.h"
#include "CTestScene.h"
#include "CGameApp.h"

CTestScene::CTestScene()
{
	cout << "CTestScene" << endl;
	Viewport viewport = CGameApp::Get()->GetViewport();
}


CTestScene::~CTestScene()
{
}

void CTestScene::Update()
{
	m_background.Update();
}

void CTestScene::Draw(HDC hdc)
{
	m_background.Draw(hdc);
}

void CTestScene::ProcessInput(CInput * input)
{

}

LRESULT CTestScene::ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, message, wParam, lParam);
}
