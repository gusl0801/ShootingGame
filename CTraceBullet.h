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

	virtual void ProcessCommand() {}

	virtual bool IsDelete() { return m_isDelete > 100; }

private:
	void TraceTarget();
	void Move() { m_position += m_direction * BULLET_SPEED; }

	CGameObject * m_target;
	int m_count;
	int m_isDelete;
};

