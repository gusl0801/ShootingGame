#pragma once

/*
�ۼ��� : 2018-03-09
����   : CGameAppŬ������ ������ �ʱ�ȭ �� ����, �۾� ó�� 
		 �Լ����� ������ �°� ȣ���� �� �ֵ��� �����ϴ� Ŭ�����Դϴ�.
*/
#include "CGameApp.h"

class CAppRunner
{
public:
	CAppRunner(CGameApp *app);
	~CAppRunner();

	bool Init(HINSTANCE hInst, int nCmdShow);
	int BeginApp();

private:
	CGameApp *m_app;
};

