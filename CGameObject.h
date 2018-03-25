#pragma once

#include "CSprite.h"
#include "Vector2D.h"

class CState;

class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();

	// ��ӹ޴� Ŭ�������� �������̵��� �ʿ��� �Լ���
	virtual void Update() = 0;
	virtual void Draw(HDC hdc) = 0;

	virtual void ProcessCommand() = 0;

	virtual bool IsDelete() = 0;

	// ��ӹ޴� Ŭ�������� �������̵� �� �ʿ䰡 ���� �Լ���	
	CState* GetState() const { return m_curState; }

	void ChangeSprite(AnimationState state) { m_renderer->ChangeState(state); }

private:
	Vector2i m_position;

	CState *m_curState;
	queue<CState*> m_stateQueue;

	CSprite *m_renderer;
};

