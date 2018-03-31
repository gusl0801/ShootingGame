#pragma once
#include "CScene.h"
#include "CSoundPlayer.h"

/*
�ۼ��� : 2018-03-13
���� : Ÿ��Ʋ Scene�Դϴ�. 
	   �����ϰ� ȭ�鿡 CTitleScene�� ����ϰ� 
	   ����ϴ� �ؽ�Ʈ�� ��ġ�� �¿��� ��� �����̵��� �Ͽ�����
	   �����̽��ٸ� ������ MainScene���� ��ȯ�մϴ�.
*/

class CTitleScene :
	public CScene
{
public:
	CTitleScene();
	~CTitleScene();

	virtual void Update();
	virtual void Draw(HDC hdc);
	virtual void ProcessInput();

	virtual LRESULT CALLBACK ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	
private:
	virtual void BuildObjects() {}
	virtual void ReleaseObjects() {}

private:
	int m_textPosX;
	int m_textPosY;

	bool m_isMoveRight;

	LPCTSTR m_text;
	USHORT m_textLen;

	CImage m_background;
};

