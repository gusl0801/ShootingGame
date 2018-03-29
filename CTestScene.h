#pragma once
#include "CScene.h"

#include "CBackground.h"

class CPlayer;

class CTestScene : public CScene
{
public:
	CTestScene();
	~CTestScene();

	virtual void Update();
	virtual void Draw(HDC hdc);
	virtual void ProcessInput(CInput *input);

	virtual LRESULT CALLBACK ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	virtual void BuildObjects();
	virtual void ReleaseObjects();
	
	CBackground m_background;

	CPlayer *m_player;
};

