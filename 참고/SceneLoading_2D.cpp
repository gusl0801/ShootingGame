#include "stdafx.h"
#include "GameFrameWork_2D.h"

#include "SceneLoading_2D.h"
#include "SceneSelectMenu_2D.h"

CSceneLoading_2D::CSceneLoading_2D(std::string name) : CGameState_2D(name)
{
}

CSceneLoading_2D::~CSceneLoading_2D()
{
	delete this;
}

void CSceneLoading_2D::enter(HWND hWnd, HINSTANCE m_hInstance, int nWndClientWidth, int nWndClientHeight)
{
	m_width = nWndClientWidth;
	m_height = nWndClientHeight;

	mx = my = 0;

	m_logo.Init("로고");
	m_logo.OnCreate(m_width / 2, m_height / 2, m_width, m_height);
	m_alpha = 255;
	
}

void CSceneLoading_2D::exit()
{
	

}

void CSceneLoading_2D::pause()
{
}

void CSceneLoading_2D::resume()
{
}   

//Render & Logic
void CSceneLoading_2D::OnDraw(HDC hdc)
{
	Draw_2D::drawRect(hdc, 1250, 750, 540, 480, BRIGHT_BLUE_3, true);

	m_logo.OnDrawAlpha(hdc, m_alpha--);
	Draw_2D::drawText(hdc, 100,50 , BRIGHT_BLUE_3, L"프레임워크 입니다");
	
}

void CSceneLoading_2D::OnUpdate(float fTimeElapsed)
{
	if (m_alpha == 200)
		SOUNDMGR->PlayEFFECT("로딩띠리링");

	if (m_alpha < 150)
		FRAMEWORK_2D->change_state(new CSceneSelectMenu_2D("SceneSelect"));
	
}

//Call
void CSceneLoading_2D::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	if (nMessageID == WM_MOUSEMOVE)
	{
		mx = LOWORD(lParam);
		my = HIWORD(lParam);
	}

}

void CSceneLoading_2D::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{

	
}

void CSceneLoading_2D::SetWindowsSizeChange(int width, int height)
{
}

void CSceneLoading_2D::CallMenu(WPARAM wParam)
{
}

