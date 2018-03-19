#include "stdafx.h"
#include "CMainScene.h"
#include "CGameApp.h"

CMainScene::CMainScene()
{
	cout << "CMainScene" << endl;
	Viewport viewport = CGameApp::Get()->GetViewport();

	m_bgXPos = m_bgYPos = 0;
}


CMainScene::~CMainScene()
{
}

void CMainScene::Update()
{
	Scrolling();
}

void CMainScene::Draw(HDC hdc)
{
	DrawBackground(hdc);
}

void CMainScene::ProcessInput(CInput * input)
{

}

LRESULT CMainScene::ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, message, wParam, lParam);
}

void CMainScene::DrawBackground(HDC hdc)
{
#define STAR_NUM 50
#define STAR_SIZE 7

	static int xSize[STAR_NUM], ySize[STAR_NUM], xPos[STAR_NUM], yPos[STAR_NUM];
	static bool isFirst = true;

	Viewport viewport = CGameApp::Get()->GetViewport();

	if (isFirst) {
		for (int i = 0; i < STAR_NUM; ++i)
		{
			xPos[i] = rand() % viewport.right;
			yPos[i] = rand() % viewport.bottom;
			xSize[i] = rand() % STAR_SIZE + 1;
			ySize[i] = rand() % STAR_SIZE + 1;
		}
		isFirst = false;
	}

	HBRUSH hBrush, oldBrush;
	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

	Rectangle(hdc, 0, 0, viewport.right, viewport.bottom);

	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);
	DeleteObject(oldBrush);

	for (int i = 0; i < STAR_NUM; ++i)
	{
		Ellipse(hdc, m_bgXPos + xPos[i], m_bgYPos + yPos[i],
			m_bgXPos + xPos[i] + xSize[i], m_bgYPos + yPos[i] + ySize[i]);
	}

	for (int i = 0; i < STAR_NUM; ++i)
	{
		Ellipse(hdc, m_bgXPos + xPos[i], m_bgGap + yPos[i],
			m_bgXPos + xPos[i] + xSize[i], m_bgGap + yPos[i] + ySize[i]);
	}
}

void CMainScene::Scrolling()
{
	Viewport viewport = CGameApp::Get()->GetViewport();

	m_bgYPos += 3;
	if (m_bgYPos >= viewport.bottom)
		m_bgYPos -= viewport.bottom;
	m_bgGap = m_bgYPos - viewport.bottom;
}
