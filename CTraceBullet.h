#pragma once

#include "CBullet.h"
class CTraceBullet :
	public CBullet
{
public:
	CTraceBullet(CGameObject *target, const Vector2d &position);
	~CTraceBullet();

	virtual void Update();
	virtual void Draw(HDC hdc);

	virtual bool IsDelete() { return m_deleteCounter.isLimit(); }

private:
	void TraceTarget();
	void Move() { m_position += m_direction * BULLET_SPEED; }

	CGameObject * m_target;
	CCounter m_traceCounter;
	CCounter m_deleteCounter;
};

