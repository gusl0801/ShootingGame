#include "stdafx.h"
#include "CSplitBullet.h"
#include "CCircularBullet.h"

const int CSplitBullet::SPLIT_LIMIT = 100;
const int CSplitBullet::SPLIT_NUM = 10;
const double CSplitBullet::SPLIT_RADIUS = 30;

CSplitBullet::CSplitBullet(const Vector2d &position, const Vector2d &targetPos)
{
	m_position = position;
	m_targetPos = targetPos;

	m_direction = targetPos - position;
	m_direction.Normalize();

	m_isSplit = false;
	m_splitGage = 0;
}
CSplitBullet::~CSplitBullet()
{
	SAFE_DELETE(m_splitedBullet);
}

void CSplitBullet::Update()
{
	if (!m_isSplit) {
		Move();

		++m_splitGage;
		if (m_splitGage > SPLIT_LIMIT) {
			m_isSplit = true;
			m_splitGage = 0;

			Split();
		}
	}
	else {
		m_splitedBullet->Update();
	}
}

void CSplitBullet::Draw(HDC hdc)
{
	if (!m_isSplit) {
		DrawSimple(hdc);
	}
	else {
		m_splitedBullet->Draw(hdc);
	}
}

void CSplitBullet::Split()
{
	Vector2d target = m_direction * CLIENT_HEIGHT;
	m_splitedBullet = new CCircularBullet(m_position, SPLIT_RADIUS, target, SPLIT_NUM);
}