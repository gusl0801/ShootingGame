#pragma once

//1초는 60프레임
//1분은 3600프레임
//1시간은 216000프레임
 

class CCounter
{
private:
	double m_count;
	double m_limit;

public:
	CCounter() { m_count = 0, m_limit = 0; }
	CCounter(double limit);
	~CCounter();

	static double SecondToFrame(double second) { return second * FPS; }
	static double MinuteToFrame(double minute) { return minute * FPS * FPS; }
	static double HourToFrame(double hour) { return hour * FPS * FPS * FPS; }

	static double FrameToSecond(double frame) { return frame * (1 / FPS); }
	static double FrameToMinute(double frame) { return frame * (1 / FPS / FPS); }
	static double FrameToHour(double frame) { return frame * (1 / FPS / FPS / FPS); }

	void Increase() { m_count = min(m_limit, m_count + 1); }
	void Decrease() { m_count = max(0, m_count - 1); }

	void Add(double value) { m_count = min(m_limit, m_count + value); }
	void Sub(double value) { m_count = max(0, m_count - value); }
	
	bool isLimit() const { return m_limit == m_count; }
	void SetLimit(double limit) { m_limit = limit; }

	void ResetCount() { m_count = 0.0f; }
};


