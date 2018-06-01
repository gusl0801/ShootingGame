#include "stdafx.h"
#include "Collidable.h"

Collidable::~Collidable() {}

//bool Collidable::IsCollide(const Collidable &other)
//{
//	/*if (other.radius == NULL)
//		if (((x1 < other.x2) && (y2 > other.y1)) ||
//			((x1 < other.x2) && (y1 < other.y2)) ||
//			((x2 > other.x1) && (y2 > other.y1)) ||
//			((x2 > other.x1) && (y1 < other.y2))) {
//			cout << "Collide!" << endl;
//			return TRUE;
//		}
//		else
//			return FALSE;*/
//	/*else
//		if ((sqrt((a.x - b.x1)*(a.x - b.x1) + (a.y - b.y1)*(a.y - b.y1)) < a.radius) ||
//			(sqrt((a.x - b.x1)*(a.x - b.x1) + (a.y - b.y2)*(a.y - b.y2)) < a.radius) ||
//			(sqrt((a.x - b.x2)*(a.x - b.x2) + (a.y - b.y1)*(a.y - b.y1)) < a.radius) ||
//			(sqrt((a.x - b.x2)*(a.x - b.x2) + (a.y - b.y2)*(a.y - b.y2)) < a.radius)){
//			cout << "Collide!" << endl;
//			return TRUE;
//		}
//		else
//			return FALSE;
//	
//	////////////////////////////////////
//	a==bullet(x, y, radius)
//	b==cplayer(x, y)
//		x, y == center point
//	
//	*/
//	return false;
//}