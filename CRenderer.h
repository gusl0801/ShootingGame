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
// �׸��� �����Լ���
// NonEx : �̹��� ũ�� ��ŭ ���
// Ex : ���ڷ� �Ѿ�� ũ�� ��ŭ ���
//---------------------------------------------------
	void BitBlt(HDC hdc, const Point2D& screenPos);
	void BitBltEx(HDC hdc, const Point2D& screenPos, const Point2D& size);

	// ��ũ�� ������ ���缭 �̹����� Ȯ���� �������մϴ�.
	void StretchBltEx(HDC hdc, const Point2D& screenPos);
	void StretchBltEx(HDC hdc, const Point2D& screenPos, const Point2D& imagePos, const Point2D& size);

	// ������ �°� �̹����� Ȯ���� �������մϴ�.
	void StretchBltEx(HDC hdc, const Point2D& screenPos, const Point2D& imagePos, const Point2D& size, double xRate, double yRate);

	// ���ڷ� �Ѿ�� ������ �����ϰ� ����մϴ�.
	void TransparentBlt(HDC hdc, const Point2D& screenPos);
	void TransparentBltEx(HDC hdc, const Vector2d & screenPos, const Point2D& imagePos,const Point2D& size);

	void AlphaBlend(HDC hdc, const Point2D& screenPos, DrawFunc drawFn);

	void AlphaBlend(HDC hdc, const Point2D& screenPos) {}
	
	inline int GetWidth() const { return m_image.GetWidth(); }
	inline int GetHeight() const { return m_image.GetHeight(); }

private:
	CImage m_image;
};