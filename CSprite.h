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
	virtual ~CSprite();

	void ChangeState(AnimationState state) { m_state = state; }
	
	virtual void Load(LPCTSTR szAddress, Point2D matrix, short stateNum) {}

	virtual void Update() {}
	
	virtual void Draw(HDC hdc, const Point2D& position) {}
	
protected:
	virtual void BitBlt(HDC hdc, const Point2D& position);

	virtual void StretchBlt(HDC hdc, const Point2D& position, double xRate, double yRate);

	virtual void AlphaBlend(HDC hdc, const Point2D& position, DrawFunc drawFn);

	virtual void AlphaBlend(HDC hdc, const Point2D& position) {}

protected:
	AnimationState m_state;
	short m_stateMaxNum;

	//map<CString, CRenderer> m_sprites;

	vector<CRenderer> m_renderers;	// 스프라이트 이미지
	vector<Point2D> m_imageSizes;	// 한 번에 출력할 스프라이트 이미지의 크기
};

