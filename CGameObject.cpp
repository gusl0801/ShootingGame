#include "stdafx.h"
#include "CGameObject.h"


CGameObject::CGameObject()
{
	m_renderer = new CSprite();

	/*
	if ((object == player) || (object == rectangle)
		pos = Collide(x1, x2, y1, y2);
	else if (object == circle)
		pos = Collide(x1, x2, y1, y2, radius);
	*/
}


CGameObject::~CGameObject()
{
	SAFE_DELETE(m_renderer);
	SAFE_DELETE(m_curState);
}
