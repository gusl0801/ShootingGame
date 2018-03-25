#include "stdafx.h"
#include "CTimer.h"

#define FPS_UPDATE_LIMIT 0.5

CTimer::CTimer()
{
	m_curTime = chrono::system_clock::now();
	m_prevTime = chrono::system_clock::now();
}


CTimer::~CTimer()
{
}

CFPSTimer::CFPSTimer()
{
	m_prevFPSTime = chrono::system_clock::now();
	m_timeSum = 0;
	m_fps = 0;
	m_nSumCount = 0;
}

double CFPSTimer::GetFrameRate()
{
	// ������ �ð��� ��� �ߴٸ�
	if (m_FPSTimeElapsed.count() > FPS_UPDATE_LIMIT)
	{
		// fps ����
		Update();
	}
	else // ��� ���� �ʾҴٸ�
	{
		// ��� �ð� ����
		m_FPSTimeElapsed = std::chrono::system_clock::now() - m_prevFPSTime;

		m_timeSum += GetTimeElapsed();
		++m_nSumCount;
	}
	return m_fps;
}

void CFPSTimer::Update()
{
	m_fps = 1.0f / (m_timeSum / m_nSumCount);
	m_timeSum = 0;
	m_nSumCount = 0;

	m_prevFPSTime = std::chrono::system_clock::now();
	m_FPSTimeElapsed = m_prevFPSTime - m_prevFPSTime;
}
