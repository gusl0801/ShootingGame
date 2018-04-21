#pragma once
#include "CBullet.h"


class CNWayBullet : public CBullet
{
public:
	CNWayBullet(const Vector2d &position, const Vector2d target, int nWay);
	~CNWayBullet();

	virtual void Update();
	virtual void Draw(HDC hdc);

	virtual void ProcessCommand() {}

	virtual bool IsDelete() { return false; }// m_position.y > CLIENT_HEIGHT;}

private:
	//void Move() { m_position += (m_direction * BULLET_SPEED); }

	static double LIMIT_ANGLE;
	vector<CBullet*> m_bullets;
};

