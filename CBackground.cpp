#include "stdafx.h"
#include "CBackground.h"
#include "CGameApp.h"

CBackground::CBackground()
{
	LPCTSTR imageAddress = TEXT("resource/backgrounds/background_test.PNG");
	
	m_image.Load(imageAddress);
	
	m_viewport = CGameApp::Get()->GetViewport();

	m_gap = 0;
}

CBackground::~CBackground()
{
	if (m_image) m_image.Destroy();
}

void CBackground::Update()
{
	m_position.y += SCROLLING_SPEED;

	if (m_position.y >= m_viewport.bottom) {
		m_position.y -= m_viewport.bottom;
	}

	m_gap = m_position.y - m_viewport.bottom;
}

void CBackground::Draw(HDC hdc)
{
	m_image.BitBlt(hdc, m_position.x, m_position.y,
		m_viewport.right,m_viewport.bottom,
		0, 0, SRCCOPY);

	m_image.BitBlt(hdc, m_position.x, m_gap, 
		m_viewport.right, m_viewport.bottom,
		0, 0, SRCCOPY);
}
