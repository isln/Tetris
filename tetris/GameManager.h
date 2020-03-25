#pragma once
#include <Windows.h>
#include <conio.h>

using namespace std;

#define BOARDX 3	//������x
#define BOARDY 3	//������y
#define BW 10	//���尡��
#define BH 20	//���弼��
#define NUMBER_OF_TILE 3
//����������
enum Color {
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

const Color wallColor = BROWN;
const Color BoardColor = CYAN;
const Color BlockColor = YELLOW;

enum Direction {
	LEFT, UP, RIGHT, DOWN, TEST=10
};
void textcolor(int foreground = WHITE, int background = BLACK);

class Tetris
{
public :
	void finalize();	//����� ���ҽ� ��ȯ
	void update(char key);	//Ű �Է� �� ������Ʈ
	void DrawBoard();	//Ʋ �׸���

private :
	bool isGameOver = false;	//���� ���� ����

};

void gotoxy(int x, int y);



