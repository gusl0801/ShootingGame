#pragma once
#include "CGameObject.h"
#include "CObjectManager.h"

class CPlayer :
	public CGameObject
{
public:
	CPlayer();
	~CPlayer();

	virtual void Update();
	virtual void Draw(HDC hdc);

	virtual bool IsDelete() { return false; }

	void Move(const Point2D &direction);
	void Attack();

private:
	int m_width;
	int m_height;

	CImage m_image;

	int m_shape = 0;
	bool m_isRight = true;
	CCounter counter;

	CObjectManager m_bullets;
};

