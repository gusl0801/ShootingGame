#pragma once

class CGameObject;

typedef void(*DrawFunc)(CGameObject*);

class CRenderer
{
public:
	CRenderer();
	~CRenderer();

	HRESULT LoadImage(LPCTSTR szAddress) { return m_image.Load(szAddress); }

	void Update();

	void BitBlt(HDC hdc, const Point2D& position);

	// ��ũ�� ������ ���缭 �̹����� Ȯ���� �������մϴ�.
	void StretchBlt(HDC hdc, const Point2D& position);
	
	// ������ �°� �̹����� Ȯ���� �������մϴ�.
	void StretchBlt(HDC hdc, const Point2D& position, double xRate, double yRate);

	void AlphaBlend(HDC hdc, const Point2D& position, DrawFunc drawFn);

	void AlphaBlend(HDC hdc, const Point2D& position) {}

private:
	CImage m_image;
};