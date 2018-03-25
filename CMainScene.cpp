#include "stdafx.h"
#include "CMainScene.h"
#include "CGameApp.h"

CMainScene::CMainScene()
{
	cout << "CMainScene" << endl;
	Viewport viewport = CGameApp::Get()->GetViewport();
}


CMainScene::~CMainScene()
{
}

void CMainScene::Update()
{
}

void CMainScene::Draw(HDC hdc)
{
}

void CMainScene::ProcessInput(CInput * input)
{

}

LRESULT CMainScene::ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, message, wParam, lParam);
}
