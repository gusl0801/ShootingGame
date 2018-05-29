#pragma once

#include "Vector2D.h"
#include "CCounter.h"
#include "Collidable.h"

class CState;

class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();

	// 상속받는 클래스에서 오버라이딩이 필요한 함수들
	virtual void Update() = 0;
	virtual void Draw(HDC hdc) = 0;

	virtual void ProcessCommand() = 0;

	virtual bool IsDelete() = 0;

	bool IsCollide(const CGameObject &subject) const { return m_boundary->IsCollide(*subject.GetBoundary()); }
	//virtual void SolveCollision(const CGameObject &subject) = 0;

	// 상속받는 클래스에서 오버라이딩 할 필요가 없는 함수들	
	CState* GetState() const { return m_curState; }
	Vector2d GetPosition() const { return m_position;}
	Collidable* GetBoundary() const { return m_boundary; }

protected:
	bool IsInScreen() const { return m_boundary->IsInScreen(); }

	Vector2d m_position;
	
	Collidable *m_boundary;

	CState *m_curState;
	queue<CState*> m_stateQueue;
};

