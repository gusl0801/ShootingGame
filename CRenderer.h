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

	// 스크린 영역에 맞춰서 이미지를 확장해 렌더링합니다.
	void StretchBlt(HDC hdc, const Point2D& position);
	
	// 비율에 맞게 이미지를 확장해 렌더링합니다.
	void StretchBlt(HDC hdc, const Point2D& position, double xRate, double yRate);

	void AlphaBlend(HDC hdc, const Point2D& position, DrawFunc drawFn);

	void AlphaBlend(HDC hdc, const Point2D& position) {}

private:
	CImage m_image;
};