#include "stdafx.h"
#include "CGameObject.h"


CGameObject::CGameObject()
{

}


CGameObject::~CGameObject()
{
	SAFE_DELETE(m_curState);
}
