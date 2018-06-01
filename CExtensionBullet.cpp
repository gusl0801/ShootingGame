#include "stdafx.h"
#include "CExtensionBullet.h"

const Vector2d CExtensionBullet::CLIENT_CENTER = { CLIENT_WIDTH *0.5f, CLIENT_HEIGHT *0.5f };
const double CExtensionBullet::RADIUS_INC_VALUE = CLIENT_CENTER.Length() / CCounter::SecondToFrame(5);

CExtensionBullet::CExtensionBullet(const Vector2d &center, int radius, int num)
{
	Vector2d pos;

	m_position = center;
	m_direction = { 0,1 };
	m_direction.Normalize();

	for (int i = 0; i <= num; ++i) {
		pos.x = center.x + radius * cos(DegToRad((ANGLE / num) * i));
		pos.y = center.y + radius * sin(DegToRad((ANGLE / num) * i));
		m_bullets.emplace_back(new CBullet(pos, m_direction));
		m_angles.emplace_back((ANGLE / num) * i);
	}
}


CExtensionBullet::~CExtensionBullet()
{
}

void CExtensionBullet::Extense()
{
	m_radius += RADIUS_INC_VALUE;

	for (int i = 0; i < m_bullets.size(); ++i) {
		m_bullets[i]->Rotate(m_position, m_angles[i], m_radius);
	}
}
