#pragma once

#include "CBullet.h"

class CDropBullet : public CBullet
{
public:
	CDropBullet(const Vector2d &position, const Vector2d &speed);
	~CDropBullet();

	virtual void Update();
	virtual void Draw(HDC hdc);

	virtual void ProcessCommand() {}

	virtual bool IsDelete() { return m_position.y > CLIENT_HEIGHT; }

private:
	void Move() { m_position += m_direction; }

	static const double DROP_SPEED;
};

