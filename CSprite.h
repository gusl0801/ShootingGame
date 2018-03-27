#pragma once

#include "CSprite.h"
#include "CRenderer.h"

enum class AnimationState
{
	None=0,

};

/*
ũ�Ⱑ ������ ��������Ʈ �̹����� ����ϱ� ���� Ŭ�����Դϴ�.
ũ�Ⱑ �������� ���� ��������Ʈ �̹����� ���ؼ�
CSpriteŬ������ ��ӹ޴� CUnOrderedSpriteŬ������ ���� �� ����մϴ�.
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

	vector<CRenderer> m_renderers;	// ��������Ʈ �̹���
	vector<Point2D> m_imageSizes;	// �� ���� ����� ��������Ʈ �̹����� ũ��
};

