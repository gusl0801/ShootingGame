#pragma once

/*
�ۼ��� : 2018-03-13
���� : ���α׷� ���� ���� �۾������� �� ���� Scene���� ���� Ŭ�����Դϴ�.
*/

class CInput;

enum class SceneType
{
	TITLE = 0,
	MAIN = 11,
};

class CScene
{
public:
	virtual ~CScene();
	
	virtual void Update() = 0;
	virtual void Draw(HDC hdc) = 0;
	virtual void ProcessInput(CInput *input) = 0;
	
	virtual LRESULT CALLBACK ProcessWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;
	
	// �ش� �Լ��� ���ؼ� ���ο� ���� ������ �� �ֵ��� �մϴ�.
	template <class SceneName>
	static CScene* NewScene()
	{
		CScene *scene = new SceneName;
		
		//�ʿ��� �ʱ�ȭ�� �ִٸ� �� �������� ȣ���� �� �ֵ��� �մϴ�.

		return scene;
	}
protected:
	// NewScene�Լ��θ� Scene�� �����ϵ��� �����մϴ�.
	CScene() {}

	virtual void BuildObjects() = 0;
	virtual void ReleaseObjects() = 0;
};