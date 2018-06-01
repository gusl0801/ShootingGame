#pragma once
#include "CGameObject.h"
#include "CObjectManager.h"
#include "CBullet.h"

#define ENEMY_SPEED 5

class CEnemy : public CGameObject
{
public:
	CEnemy();
	~CEnemy();

	virtual void Update();
	virtual void Draw(HDC hdc);
	virtual void ProcessCommand() {}

	virtual bool IsDelete() { return false; }

	void Test(int x, int y) { m_position.x += x; m_position.y += y; }

private:
	int m_width;
	int m_height;
	int m_direction;

	CImage m_image;

	int shape = 0;
	bool isRight = true;
	CCounter counter;

protected:
	void SimpleMove();
	void Attack();
};

