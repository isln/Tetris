#pragma once
#include "point.h"
#include "GameManager.h"

#define BLOCK_SIZE 4
#define BLOCK_EXAMPLE_SIZE 7


const Point blockExample[BLOCK_EXAMPLE_SIZE][BLOCK_SIZE][BLOCK_SIZE] =	//2腰属澗 号狽
{
	//けけけけ
		{
		{ { 0, 5 }, { 0, 6 }, { 0, 7 }, { 0, 8 } },
		{ { -2, 6 }, { -1, 6 }, { 0, 6 }, { 1, 6 } },
		{ { 0, 5 }, { 0, 6 }, { 0, 7 }, { 0, 8 } },
		{ { -2, 6 }, { -1, 6 }, { 0, 6 }, { 1, 6 } }
		},
	//    け 呪舛刃戟
	//けけけ
		{
			{ { -1, 8 }, { 0, 6 }, { 0, 7 }, { 0, 8 } },
			{ { -1, 7 }, { 0, 7 }, { 1, 7 }, { 1, 8 } },
			{ { 0, 6 }, { 0, 7 }, { 0, 8 }, { 1, 6 } },
			{ { -1, 6 }, { -1, 7 }, { 0, 7 }, { 1, 7 } }
		},
	//  けけ
	//けけ
	{
		{ { 0, 7 }, { 0, 8 }, { 1, 6 }, { 1, 7 } },
		{ { -1, 6 }, { 0, 6 }, { 0, 7 }, { 1, 7 } },
		{ { 0, 7 }, { 0, 8 }, { 1, 6 }, { 1, 7 } },
		{ { -1, 6 }, { 0, 6 }, { 0, 7 }, { 1, 7 } }
	},
	//けけ
	//  けけ
	{
		{ { 0, 6 }, { 0, 7 }, { 1, 7 }, { 1, 8 } },
		{ { -1, 8 }, { 0, 8 }, { 0, 7 }, { 1, 7 } },
		{ { 0, 6 }, { 0, 7 }, { 1, 7 }, { 1, 8 } },
		{ { -1, 8 }, { 0, 8 }, { 0, 7 }, { 1, 7 } }
	},
	//け
	//けけけ
	{
		{ { 0, 6 }, { 1, 6 }, { 1, 7 }, { 1, 8 } },
		{ { -1, 8 }, { -1, 7 }, { 0, 7 }, { 1, 7 } },
		{ { -1, 6 }, { -1, 7 }, { -1, 8 }, { 0, 8 } },
		{ { -1, 7 }, { 0, 7 }, { 1, 7 }, { 1, 6 } }
	},
	//けけ
	//けけ
	{
		{ { 0, 6 }, { 0, 7 }, { 1, 6 }, { 1, 7 } },
		{ { 0, 6 }, { 0, 7 }, { 1, 6 }, { 1, 7 } },
		{ { 0, 6 }, { 0, 7 }, { 1, 6 }, { 1, 7 } },
		{ { 0, 6 }, { 0, 7 }, { 1, 6 }, { 1, 7 } }
	}
};

//展析鷺系 適掘什
class Block
{
private :
	Point blockPosition[BLOCK_SIZE][BLOCK_SIZE];	//鷺系 馬蟹雁 4鯵税 号狽 * 唖 牒税 疎妊
	int direction;
	int shape;
	Point movePoint;	//blockPosition 是帖拭辞採斗 崇送昔 葵聖 煽舌
	Point StartPoint;

public :
	Block(int dir=0, int sh=0);

	void rotate();
	
	void setNextBlockPosition(Point f);

	void printCurrentBlock();

	void blockMove(int dir);

	bool isWall(Point p);
};