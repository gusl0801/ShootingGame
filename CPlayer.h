#pragma once
#include "CGameObject.h"
class CPlayer :
	public CGameObject
{
public:
	CPlayer();
	~CPlayer();

	virtual void Update();
	virtual void Draw(HDC hdc);
	virtual void ProcessCommand() {}

	virtual bool IsDelete() { return false; }
};

