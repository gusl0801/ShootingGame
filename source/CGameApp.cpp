#include "stdafx.h"
#include "CGameApp.h"
#include "resource.h"
#include "CBackBuffer.h"
#include "CTitleScene.h"
#include "CNullScene.h"

#define MS_PER_UPDATE 1 / 60.0f // 0.016f �Ϲ����� ����ʹ� 1�ʿ� 60�� ȭ���� ����
#define MAX_LOOP_COUNT 50 // update�������� �ѹ��� �ִ� 50�� ������ �����ϵ��� ����
#define TITLE_LENGTH	50	// Ÿ��Ʋ ���ڿ��� ���̸� �ִ� 50�ڷ� ����

// �ν��Ͻ��� �ʱ�ȭ ���ݴϴ�.
SINGLETON_IMPL(CGameApp);

CGameApp::CGameApp()
{
	m_currentScene = CScene::NewScene<CNullScene>();

	m_hInst = nullptr;
	m_hWnd = nullptr;

	LoadString(m_hInst, IDS_APP_TITLE, m_captionTitle, TITLE_LENGTH);

	lstrcat(m_captionTitle, TEXT(" ("));
	m_titleLength = lstrlen(m_captionTitle);
	SetWindowText(m_hWnd, m_captionTitle);
}

CGameApp::~CGameApp()
{
}

//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
ATOM CGameApp::MyRegisterClass(HINSTANCE hInstance)
{
	LoadStringW(hInstance, IDS_APP_TITLE, m_szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_SHOOTINGGAME, m_szWindowClass, MAX_LOADSTRING);

	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style =
		CS_HREDRAW		//Ŭ���̾�Ʈ�� ���̸� �����ϸ� �ٽ� �׸����� �մϴ�. 
		| CS_VREDRAW	//Ŭ���̾�Ʈ�� ���̸� �����ϸ� �ٽ� �׸����� �մϴ�.
		| CS_DBLCLKS	//�ش� �������α׷��� ���� Ŭ���� �����ϵ��� �մϴ�.
		;
	wcex.lpfnWndProc = StaticWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SHOOTINGGAME));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);  //������ ������ �����Ѵٸ� �ڵ����� ����Ƿη� �մϴ�.
	wcex.lpszMenuName = nullptr; // MAKEINTRESOURCEW(IDC_FRAMEWORK);
	wcex.lpszClassName = m_szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL CGameApp::InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	m_hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

	// ������ �������� ������ �������ݴϴ�.
	DWORD dwStyle =
		WS_OVERLAPPED	  //����Ʈ ������.Ÿ��Ʋ �ٿ� ũ�� ������ �ȵǴ� ��輱�� ���� �����츦 ����ϴ�.
		| WS_SYSMENU	  //�ý��� �޴��� ���� �����츦 ����ϴ�.
		| WS_MINIMIZEBOX  //�ּ�ȭ ��ư�� ���� �����츦 ����ϴ�.
		| WS_CAPTION	  //Ÿ��Ʋ �ٸ� ���� �����츦 ����� WS_BORDER ��Ÿ���� �����մϴ�.
		//  | WS_BORDER		  //�ܼ����� �� ��輱(ũ�� ���� �Ұ���)�� ����ϴ�.
		//  | WS_CLIPCHILDREN //���ϵ尡 ��ġ�� ������ �׸��� �ʽ��ϴ�.
		//  | WS_CLIPSIBLINGS //���ϵ峢�� ��ȣ ��ģ ������ �׸��� �������� �����մϴ�.
		//	| WS_CLIPCHILDREN //���ϵ尡 ��ġ�� ������ �׸��� �ʽ��ϴ�.
		//	| WS_CLIPSIBLINGS //���ϵ峢�� ��ȣ ��ģ ������ �׸��� �������� �����մϴ�.
		;

	RECT rtClient, rtDesktop;

	// �����찡 ������ ��ġ�� ȭ���� �߰��� �ǵ��� �մϴ�.
	GetWindowRect(GetDesktopWindow(), &rtDesktop); 

	// Ŭ���̾�Ʈ�� ũ�⸦ �����մϴ�.
	rtClient.left = rtClient.top = 0;
	rtClient.right = CLIENT_WIDTH;
	rtClient.bottom = CLIENT_HEIGHT;

	// ������ ������� �߰��Ǵ� ũ��� (ĸ��, �ܰ��� ��)�� �����մϴ�.
	AdjustWindowRect(&rtClient, dwStyle, FALSE);

	//Ŭ���̾�Ʈ�� ������ ��ǥ�� ����ũ���� �߾��� �ǵ��� �����մϴ�.
	POINT ptClientPos;

	ptClientPos.x = (rtDesktop.right - rtClient.right) * 0.5f;
	ptClientPos.y = (rtDesktop.bottom - rtClient.bottom) * 0.5f;

	m_hWnd = CreateWindowW(
		m_szWindowClass,	//������ Ŭ���� ��
		m_szTitle,			//Ÿ��Ʋ�� �Էµ� ���ڿ�
		dwStyle,			//������ ��Ÿ��
		ptClientPos.x,		//���� ���α׷��� ���۵� x��ǥ
		ptClientPos.y,		//���� ���α׷��� ���۵� y��ǥ
		rtClient.right  - rtClient.left,//���� ���α׷��� ���� ����
		rtClient.bottom - rtClient.top, //���� ���α׷��� ���� ���� 
		nullptr,			//�θ� ������
		nullptr,			//�޴� �ڵ�
		hInstance,			//�ν��Ͻ� �ڵ� 
		nullptr				//�߰� �Ķ����
	);

	if (!m_hWnd)
	{
		return FALSE;
	}

	ShowWindow(m_hWnd, nCmdShow);
	UpdateWindow(m_hWnd);

	return TRUE;
}

void CGameApp::FrameAdvance()
{
	int loopCount = 0;

	m_timer.Tick();

	while (m_timer.GetTimeLag() > MS_PER_UPDATE && loopCount++ < MAX_LOOP_COUNT)
	{
		ProcessInput(nullptr);

		Update();

		m_timer.UpdateTimeLag(-MS_PER_UPDATE);
	}
	Draw();

	float fps = m_timer.GetFrameRate();

	_itow_s(fps, m_captionTitle + m_titleLength, TITLE_LENGTH - m_titleLength, 10);
	wcscat_s(m_captionTitle + m_titleLength, TITLE_LENGTH - m_titleLength, TEXT(" FPS)"));
	SetWindowText(m_hWnd, m_captionTitle);
}

void CGameApp::Update()
{
	m_currentScene->Update();
}

void CGameApp::Draw()
{
	HDC backDC = m_backBuffer->GetBuffer();

	m_backBuffer->Reset();

	m_currentScene->Draw(backDC);
	
	m_backBuffer->Present();
}

void CGameApp::ProcessInput(CInput * input)
{
}

void CGameApp::ShutDown()
{
	ReleaseObjects();

	if (m_hWnd) DestroyWindow(m_hWnd);
}

LRESULT CGameApp::StaticWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// return CGameApp::Get()->ProcessWndProc(hWnd, message, wParam, lParam);
	// �� �ڵ�� �Ʒ� �ڵ�� ���� ����� �����մϴ�.
	return instance->ProcessWndProc(hWnd, message, wParam, lParam);
}

LRESULT CGameApp::ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	
	default:
		return m_currentScene->ProcessWndProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

void CGameApp::BuildObjects()
{
 	GetClientRect(m_hWnd, &m_viewport);
	m_backBuffer = new CBackBuffer(m_hWnd, m_viewport);

	m_currentScene = CScene::NewScene<CTitleScene>();
}

void CGameApp::ReleaseObjects()
{
	SAFE_DELETE(m_backBuffer);
}
