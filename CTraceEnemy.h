#pragma once
#include "CEnemy.h"

class CTraceEnemy :
	public CEnemy
{
public:
	CTraceEnemy();
	CTraceEnemy(CGameObject *target);
	~CTraceEnemy();

	virtual void Update();
	virtual void Draw(HDC hdc);

	virtual bool IsDelete() { return false; }

private:
	void Move();
	void Attack();

	void TraceTarget();

	void SpriteUpdate();
	void AttackUpdate();

	int m_width;
	int m_height;

	CImage m_image;

	int m_shape = 2;
	bool m_isRight = true;

	CCounter m_traceCounter;
	CCounter spriteCounter;
	CCounter attackCounter;

	CGameObject *m_target;

	CObjectManager m_bullets;
};


