#include "stdafx.h"
#include "SceneSelectMenu_2D.h"
#include "Draw_2D.h"
#include "GameFrameWork_2D.h"

CSceneSelectMenu_2D::CSceneSelectMenu_2D(std::string name) : CGameState_2D(name)
{
}


CSceneSelectMenu_2D::~CSceneSelectMenu_2D()
{
}

void CSceneSelectMenu_2D::enter(HWND hWnd, HINSTANCE m_hInstance, int nWndClientWidth, int nWndClientHeight)
{
	m_width = nWndClientWidth;
	m_height = nWndClientHeight;

	

}

void CSceneSelectMenu_2D::exit()
{

}

void CSceneSelectMenu_2D::pause()
{
}

void CSceneSelectMenu_2D::resume()
{

}

//Render & Logic
void CSceneSelectMenu_2D::OnDraw(HDC hdc)
{
	LOGFONT			lf;
	lf.lfHeight = 300;
	lf.lfWidth = 0;
	lf.lfEscapement = 0;
	lf.lfOrientation = 0;
	lf.lfWeight = 30;
	lf.lfItalic = 0;
	lf.lfUnderline = 0;
	lf.lfStrikeOut = 0;
	lf.lfCharSet = HANGEUL_CHARSET;
	lf.lfOutPrecision = 0;
	lf.lfClipPrecision = 0;
	lf.lfClipPrecision = 0;
	lf.lfQuality = 0;
	lf.lfPitchAndFamily = 0;

	HFONT			hFont;
	hFont = CreateFontIndirect(&lf);
	(HFONT)SelectObject(hdc, hFont);
	TextOut(hdc, 500, 300, L"안냥",sizeof("안냥"));

	m_Background.OnDraw(hdc);

	Draw_2D::drawText(hdc, L"안녕하세요", 50, 50, RED, 50, L"MJ");
	static int pivot = 0;
	pivot += 10;
	pivot %= WIDTH;


	Draw_2D::drawText(hdc, 50+pivot, 150, RGB(255,255,0),250, L"gulim",L"%d %d 으아아아악",pivot, pivot);

}
void CSceneSelectMenu_2D::OnUpdate(float fTimeElapsed)
{
	
}

//Call
void CSceneSelectMenu_2D::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	switch (nMessageID)
	{
	case WM_MOUSEMOVE:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);
		break;

	case WM_RBUTTONDOWN:
		m_bRbutton = true;
		break;

	case WM_RBUTTONUP:
		m_bRbutton = false;

		break;

	case WM_LBUTTONDOWN:
		m_bLbutton = true;


		break;

	case WM_LBUTTONUP:
		m_bLbutton = false;
		break;
	}
}

void CSceneSelectMenu_2D::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	switch (nMessageID)
	{
	case WM_KEYDOWN:
		break;
	case WM_KEYUP:
		break;
	}
}

void CSceneSelectMenu_2D::SetWindowsSizeChange(int width, int height)
{
}

void CSceneSelectMenu_2D::CallMenu(WPARAM wParam)
{
}

