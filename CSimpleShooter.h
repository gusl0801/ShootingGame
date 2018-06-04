#pragma once
#include "CEnemy.h"
class CSimpleShooter :
	public CEnemy
{
public:
	CSimpleShooter();
	~CSimpleShooter();

	virtual void Update();
	virtual void Draw(HDC hdc);

	virtual bool IsDelete() { return false; }

private:
	void Move();
	void Attack();

	void SpriteUpdate();
	void AttackUpdate();
	
	int m_width;
	int m_height;

	CImage m_image;

	int m_shape = 2;
	bool m_isRight = true;
	CCounter spriteCounter;
	CCounter attackCounter;

	CObjectManager m_bullets;
};


