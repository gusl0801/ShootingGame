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

	// ��ũ�� ������ ���缭 �̹����� Ȯ���� �������մϴ�.
	virtual void StretchBlt(HDC hdc);
	
	// ������ �°� �̹����� Ȯ���� �������մϴ�.
	virtual void StretchBlt(HDC hdc, double xRate, double yRate);

	virtual void AlphaBlend(HDC hdc, DrawFunc drawFn);

	static void AlphaBlend(HDC hdc) {}

private:
	CImage m_image;
};