#pragma once
#include <Windows.h>
#include <conio.h>

using namespace std;

#define BOARDX 3	//시작점x
#define BOARDY 3	//시작점y
#define BW 10	//보드가로
#define BH 20	//보드세로
#define NUMBER_OF_TILE 3
//색상의종류
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
	void finalize();	//종료시 리소스 반환
	void update(char key);	//키 입력 시 업데이트
	void DrawBoard();	//틀 그리기

private :
	bool isGameOver = false;	//게임 오버 여부

};

void gotoxy(int x, int y);



