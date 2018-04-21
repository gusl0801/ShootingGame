#pragma once
#include "CBullet.h"

class CCircularBullet :
	public CBullet
{
public:
	CCircularBullet(const Vector2d &center, int radius, const Vector2d &target, int num);
	~CCircularBullet();

	virtual void Update();
	virtual void Draw(HDC hdc);

	virtual void ProcessCommand() {}

	virtual bool IsDelete() { return false; }// m_position.y > CLIENT_HEIGHT;}

private:
	static const int ANGLE_INC_VALUE;
	vector<CBullet*> m_bullets;
	vector<int>	m_angles;
	int m_radius;
};

