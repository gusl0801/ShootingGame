#pragma once

#include "Vector2D.h"
#include "CCounter.h"
#include "Collidable.h"
#include "CSprite.h"


#define DIR_LEFT  Point2D {-1, 0 }
#define DIR_RIGHT Point2D { 1, 0 }
#define DIR_UP    Point2D { 0,-1 }
#define DIR_DOWN  Point2D { 0, 1 }

class CState;

class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();

	// 상속받는 클래스에서 오버라이딩이 필요한 함수들
	virtual void Update() = 0;
	virtual void Draw(HDC hdc) = 0;

	virtual bool IsDelete() = 0;

	bool IsCollide(const CGameObject &subject) const { return m_boundary->IsCollide(*subject.GetBoundary()); }
	
	// 상속받는 클래스에서 오버라이딩 할 필요가 없는 함수들	
	CState* GetState() const { return m_curState; }
	Vector2d GetPosition() const { return m_position;}
	Collidable* GetBoundary() const { return m_boundary; }

	void SpriteUpdate(int variation, bool yUpdate) { m_sprite->Add(variation); }
protected:
	bool IsInScreen() const { return m_boundary->IsInScreen(); }

	Vector2d m_position;
	
	Collidable *m_boundary;

	CState *m_curState;
	queue<CState*> m_stateQueue;

	CSprite * m_sprite;
};

