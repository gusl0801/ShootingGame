#include "stdafx.h"
#include "CGameObject.h"


CGameObject::CGameObject()
{
	m_renderer = new CSprite();
}


CGameObject::~CGameObject()
{
	SAFE_DELETE(m_renderer);
	SAFE_DELETE(m_curState);
}
