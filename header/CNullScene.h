#pragma once
#include "CScene.h"

/*
�ۼ��� : 2018-03-13
���� : nullptrȮ���� ���� �ʱ� ���ؼ� �߰������� ������ nullŬ������
	   ������ ����� �������� �ʽ��ϴ�.
*/
class CNullScene :
	public CScene
{
public:
	CNullScene();
	~CNullScene();

	virtual void Update() {}
	virtual void Draw(HDC hdc) {}
	virtual void ProcessInput(CInput *input) {}

	virtual LRESULT CALLBACK ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{ return DefWindowProc(hWnd, message, wParam, lParam); }
};

