#pragma once
#include "CGameObject.h"

#define BULLET_SPEED 5

class CBullet : public CGameObject
{
public:
	CBullet();
	virtual ~CBullet();

	virtual void Update();
	virtual void Draw(HDC hdc);

	virtual void ProcessCommand() {}

	virtual bool IsDelete() { return m_position.y > CLIENT_HEIGHT; }

private:
	void Move() { m_position.y += BULLET_SPEED; }
};

