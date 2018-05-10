#include "stdafx.h"
#include "CCircularBullet.h"

const int CCircularBullet::ANGLE_INC_VALUE = 1;

CCircularBullet::CCircularBullet(const Vector2d &center, int radius, const Vector2d &target,int num)
	:m_radius(radius)
{
	Vector2d pos;

	m_position = center;
	m_direction = target - center;
	m_direction.Normalize();

	for (int i = 0; i < num; ++i) { 	
		pos.x = center.x + radius * cos(DegToRad((ANGLE / num) * i));
		pos.y = center.y + radius * sin(DegToRad((ANGLE / num) * i));
		m_bullets.emplace_back(new CBullet(pos, m_direction));
		m_angles.emplace_back((ANGLE / num) * i);
	}
}


CCircularBullet::~CCircularBullet()
{
	m_bullets.clear();
	m_bullets.clear();
}

void CCircularBullet::Update()
{
	for (int i = 0; i < m_bullets.size(); ++i) {
		m_bullets[i]->Rotate(m_position, m_angles[i], m_radius);
	}

	for (int i = 0; i < m_angles.size(); ++i) {
		m_angles[i] += ANGLE_INC_VALUE;
		if (m_angles[i] > ANGLE)
			m_angles[i] -= ANGLE;
	}

	m_position += (m_direction * BULLET_SPEED);
	//m_radius += 1;
	//if (m_radius > 150)
	//	m_radius -= 1;
}

void CCircularBullet::Draw(HDC hdc)
{
	for (CBullet *bullet : m_bullets)
		bullet->Draw(hdc);
}
