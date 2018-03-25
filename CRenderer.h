#pragma once

class CGameObject;

typedef void(*DrawFunc)(CGameObject*);

class CRenderer
{
public:
	CRenderer();
	virtual ~CRenderer();

	HRESULT LoadImage(LPCTSTR szAddress) { return m_image.Load(szAddress); }

	void Update();

	virtual void BitBlt(HDC hdc);

	// 스크린 영역에 맞춰서 이미지를 확장해 렌더링합니다.
	virtual void StretchBlt(HDC hdc);
	
	// 비율에 맞게 이미지를 확장해 렌더링합니다.
	virtual void StretchBlt(HDC hdc, double xRate, double yRate);

	virtual void AlphaBlend(HDC hdc, DrawFunc drawFn);

	static void AlphaBlend(HDC hdc) {}

private:
	CImage m_image;
};