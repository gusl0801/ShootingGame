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
	virtual void ProcessCommand() {}

	virtual bool IsDelete() { return false; }

private:
	void Move();
	void Attack();

	void SpriteUpdate();
	void AttackUpdate();
	
	int m_width;
	int m_height;
	int m_direction;

	CImage m_image;

	int shape = 0;
	bool isRight = true;
	CCounter spriteCounter;
	CCounter attackCounter;

	CObjectManager m_bullets;
};


