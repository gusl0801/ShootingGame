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
	
	void Load(LPCTSTR szAddress);
	virtual void Load(LPCTSTR szAddress, Point2D partition);
	
	virtual void Update();
	
	virtual void Draw(HDC hdc, const Point2D& position);
	
protected: 
	virtual void AlphaBlend(HDC hdc, const Point2D& position, DrawFunc drawFn);

	virtual void AlphaBlend(HDC hdc, const Point2D& position) {}

protected:
	AnimationState m_state;
	Point2D m_partition;		// 스프라이트가 x,y축으로 몇개의 이미지로 구성되는지
	Point2D m_outputPosition;	// 스프라이트 출력 위치

	vector<CRenderer*> m_renderers;	// 스프라이트 이미지
	vector<Point2D> m_imageSizes;	// 한 번에 출력할 스프라이트 이미지의 크기

private:
	short m_index;
	
	short m_animationPerSecond;		// 1초에 몇 회 애니메이션을 진행할 것 인지
	short m_animationDelay = 0;		// 애니메이션 지연 횟수
	short m_animationCount = 0;		// 애니메이션 업데이트를 위해 증가 시킨 횟수

	CImage m_image;
};

