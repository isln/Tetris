#include "point.h"

Point::Point(int inputX, int inputY)
{
	x = inputX;
	y = inputY;
}

int Point::getX()
{
	return x; 
}

int Point::getY() 
{ 
	return y; 
}

void Point::setX(int inputX) { x = inputX; }

void Point::setY(int inputY) { y = inputY; }

int Point::getMaxX(Point p)
{
	if (p.getX() > x)
		return p.getX();
	else
		return x;
}

int Point::getMaxY(Point p)
{
	if (p.getY() > y)
		return p.getY();
	else
		return y;

}
