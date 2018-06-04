#pragma once
#include "CGameObject.h"
#include "CObjectManager.h"
#include "CBullet.h"

#define ENEMY_SPEED CSpeed::PixelPerSecond(3, CLIENT_WIDTH);

class CEnemy : public CGameObject
{
public:
	virtual ~CEnemy();

protected:
	void SimpleMove() {	m_position += m_direction * ENEMY_SPEED; }
	Vector2d m_direction;
};

