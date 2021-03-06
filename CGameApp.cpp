#include "stdafx.h"
#include "CGameApp.h"
#include "resource.h"
#include "CBackBuffer.h"
#include "CTitleScene.h"
#include "CNullScene.h"

#define MS_PER_UPDATE 1 / FPS // 0.016f 일반적인 모니터는 1초에 60번 화면을 갱신
#define MAX_LOOP_COUNT 50 // update따라잡기는 한번에 최대 50번 까지만 가능하도록 설정
#define TITLE_LENGTH	50	// 타이틀 문자열의 길이를 최대 50자로 설정

// 인스턴스를 초기화 해줍니다.
SINGLETON_IMPL(CGameApp);

CGameApp::CGameApp()
{
	m_currentScene = CScene::NewScene<CNullScene>();

	m_hInst = nullptr;
	m_hWnd = nullptr;
}

CGameApp::~CGameApp()
{
}

//
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
//
ATOM CGameApp::MyRegisterClass(HINSTANCE hInstance)
{
	LoadStringW(hInstance, IDS_APP_TITLE, m_szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_SHOOTINGGAME, m_szWindowClass, MAX_LOADSTRING);

	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style =
		CS_HREDRAW		//클라이언트의 넓이를 변경하면 다시 그리도록 합니다. 
		| CS_VREDRAW	//클라이언트의 높이를 변경하면 다시 그리도록 합니다.
		| CS_DBLCLKS	//해당 응용프로그램이 더블 클릭을 지원하도록 합니다.
		;
	wcex.lpfnWndProc = StaticWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SHOOTINGGAME));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);  //윈도우 배경색을 변경한다면 자동으로 적용되로록 합니다.
	wcex.lpszMenuName = nullptr; // MAKEINTRESOURCEW(IDC_FRAMEWORK);
	wcex.lpszClassName = m_szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   목적: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   설명:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL CGameApp::InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	m_hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

	// 생성할 윈도우의 형식을 지정해줍니다.
	DWORD dwStyle =
		WS_OVERLAPPED	  //디폴트 윈도우.타이틀 바와 크기 조절이 안되는 경계선을 갖는 윈도우를 만듭니다.
		| WS_SYSMENU	  //시스템 메뉴를 가진 윈도우를 만듭니다.
		| WS_MINIMIZEBOX  //최소화 버튼을 갖는 윈도우를 만듭니다.
		| WS_CAPTION	  //타이틀 바를 가진 윈도우를 만들며 WS_BORDER 스타일을 포함합니다.
		//  | WS_BORDER		  //단선으로 된 경계선(크기 조절 불가능)을 만듭니다.
		//  | WS_CLIPCHILDREN //차일드가 위치한 영역은 그리지 않습니다.
		//  | WS_CLIPSIBLINGS //차일드끼리 상호 겹친 영역은 그리기 영역에서 제외합니다.
		//	| WS_CLIPCHILDREN //차일드가 위치한 영역은 그리지 않습니다.
		//	| WS_CLIPSIBLINGS //차일드끼리 상호 겹친 영역은 그리기 영역에서 제외합니다.
		;

	RECT rtClient, rtDesktop;

	// 윈도우가 생성될 위치를 화면의 중간이 되도록 합니다.
	GetWindowRect(GetDesktopWindow(), &rtDesktop); 

	// 클라이언트의 크기를 설정합니다.
	rtClient.left = rtClient.top = 0;
	rtClient.right = CLIENT_WIDTH;
	rtClient.bottom = CLIENT_HEIGHT;

	// 윈도우 사이즈에서 추가되는 크기들 (캡션, 외각선 등)을 보정합니다.
	AdjustWindowRect(&rtClient, dwStyle, FALSE);

	//클라이언트가 생성될 좌표가 데스크톱의 중앙이 되도록 지정합니다.
	POINT ptClientPos;

	ptClientPos.x = (rtDesktop.right - rtClient.right) * 0.5f;
	ptClientPos.y = (rtDesktop.bottom - rtClient.bottom) * 0.5f;

	m_hWnd = CreateWindowW(
		m_szWindowClass,	//윈도우 클래스 명
		m_szTitle,			//타이틀에 입력될 문자열
		dwStyle,			//윈도우 스타일
		ptClientPos.x,		//응용 프로그램이 시작될 x좌표
		ptClientPos.y,		//응용 프로그램이 시작될 y좌표
		rtClient.right  - rtClient.left,//응용 프로그램의 가로 길이
		rtClient.bottom - rtClient.top, //응용 프로그램의 세로 길이 
		nullptr,			//부모 윈도우
		nullptr,			//메뉴 핸들
		hInstance,			//인스턴스 핸들 
		nullptr				//추가 파라메터
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
	m_timer.UpdateTimeElpased();	// 이전 함수 호출부터 현재 함수 호출까지 경과한 시간을 계산합니다.

	if (m_timer.GetTimeElapsed() > MS_PER_UPDATE)	// 지정된 시간이 경과한 경우
	{
		m_timer.Tick();				// 시간을 업데이트 합니다.

		// 게임 시간이 늦어진 경우 늦은 시간을 따라잡을 때 까지
		// 반복해서 업데이트 시킵니다.
		for (int i = 0; i < MAX_LOOP_COUNT && m_timer.GetTimeLag() > MS_PER_UPDATE; ++i)
		{
			ProcessInput();

			Update();

			m_timer.UpdateTimeLag(-MS_PER_UPDATE);
		}
	}
	else // 지정된 시간이 경과하지 않은 경우 업데이트를 생략합니다.
		return;
	
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

void CGameApp::ProcessInput()
{
	m_currentScene->ProcessInput();
}

void CGameApp::ShutDown()
{
	ReleaseObjects();

	if (m_hWnd) DestroyWindow(m_hWnd);
}

void CGameApp::ChangeScene(CScene * scene)
{ 
	if (scene == nullptr) return; 
	
	SAFE_DELETE(m_currentScene);  
	m_currentScene = scene; 
}

LRESULT CGameApp::StaticWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// return CGameApp::Get()->ProcessWndProc(hWnd, message, wParam, lParam);
	// 위 코드와 아래 코드는 같은 기능을 수행합니다.
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

	LoadString(m_hInst, IDS_APP_TITLE, m_captionTitle, TITLE_LENGTH);

	lstrcat(m_captionTitle, TEXT(" ("));
	m_titleLength = lstrlen(m_captionTitle);
	SetWindowText(m_hWnd, m_captionTitle);

	m_currentScene = CScene::NewScene<CTitleScene>();
}

void CGameApp::ReleaseObjects()
{
	SAFE_DELETE(m_backBuffer);
}
