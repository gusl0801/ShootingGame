#include "stdafx.h"
#include "Collide.h"

Collide::~Collide() {}

bool Collide::IsCollide(Collide bullet)
{
	if (bullet.radius == NULL)
		if (((x1 < bullet.x2) && (y2 > bullet.y1)) ||
			((x1 < bullet.x2) && (y1 < bullet.y2)) ||
			((x2 > bullet.x1) && (y2 > bullet.y1)) ||
			((x2 > bullet.x1) && (y1 < bullet.y2))) {
			cout << "Collide!" << endl;
			return TRUE;
		}
		else
			return FALSE;
	/*else
		if ((sqrt((a.x - b.x1)*(a.x - b.x1) + (a.y - b.y1)*(a.y - b.y1)) < a.radius) ||
			(sqrt((a.x - b.x1)*(a.x - b.x1) + (a.y - b.y2)*(a.y - b.y2)) < a.radius) ||
			(sqrt((a.x - b.x2)*(a.x - b.x2) + (a.y - b.y1)*(a.y - b.y1)) < a.radius) ||
			(sqrt((a.x - b.x2)*(a.x - b.x2) + (a.y - b.y2)*(a.y - b.y2)) < a.radius)){
			cout << "Collide!" << endl;
			return TRUE;
		}
		else
			return FALSE;
	
	////////////////////////////////////
	a==bullet(x, y, radius)
	b==cplayer(x, y)
		x, y == center point
	
	*/

}