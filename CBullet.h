#pragma once
#include "CGameObject.h"

#define BULLET_SPEED 5

class CBullet : public CGameObject
{
public:
	CBullet();
	CBullet(const Vector2d &position, const Vector2d &direction);
	virtual ~CBullet();

	virtual void Update();
	virtual void Draw(HDC hdc);

	virtual void ProcessCommand() {}

	virtual bool IsDelete() { return m_position.y > CLIENT_HEIGHT; }

	void Rotate(const Vector2d &center, int angle, int radius);

protected:
	void DrawSimple(HDC hdc);

	Vector2d m_direction;

private:
	void Move() { m_position += m_direction * BULLET_SPEED; }
};

