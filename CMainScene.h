#pragma once
#include "CScene.h"

/*
�ۼ��� : 2018-03-13
���� : main scene�Դϴ�.
�����ϰ� ȭ�鿡 CMainScene�� ����ϰ�
����ϴ� �ؽ�Ʈ�� ��ġ�� ������ �Ʒ��� �����̵��� �մϴ�.
*/

class CMainScene : public CScene
{
public:
	CMainScene();
	~CMainScene();

	virtual void Update();
	virtual void Draw(HDC hdc);
	virtual void ProcessInput(CInput *input);

	virtual LRESULT CALLBACK ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	virtual void BuildObjects() {}
	virtual void ReleaseObjects() {}
};

