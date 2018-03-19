#pragma once
#include "CScene.h"

/*
�ۼ��� : 2018-03-13
���� : main scene�Դϴ�.
�����ϰ� ȭ�鿡 CMainScene�� ����ϰ�
����ϴ� �ؽ�Ʈ�� ��ġ�� ������ �Ʒ��� �����̵��� �մϴ�.
*/

class CMainScene :
	public CScene
{
public:
	CMainScene();
	~CMainScene();

	virtual void Update();
	virtual void Draw(HDC hdc);
	virtual void ProcessInput(CInput *input);

	virtual LRESULT CALLBACK ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	void DrawBackground(HDC hdc);
	void Scrolling();

	CImage m_background;
	int m_bgXPos;
	int m_bgYPos;
	int m_bgGap;
};

