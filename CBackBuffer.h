#pragma once

/*
�ۼ��� : 2018-03-11
����   : ������۸� ó���� ���� ����� �����ϴ� Ŭ�����Դϴ�.
*/
class CBackBuffer
{
public:
	CBackBuffer(HWND hWnd, const RECT &rtClientSize);
	~CBackBuffer();

	HDC GetBuffer() const { return m_hDC; }
	void Reset(){ FillRect(m_hDC, &m_rtClientSize, m_hBrush); }
	void Resize(const RECT &rtClientSize) { m_rtClientSize = rtClientSize; }

	// ������� DC�� �׷��� ������ ��DC�� �ű�ϴ�.
	void Present();

private:
	// ��������� ���Կ����� �����մϴ�
	CBackBuffer(const CBackBuffer &other) = delete;
	CBackBuffer& operator=(const CBackBuffer &other) = delete;

	HWND m_hWnd;
	HDC m_hDC;
	HBITMAP m_hBmp;
	HBRUSH m_hBrush;

	RECT m_rtClientSize;
};

