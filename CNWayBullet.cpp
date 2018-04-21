#include "stdafx.h"
#include "CNWayBullet.h"

double CNWayBullet::LIMIT_ANGLE = 30;

CNWayBullet::CNWayBullet(const Vector2d &position, const Vector2d target, int nWay)
{
	if (nWay <= 0)
		return;
	
	double angle, div;
	Vector2d direction = target - position;
	direction.Normalize();

	if (nWay % 2 == 0) { // 礎熱檣 唳辦
		div = nWay * 0.5f;
	}
	else { // �汝鶺� 唳辦
		div = (nWay - 1) * 0.5f;
		m_bullets.emplace_back(new CBullet(position, direction));
	}

	angle = LIMIT_ANGLE / div;

	for (int i = 1; i <= div; ++i) {
		m_bullets.emplace_back(new CBullet(position, direction.Rotate(angle * i)));
		m_bullets.emplace_back(new CBullet(position, direction.Rotate(-angle * i)));
	}
}


CNWayBullet::~CNWayBullet()
{
	m_bullets.clear();
}

void CNWayBullet::Update()
{
	for (CBullet *bullet : m_bullets)
		bullet->Update();
}

void CNWayBullet::Draw(HDC hdc)
{
	for (CBullet *bullet : m_bullets)
		bullet->Draw(hdc);
}
