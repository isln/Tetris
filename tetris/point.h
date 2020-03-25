#pragma once

class Point
{
public :
	Point(int inputX = 0, int inputY = 0);

	int getX();
	int getY();
	void setX(int inputX);
	void setY(int inputY);
	int getMaxX(Point p);
	int getMaxY(Point p);

	//연산자 오버로딩
	Point operator=(const Point& p)
	{
		x = p.x;
		y = p.y;

		return Point(x, y);
	}

	Point operator+(const Point& p)
	{
		//x += p.x;
		//y += p.y;

		return Point(x+p.x, y+p.y);
	}

	Point operator-(const Point& p)
	{
		x -= p.x;
		y -= p.y;

		return Point(x, y);
	}

private :
	int x;
	int y;
};