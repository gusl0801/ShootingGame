#pragma once

/*
�ۼ��� : 2018-03-12
���� : chrono�Լ��� �̿��Ͽ� ���� �Լ� ȣ�� �ð��� 
       �̹� �Լ� ȣ�� �ð������� ���̸� ����ϴ� ����� �����մϴ�.
*/


class CTimer
{
public:
	CTimer();
	virtual ~CTimer();

	// ���� �Լ� ȣ�� �ð��� ���� �Լ� ȣ�� �ð� �����մϴ�.
	virtual void Tick() {
		m_curTime = chrono::system_clock::now(); 
		m_timeElapsed = m_curTime - m_prevTime;
		m_prevTime = m_curTime;
		m_timeLag += m_timeElapsed.count();
	}

	// ���� �Լ� ȣ�� �ð��� ���� �Լ� ȣ�� �ð� ������ ���̸� ����Ͽ� ��ȯ�մϴ�.
	double GetTimeLag() const { return m_timeLag; }					// update���� ��ȭ��
	double GetTimeElapsed() const { return m_timeElapsed.count(); }	// update���� ��ȭ����

	void UpdateTimeLag(double timeLag) { m_timeLag += timeLag; }

private:
	chrono::system_clock::time_point m_curTime;
	chrono::system_clock::time_point m_prevTime;
	chrono::duration<double> m_timeElapsed;
	double m_timeLag;
};

/*
�ۼ��� : 2018-03-13
���� : CTimerŬ������ ��ӹ޾� �θ�Ŭ������ �⺻ ����� �����ϰ�
	   �߰������� FPS�� ����ϴ� ����� �����մϴ�.
*/
class CFPSTimer : public CTimer
{
public:
	CFPSTimer();
	
	//virtual void Tick() override final { CTimer::Tick(); m_prevFPSTime = chrono::system_clock::now(); }

	double GetFrameRate();
	
private:
	// FPS�� �����մϴ�.
	void Update();

	chrono::system_clock::time_point m_prevFPSTime;
	chrono::duration<double> m_FPSTimeElapsed;

	double m_timeSum;
	int m_nSumCount;

	double m_fps;
};

