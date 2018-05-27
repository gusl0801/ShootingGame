#pragma once
#include "CGameObject.h"
class CPlayer :
	public CGameObject
{
public:
	CPlayer();
	~CPlayer();

	virtual void Update();
	virtual void Draw(HDC hdc);
	virtual void ProcessCommand() {}

	virtual bool IsDelete() { return false; }

	void Test(int x, int y) { m_position.x += x; m_position.y += y; }

private:
	int m_width;
	int m_height;
};

