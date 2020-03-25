#include <iostream>
#include "block.h"

/*
�ϳ��� ��� ��ü�� �ϴ� ��� ��
�̵�, ȸ�� ���
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
		//x�� 1ĭ���� �ϸ� ��ġ�Ƿ� ��½� ���������� * 2 �������
		x_loc = (blockPosition[direction][i].getX() + movePoint.getX()) * 2;
		y_loc = blockPosition[direction][i].getY() + movePoint.getY();
		gotoxy(x_loc, y_loc);
		std::cout << "��";
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
		/* ���� ����� ���� üũ�ؾ���
		if(temp.getY == blockPosition[dir][BLOCK_SIZE-1]+BOARDY+BH)
		*/
		//�������� 0,0��
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
		//���� ��ħ �����̹Ƿ� *2 �ʿ����
		//�̵������� ��ǥ�� ��ġ���� �Ǵ��ϹǷ� block�� movePoint�� �ƴ� p�� ��
		x_loc = blockPosition[direction][i].getX() + p.getX();
		y_loc = blockPosition[direction][i].getY() + p.getY();
		//�׵θ� �β� 1ĭ ���
		if (x_loc >= BW + BOARDX + 1 || x_loc<=BOARDX || y_loc >= BH + BOARDY + 1)
			return true;
	}
	return false;
}