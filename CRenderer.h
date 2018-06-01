#pragma once

class CGameObject;

typedef void(*DrawFunc)(CGameObject*);

#define TRANSPARENT_COLOR RGB(255,0,255)

class CRenderer
{
public:
	CRenderer();
	~CRenderer();

	HRESULT Load(LPCTSTR szAddress) { return m_image.Load(szAddress); }

	void Update();
//---------------------------------------------------
// 그리기 관련함수들
// NonEx : 이미지 크기 만큼 출력
// Ex : 인자로 넘어온 크기 만큼 출력
//---------------------------------------------------
	void BitBlt(HDC hdc, const Point2D& screenPos);
	void BitBltEx(HDC hdc, const Point2D& screenPos, const Point2D& size);

	// 스크린 영역에 맞춰서 이미지를 확장해 렌더링합니다.
	void StretchBltEx(HDC hdc, const Point2D& screenPos);
	void StretchBltEx(HDC hdc, const Point2D& screenPos, const Point2D& imagePos, const Point2D& size);

	// 비율에 맞게 이미지를 확장해 렌더링합니다.
	void StretchBltEx(HDC hdc, const Point2D& screenPos, const Point2D& imagePos, const Point2D& size, double xRate, double yRate);

	// 인자로 넘어온 색상을 제거하고 출력합니다.
	void TransparentBlt(HDC hdc, const Point2D& screenPos);
	void TransparentBltEx(HDC hdc, const Vector2d & screenPos, const Point2D& imagePos,const Point2D& size);

	void AlphaBlend(HDC hdc, const Point2D& screenPos, DrawFunc drawFn);

	void AlphaBlend(HDC hdc, const Point2D& screenPos) {}
	
	inline int GetWidth() const { return m_image.GetWidth(); }
	inline int GetHeight() const { return m_image.GetHeight(); }

private:
	CImage m_image;
};