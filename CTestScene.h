#pragma once
#include "CScene.h"

#include "CBackground.h"
#include "CObjectManager.h"

class CPlayer;
class CBullet;

class CTestScene : public CScene
{
public:
	CTestScene();
	~CTestScene();

	virtual void Update();
	virtual void Draw(HDC hdc);
	virtual void ProcessInput();

	virtual LRESULT CALLBACK ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	virtual void BuildObjects();
	virtual void ReleaseObjects();
	
	CBackground m_background;

	CPlayer *m_player;

	CObjectManager m_bullets;
};

