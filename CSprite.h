#pragma once

#include "CSprite.h"

enum class AnimationState
{
	None = 0,
	Idle = 11,
	Move = 21,
};

class CSprite
{
public:
	CSprite();
	~CSprite();

	void ChangeState(AnimationState state) { m_state = state; }

public:
	AnimationState m_state;
};

