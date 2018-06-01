#pragma once
#include "CBullet.h"
class CExtensionBullet :
	public CBullet
{
public:
	CExtensionBullet(const Vector2d &center, int radius, int num);
	~CExtensionBullet();

	virtual void Update() { Move(); Extense(); }
	virtual void Draw(HDC hdc) { for (CBullet *bullet : m_bullets) bullet->Draw(hdc); }

	virtual bool IsDelete() override { return false; }// { return m_boundary->IsInScreen(); }

private:
	void Move() { SimpleMove(); }
	void Extense();

	static const double RADIUS_INC_VALUE;
	static const Vector2d CLIENT_CENTER;

	vector<CBullet*> m_bullets;
	vector<int> m_angles;

	double m_radius;
};

