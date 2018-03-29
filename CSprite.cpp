#include "stdafx.h"
#include "CSprite.h"


CSprite::CSprite()
{
	m_index = 0;

	const int SPRITE_NUM = 4;
	m_animationPerSecond = 4;
	m_animationDelay = FRAME_PER_SECOND / (m_animationPerSecond * SPRITE_NUM);
}


CSprite::~CSprite()
{
	m_renderers.clear();
}

void CSprite::Load(LPCTSTR szAddress)
{
	m_renderers.emplace_back(new CRenderer());
	m_renderers[m_index++]->Load(szAddress);
}

void CSprite::Load(LPCTSTR szAddress, Point2D partition)
{
	m_image.Load(szAddress);
	Load(szAddress);

	m_partition = partition;
	
	m_imageSizes.emplace_back(m_renderers[0]->GetWidth() / partition.x, m_renderers[0]->GetHeight() / partition.y);
	cout << m_imageSizes[0].x << ", " << m_imageSizes[0].y << endl;
}

void CSprite::Update()
{
	const int SPRITE_NUM = 4;

	++m_animationCount;

	if (m_animationCount > m_animationDelay)
	{
		m_animationCount = 0;

		m_outputPosition.x += 1;
		if (m_outputPosition.x > SPRITE_NUM)
			m_outputPosition.x = 0;
	}
}

void CSprite::Draw(HDC hdc, const Point2D & position)
{
	m_image.TransparentBlt(hdc, position.x, position.y, m_imageSizes[0].x, m_imageSizes[0].y,
		m_imageSizes[0].x * m_outputPosition.x, 0, m_imageSizes[0].x, m_imageSizes[0].y, RGB(255,255,255));
}

void CSprite::AlphaBlend(HDC hdc, const Point2D & position, DrawFunc drawFn)
{
}
