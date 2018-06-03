#include "stdafx.h"
#include "CTestScene.h"
#include "CGameApp.h"
#include "CPlayer.h"
#include "CSimpleShooter.h"

#include "CBullet.h"
#include "CNWayBullet.h"
#include "CSplitBullet.h"
#include "CDropBullet.h"
#include "CCircularBullet.h"
#include "CTraceBullet.h"
#include "CRapidBullet.h"
#include "CSplitBullet.h"
#include "CExtensionBullet.h"

CTestScene::CTestScene()
{
	cout << "CTestScene" << endl;
	Viewport viewport = CGameApp::Get()->GetViewport();

	BuildObjects();
}


CTestScene::~CTestScene()
{
	ReleaseObjects();
}

void CTestScene::Update()
{
	m_background.Update();
	m_player->Update();

	m_enemys.Update();
	m_bullets.Update();
	m_bullets.CheckDelete();
}

void CTestScene::Draw(HDC hdc)
{
	m_background.Draw(hdc);
	m_player->Draw(hdc);

	m_enemys.Draw(hdc);
	m_bullets.Draw(hdc);
}

void CTestScene::ProcessInput()
{	
	if (IS_KEY_DOWN(VK_LEFT))  { m_player->Test(-1,0);}
	if (IS_KEY_DOWN(VK_RIGHT)) { m_player->Test(1,0); }
	if (IS_KEY_DOWN(VK_UP))    { m_player->Test(0,-1);}
	if (IS_KEY_DOWN(VK_DOWN))  { m_player->Test(0,1); }
}

LRESULT CTestScene::ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	Vector2d pos = { (double)(rand() % CLIENT_WIDTH),50 };
	Vector2d dropPosL = { 0, CLIENT_HEIGHT *0.5f };
	Vector2d dropPosR = { CLIENT_WIDTH, CLIENT_HEIGHT * 0.5f };
	//Vector2d pos = { m_player->GetPosition().x, 50 };

	switch (message)
	{
	case WM_KEYDOWN:
		if (wParam == VK_SPACE)
			m_bullets.AddObject(new CBullet());
		else if (wParam == 'n' || wParam == 'N')
			m_bullets.AddObject(new CNWayBullet(pos, m_player->GetPosition(), 7));
		else if (wParam == 'c' || wParam == 'C')
			m_bullets.AddObject(new CCircularBullet(pos, 50, m_player->GetPosition(), 10));
		else if (wParam == 'd' || wParam == 'D') {
			m_bullets.AddObject(new CDropBullet(dropPosL, { 3, -10 }));
			m_bullets.AddObject(new CDropBullet(dropPosR, { -3, -10 }));
		}
		else if (wParam == 'm' || wParam == 'M') {
			m_bullets.AddObject(new CTraceBullet(m_player, pos));
		}
		else if (wParam == 'r' || wParam == 'R') {
			m_bullets.AddObject(new CRapidBullet(pos));
			m_bullets.AddObject(new CRapidBullet(pos, m_player->GetPosition()));
		}
		else if (wParam == 's' || wParam == 'S') {
			m_bullets.AddObject(new CSplitBullet(pos, m_player->GetPosition()));
		}
		else if (wParam == 't' || wParam == 'T') {
			m_bullets.AddObject(new CTraceBullet(m_player, pos));
		}
		else if (wParam == 'e' || wParam == 'E') {
			m_bullets.AddObject(new CExtensionBullet(pos, 50, 10));
		}
		else if (wParam == 'q' || wParam == 'Q') {
			m_enemys.AddObject(new CSimpleShooter());
		}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void CTestScene::BuildObjects()
{
	m_player = new CPlayer;
}

void CTestScene::ReleaseObjects()
{
}
