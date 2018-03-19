#include "stdafx.h"
#include "CAppRunner.h"


CAppRunner::CAppRunner(CGameApp *app)
	:m_app(app)
{
}


CAppRunner::~CAppRunner()
{
}

bool CAppRunner::Init(HINSTANCE hInst, int nCmdShow)
{
	m_app->MyRegisterClass(hInst);

	// ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
	if (!m_app->InitInstance(hInst, nCmdShow))
	{	// ���� ���α׷� ������ ���������� ���� ��� �ߴ�
		m_app->ShutDown();
		return false;
	}

	m_app->BuildObjects();

	srand((unsigned int)time(NULL));

	return true;
}

int CAppRunner::BeginApp()
{
	MSG msg;

	// �⺻ �޽��� �����Դϴ�
	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}//end if  �ü���κ��� �޽����� ���� ��� �ش� �޽����� �ݹ��Լ����� ����
		else
		{
			m_app->FrameAdvance();
		}//end elif �޽����� ���� ��쿡�� ������ ����Ǿ�� �ϹǷ� ���� ����
	}

	return (int)msg.wParam;
}
