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
	int m_segement;			  // �� ���� �������� ������������, 0 ~ n
	int m_imagePosition;	  // �̹��� �󿡼� ����� ��ġ
	Point2D m_imageSize;	  // �̹��� �󿡼� ����� ũ��
	CRenderer* m_renderer;
};

