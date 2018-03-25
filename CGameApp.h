#pragma once

/*
�ۼ��� : 2018-03-09
����   : �����츦 �����ϰ� ��ü ���α׷��� �����ϴ� Ŭ�����Դϴ�.
*/
#include "Singleton.h"
#include "CTimer.h"
#include "CScene.h"

#define MAX_LOADSTRING 100

class CInput;
class CBackBuffer;



class CGameApp : public Singleton<CGameApp>
{
	//������ ���� �� ������ Ŭ���� ���� ��ũ��
	SINGLETON_DECL(CGameApp);

public:
	~CGameApp();

	ATOM MyRegisterClass(HINSTANCE hInstance);
	BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);
	
	void BuildObjects();

	void FrameAdvance();

	void ShutDown();
	
	Viewport GetViewport() const { return m_viewport; }

	void ChangeScene(CScene *scene) { if (scene == nullptr) return; m_currentScene = scene; }

private:
	static LRESULT CALLBACK StaticWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void Update();
	void Draw();
	void ProcessInput(CInput *input);

	void ReleaseObjects();

	// ��������� ���Կ����� �����մϴ�
	CGameApp(const CGameApp& other) = delete;
	CGameApp& operator=(const CGameApp& other) = delete;

	HWND m_hWnd;
	HINSTANCE m_hInst;
	HDC m_hdc;

	WCHAR m_szTitle[MAX_LOADSTRING];       // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
	WCHAR m_szWindowClass[MAX_LOADSTRING]; // �⺻ â Ŭ���� �̸��Դϴ�.

	Viewport m_viewport;
	CBackBuffer *m_backBuffer;

	CFPSTimer m_timer;
	TCHAR m_captionTitle[50];	// FPS Caption ��� ���� ����
	int m_titleLength;			// FPS Caption ��� ���� ����

	CScene * m_currentScene;
};

