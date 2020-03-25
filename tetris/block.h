#pragma once
#include "point.h"
#include "GameManager.h"

#define BLOCK_SIZE 4
#define BLOCK_EXAMPLE_SIZE 7


const Point blockExample[BLOCK_EXAMPLE_SIZE][BLOCK_SIZE][BLOCK_SIZE] =	//2번째는 방향
{
	//ㅁㅁㅁㅁ
		{
		{ { 0, 5 }, { 0, 6 }, { 0, 7 }, { 0, 8 } },
		{ { -2, 6 }, { -1, 6 }, { 0, 6 }, { 1, 6 } },
		{ { 0, 5 }, { 0, 6 }, { 0, 7 }, { 0, 8 } },
		{ { -2, 6 }, { -1, 6 }, { 0, 6 }, { 1, 6 } }
		},
	//    ㅁ 수정완료
	//ㅁㅁㅁ
		{
			{ { -1, 8 }, { 0, 6 }, { 0, 7 }, { 0, 8 } },
			{ { -1, 7 }, { 0, 7 }, { 1, 7 }, { 1, 8 } },
			{ { 0, 6 }, { 0, 7 }, { 0, 8 }, { 1, 6 } },
			{ { -1, 6 }, { -1, 7 }, { 0, 7 }, { 1, 7 } }
		},
	//  ㅁㅁ
	//ㅁㅁ
	{
		{ { 0, 7 }, { 0, 8 }, { 1, 6 }, { 1, 7 } },
		{ { -1, 6 }, { 0, 6 }, { 0, 7 }, { 1, 7 } },
		{ { 0, 7 }, { 0, 8 }, { 1, 6 }, { 1, 7 } },
		{ { -1, 6 }, { 0, 6 }, { 0, 7 }, { 1, 7 } }
	},
	//ㅁㅁ
	//  ㅁㅁ
	{
		{ { 0, 6 }, { 0, 7 }, { 1, 7 }, { 1, 8 } },
		{ { -1, 8 }, { 0, 8 }, { 0, 7 }, { 1, 7 } },
		{ { 0, 6 }, { 0, 7 }, { 1, 7 }, { 1, 8 } },
		{ { -1, 8 }, { 0, 8 }, { 0, 7 }, { 1, 7 } }
	},
	//ㅁ
	//ㅁㅁㅁ
	{
		{ { 0, 6 }, { 1, 6 }, { 1, 7 }, { 1, 8 } },
		{ { -1, 8 }, { -1, 7 }, { 0, 7 }, { 1, 7 } },
		{ { -1, 6 }, { -1, 7 }, { -1, 8 }, { 0, 8 } },
		{ { -1, 7 }, { 0, 7 }, { 1, 7 }, { 1, 6 } }
	},
	//ㅁㅁ
	//ㅁㅁ
	{
		{ { 0, 6 }, { 0, 7 }, { 1, 6 }, { 1, 7 } },
		{ { 0, 6 }, { 0, 7 }, { 1, 6 }, { 1, 7 } },
		{ { 0, 6 }, { 0, 7 }, { 1, 6 }, { 1, 7 } },
		{ { 0, 6 }, { 0, 7 }, { 1, 6 }, { 1, 7 } }
	}
};

//타일블록 클래스
class Block
{
private :
	Point blockPosition[BLOCK_SIZE][BLOCK_SIZE];	//블록 하나당 4개의 방향 * 각 칸의 좌표
	int direction;
	int shape;
	Point movePoint;	//blockPosition 위치에서부터 움직인 값을 저장
	Point StartPoint;

public :
	Block(int dir=0, int sh=0);

	void rotate();
	
	void setNextBlockPosition(Point f);

	void printCurrentBlock();

	void blockMove(int dir);

	bool isWall(Point p);
};