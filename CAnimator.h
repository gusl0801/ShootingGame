#pragma once

class CSprite;

class CAnimator
{
public:
	CAnimator();
	~CAnimator();

	void Load(LPCTSTR szAddress, const Point2D &segement, const Point2D &startPoint, const Point2D &size);
	void LoadFromFile(LPSTR szAddress);
	
	void Update();
	void Draw(HDC hdc);
private:
	vector <CSprite*> m_sprites;

	Point2D m_segement;
	Point2D m_imagePosition;
	Point2D m_imageSize;
};

