#pragma once

#include "CBullet.h"

class CDropBullet : public CBullet
{
public:
	CDropBullet();
	~CDropBullet();

	virtual void Update();
	virtual void Draw(HDC hdc);

	virtual void ProcessCommand() {}

	virtual bool IsDelete() { return m_position.y > CLIENT_HEIGHT; }
};

