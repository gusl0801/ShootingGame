#include "stdafx.h"
#include "CRenderer.h"
#include "CGameObject.h"
#include "CGameApp.h"

CRenderer::CRenderer()
{
}

CRenderer::~CRenderer()
{
	if (m_image) m_image.Destroy();
}

void CRenderer::Update()
{
}

void CRenderer::BitBlt(HDC hdc, const Point2D& screenPos)
{
	m_image.BitBlt(hdc, screenPos.x, screenPos.y, m_image.GetWidth(), m_image.GetHeight(),
		m_image.GetWidth(), m_image.GetHeight(), SRCCOPY);
}

void CRenderer::BitBltEx(HDC hdc, const Point2D& screenPos, const Point2D& size)
{
	m_image.BitBlt(hdc, screenPos.x, screenPos.y, size.x, size.y, size.x, size.y, SRCCOPY);
}

void CRenderer::StretchBltEx(HDC hdc, const Point2D& screenPos)
{
	Viewport viewport = CGameApp::Get()->GetViewport();

	m_image.StretchBlt(hdc, screenPos.x, screenPos.y, viewport.right, viewport.bottom,
		0, 0, m_image.GetWidth(), m_image.GetHeight(), SRCCOPY);
}

void CRenderer::StretchBltEx(HDC hdc, const Point2D& screenPos, const Point2D& imagePos, const Point2D& size)
{
	Viewport viewport = CGameApp::Get()->GetViewport();

	m_image.StretchBlt(hdc, screenPos.x, screenPos.y, size.x, size.y,
		imagePos.x * size.x, imagePos.y * size.y, size.x, size.y, SRCCOPY);
}

void CRenderer::StretchBltEx(HDC hdc, const Point2D& screenPos, const Point2D& imagePos, const Point2D& size, double xRate, double yRate)
{
	m_image.StretchBlt(hdc, screenPos.x, screenPos.y, m_image.GetWidth() * xRate, m_image.GetHeight() * yRate,
		imagePos.x * size.x, imagePos.y * size.y, size.x, size.y, SRCCOPY);
}

void CRenderer::TransparentBlt(HDC hdc, const Point2D & screenPos)
{
	m_image.TransparentBlt(hdc, screenPos.x, screenPos.y, m_image.GetWidth(), m_image.GetHeight(),
		0, 0, m_image.GetWidth(), m_image.GetHeight(), TRANSPARENT_COLOR);
}

void CRenderer::TransparentBltEx(HDC hdc, const Vector2d & screenPos, const Point2D& imagePos, const Point2D & size)
{
	m_image.TransparentBlt(hdc, screenPos.x, screenPos.y, size.x, size.y,
		imagePos.x * size.x, imagePos.y * size.y, size.x, size.y, TRANSPARENT_COLOR);
}

void CRenderer::AlphaBlend(HDC hdc, const Point2D& screenPos, DrawFunc drawFn)
{
	//COLORREF removeColor = RGB(255, 0, 255);		//지울 색상
	////static int alpha = 0;				//투명도

	//if (m_nAlpha <= 255)
	//{
	//	HDC LayDC;
	//	HBITMAP Lay;
	//	BLENDFUNCTION bf;

	//	bf.BlendOp = AC_SRC_OVER;
	//	bf.BlendFlags = 0;
	//	bf.AlphaFormat = 0;
	//	bf.SourceConstantAlpha = m_nAlpha;

	//	Lay = CreateCompatibleBitmap(hdc, m_rcApp.right, m_rcApp.bottom);
	//	LayDC = CreateCompatibleDC(hdc);
	//	SelectObject(LayDC, Lay);
	//	TransparentBlt(LayDC, 0, 0, m_rcApp.right, m_rcApp.bottom
	//		, hdc, m_rcApp.left, m_rcApp.top, m_rcApp.right, m_rcApp.bottom, removeColor);

	//	m_map->OnDraw(hdc, m_vecUnits, 0, camera);

	//	AlphaBlend(hdc, m_rcApp.left, m_rcApp.top, m_rcApp.right, m_rcApp.bottom
	//		, LayDC, 0, 0, m_rcApp.right, m_rcApp.bottom, bf);

	//	DeleteDC(LayDC);
	//	DeleteObject(Lay);
	//	m_nAlpha += 3;
	//}
}
