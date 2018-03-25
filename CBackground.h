#pragma once
#define SCROLLING_SPEED 5

class CBackground 
{
public:
	CBackground();
	~CBackground();

	void Update();
	void Draw(HDC hdc);

private:
	CImage m_image;

	Vector2i m_position;

	Viewport m_viewport;

	int m_gap;
};

