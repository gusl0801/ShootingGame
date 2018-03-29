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
	
	void Load(LPCTSTR szAddress);
	virtual void Load(LPCTSTR szAddress, Point2D partition);
	
	virtual void Update();
	
	virtual void Draw(HDC hdc, const Point2D& position);
	
protected: 
	virtual void AlphaBlend(HDC hdc, const Point2D& position, DrawFunc drawFn);

	virtual void AlphaBlend(HDC hdc, const Point2D& position) {}

protected:
	AnimationState m_state;
	Point2D m_partition;		// ��������Ʈ�� x,y������ ��� �̹����� �����Ǵ���
	Point2D m_outputPosition;	// ��������Ʈ ��� ��ġ

	vector<CRenderer*> m_renderers;	// ��������Ʈ �̹���
	vector<Point2D> m_imageSizes;	// �� ���� ����� ��������Ʈ �̹����� ũ��

private:
	short m_index;
	
	short m_animationPerSecond;		// 1�ʿ� �� ȸ �ִϸ��̼��� ������ �� ����
	short m_animationDelay = 0;		// �ִϸ��̼� ���� Ƚ��
	short m_animationCount = 0;		// �ִϸ��̼� ������Ʈ�� ���� ���� ��Ų Ƚ��

	CImage m_image;
};

