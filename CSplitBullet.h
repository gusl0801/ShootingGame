#pragma once
#include "CBullet.h"
class CSplitBullet :
	public CBullet
{
public:
	CSplitBullet();
	~CSplitBullet();

	virtual void Update();
	virtual void Draw(HDC hdc);

	virtual void ProcessCommand() {}

	virtual bool IsDelete() { return m_position.y > CLIENT_HEIGHT; }
};

