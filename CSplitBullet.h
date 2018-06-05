#pragma once
#include "CBullet.h" 

class CCircularBullet;

class CSplitBullet :
	public CBullet
{
public:
	CSplitBullet(const Vector2d &position, const Vector2d &targetPos);

	~CSplitBullet();

	virtual void Update();
	virtual void Draw(HDC hdc);

	virtual bool IsDelete() { return m_position.y > CLIENT_HEIGHT; }

private:
	void Move() { m_position += (m_direction * BULLET_SPEED); }
	void Split();

	static const int SPLIT_NUM;
	static const double SPLIT_RADIUS;

	CCounter m_splitGage;
	bool m_isSplit;

	CCircularBullet *m_splitedBullet;
	Vector2d m_targetPos;
};
