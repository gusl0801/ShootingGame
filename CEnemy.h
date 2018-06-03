#pragma once
#include "CGameObject.h"
#include "CObjectManager.h"
#include "CBullet.h"

#define ENEMY_SPEED CSpeed::PixelPerSecond(CLIENT_WIDTH, 5);

class CEnemy : public CGameObject
{
public:
	virtual ~CEnemy();

protected:
	void SimpleMove() { m_position += m_direction * ENEMY_SPEED; }

private:
	int m_width;
	int m_height;
	int m_direction;

	CImage m_image;

	int shape = 0;
	bool isRight = true;
	CCounter counter;
};

