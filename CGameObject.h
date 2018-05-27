#pragma once

#include "CSprite.h"
#include "Vector2D.h"
#include "CCounter.h"
#include "Collidable.h"

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

	bool IsCollide(const CGameObject &subject) const { return m_boundary->IsCollide(*subject.GetBoundary()); }
	//virtual void SolveCollision(const CGameObject &subject) = 0;

	// ��ӹ޴� Ŭ�������� �������̵� �� �ʿ䰡 ���� �Լ���	
	CState* GetState() const { return m_curState; }
	Vector2d GetPosition() const { return m_position;}
	Collidable* GetBoundary() const { return m_boundary; }

	void ChangeSprite(AnimationState state) { m_renderer->ChangeState(state); }
	
protected:
	bool IsInScreen() const { return m_boundary->IsInScreen(); }

	CSprite * m_renderer;

	Vector2d m_position;
	
	Collidable *m_boundary;

	CState *m_curState;
	queue<CState*> m_stateQueue;
};

