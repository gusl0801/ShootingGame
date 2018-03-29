#pragma once

class CGameObject;

typedef void(*DrawFunc)(CGameObject*);

class CRenderer
{
public:
	CRenderer();
	~CRenderer();

	HRESULT Load(LPCTSTR szAddress) { return m_image.Load(szAddress); }

	void Update();

	void BitBlt(HDC hdc, const Point2D& position);

	// ��ũ�� ������ ���缭 �̹����� Ȯ���� �������մϴ�.
	void StretchBlt(HDC hdc, const Point2D& position);
	
	// ������ �°� �̹����� Ȯ���� �������մϴ�.
	void StretchBlt(HDC hdc, const Point2D& position, double xRate, double yRate);

	// ���ڷ� �Ѿ�� ������ �����ϰ� ����մϴ�.
	void TransparentBlt(HDC hdc, const Point2D& position, COLORREF color);

	void AlphaBlend(HDC hdc, const Point2D& position, DrawFunc drawFn);

	void AlphaBlend(HDC hdc, const Point2D& position) {}
	
	inline int GetWidth() const { return m_image.GetWidth(); }
	inline int GetHeight() const { return m_image.GetHeight(); }

private:
	CImage m_image;
};