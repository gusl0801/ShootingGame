#pragma once

#include "CSprite.h"
#include "CRenderer.h"

enum class AnimationState
{
	None=0,

};

/*
크기가 균일한 스프라이트 이미지를 출력하기 위한 클래스입니다.
크기가 균일하지 못한 스프라이트 이미지에 대해선
CSprite클래스를 상속받는 CUnOrderedSprite클래스를 정의 및 사용합니다.
*/

class CSprite
{
public:
	CSprite();
	~CSprite();

	void Load(LPCTSTR szAddress, int segement, int startPoint, const Point2D &size);
	void LoadFromFile(LPSTR szAddress);
	
	void Draw(HDC hdc, const Vector2d & position);
	void Draw(HDC hdc, const Vector2d & position, const Point2D & size);
	
	void Add(int num) { m_imagePosition = min(m_imagePosition + num, m_segement); }
	void Sub(int num) { m_imagePosition = max(m_imagePosition - num, m_segement); }

	void Increase() { Add(1); }
	void Decrease() { Sub(1); }

	void AlphaBlend(HDC hdc, const Point2D& position, DrawFunc drawFn);
	void AlphaBlend(HDC hdc, const Point2D& position) {}


private:
	int m_segement;			  // 몇 개의 영역으로 나누어지는지, 0 ~ n
	int m_imagePosition;	  // 이미지 상에서 출력할 위치
	Point2D m_imageSize;	  // 이미지 상에서 출력할 크기
	CRenderer* m_renderer;
};

