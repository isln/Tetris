#include <iostream>
#include "block.h"

/*
하나의 블록 객체가 하는 모든 일
이동, 회전 등등
*/
Block::Block(int dir, int sh)
{
	direction = dir;
	shape = sh;
	for (int i = 0; i < BLOCK_SIZE; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			blockPosition[i][j] = blockExample[shape][i][j];
 		}
	}
	StartPoint = Point(BOARDX + BW / 2 + 1, BOARDY + 1);
	movePoint = Point(0, 0) + StartPoint;	
}

void Block::rotate()
{
	textcolor(BoardColor);
	printCurrentBlock();
	
	if (direction == LEFT)
		direction = DOWN;
	else
		direction -= 1;
	
	textcolor(BlockColor);
	printCurrentBlock();
}

void Block::setNextBlockPosition(Point f)
{

}

void Block::printCurrentBlock()
{
	int x_loc, y_loc; 
	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		//x는 1칸으로 하면 겹치므로 출력시 최종적으로 * 2 해줘야함
		x_loc = (blockPosition[direction][i].getX() + movePoint.getX()) * 2;
		y_loc = blockPosition[direction][i].getY() + movePoint.getY();
		gotoxy(x_loc, y_loc);
		std::cout << "□";
	}
}

void Block::blockMove(int dir)
{
	Point temp;

	switch (dir)
	{
	case LEFT:
		temp = movePoint + Point(-1, 0);
		break;
	case RIGHT:
		temp = movePoint + Point(1, 0);
		break;
	case DOWN:
		temp = movePoint + Point(0, 1);
		break;
	case TEST:
		temp = movePoint;
		shape += 1;
		if (shape >= 6)
			shape = 0;
		for (int i = 0; i < BLOCK_SIZE; i++) {
			for (int j = 0; j < BLOCK_SIZE; j++) {
				blockPosition[i][j] = blockExample[shape][i][j];
			}
		}
		/* 벽에 닿는지 여부 체크해야함
		if(temp.getY == blockPosition[dir][BLOCK_SIZE-1]+BOARDY+BH)
		*/
		//왼쪽위가 0,0임
		break;
	}

	if (!isWall(temp))
	{
		textcolor(BoardColor);
		printCurrentBlock();

		movePoint = temp;

		textcolor(BlockColor);
		printCurrentBlock();
	}
}

bool Block::isWall(Point p)
{
	int x_loc, y_loc;
	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		//벽과 겹침 여부이므로 *2 필요없음
		//이동예정인 좌표가 겹치는지 판단하므로 block의 movePoint가 아닌 p의 값
		x_loc = blockPosition[direction][i].getX() + p.getX();
		y_loc = blockPosition[direction][i].getY() + p.getY();
		//테두리 두께 1칸 고려
		if (x_loc >= BW + BOARDX + 1 || x_loc<=BOARDX || y_loc >= BH + BOARDY + 1)
			return true;
	}
	return false;
}