#include "stdafx.h"
#include "CSprite.h"


CSprite::CSprite()
{
	
}


CSprite::~CSprite()
{
	SAFE_DELETE(m_renderer);
}


void CSprite::Load(LPCTSTR szAddress, int segement, int startPoint, const Point2D & size)
{
	assert(!m_renderer && !"only one renderer per CSprite instance");
	
	m_renderer = new CRenderer();
	m_renderer->Load(szAddress);
	
	m_segement = segement;
	m_imagePosition = startPoint;
	m_imageSize = size;
}

void CSprite::LoadFromFile(LPSTR szAddress)
{
}
void CSprite::Draw(HDC hdc, const Vector2d & position)
{
	m_renderer->TransparentBltEx(hdc, position, { m_imagePosition * m_imageSize.x, m_imageSize.y }, m_imageSize);
}

void CSprite::Draw(HDC hdc, const Vector2d & position, const Point2D & size)
{
	m_renderer->TransparentBltEx(hdc, position, { m_imagePosition * m_imageSize.x, m_imageSize.y }, size);
}

void CSprite::AlphaBlend(HDC hdc, const Point2D & position, DrawFunc drawFn)
{
}
