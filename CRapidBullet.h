#pragma once
#include "CBullet.h"
class CRapidBullet :
	public CBullet
{
	enum class PHASE : int
	{
		NONE = 0,
		WARN = 1,
		ATTACK = 2,
		COUNT = 3
	};
public:
	CRapidBullet(const Vector2d &position);
	CRapidBullet(const Vector2d &position, const Vector2d target);
	~CRapidBullet();
	
	virtual void Update();
	virtual void Draw(HDC hdc);

	virtual bool IsDelete() { return m_position.y > CLIENT_HEIGHT; }

private:
	void updatePhaseWarn();
	void updatePhaseAttack();

	void drawPhaseWarn(HDC hdc);
	void drawPhaseAttack(HDC hdc);

	void init();
	void Move() { m_position += (m_direction * BULLET_SPEED * 3); }

	typedef void(CRapidBullet::*updater)();
	typedef void(CRapidBullet::*drawer)(HDC);
	map<PHASE,updater> m_updater;
	map<PHASE,drawer> m_drawer;

	Vector2d m_endPos;
	PHASE m_phase;
	CCounter m_warnCounter = 0;
};

