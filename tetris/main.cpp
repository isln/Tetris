#include <iostream>
#include <fstream>
#include <time.h>
#include "GameManager.h"
#include "point.h"
#include "block.h"

/*
기능
wasd, 방향키 입력 -> 블록 1칸씩 이동 혹은 회전
space bar -> 최하단이동
q -> 게임종료

1. 보드판 ------------------------------------------------------> 보드판 출력

2.	2-1. s 블록 하나만 생성
	2-2 블록 -> 7종 하드코딩 후 난수로 결정
3. 블록 1칸씩 내려오기
4. 쌓기
5. 1줄 완성 시 사라지면서 점수증가
*/

using std::cin;
using std::cout;
using std::endl;

//타일의 종류
enum Tile {
	EMPTY,
	WALL
};

const char *tiles[NUMBER_OF_TILE];

//char *tiles = new char[NUMBER_OF_TILE];
int board[BW][BH] = { EMPTY, };


bool update();
void finalize();		//게임 종료 시 실행
void tileSetting();		//유니코드 문자를 출력하기 위해 tiles 배열에 문자 넣는 함수. 다른방법은 없을지
void DrawScreen();		//테트리스 틀(벽)을 그림
void init();			//게임 시작 시 실행

int input_key();


int main(int argc, char* argv[])
{

	tileSetting();

	std::ifstream inStream;
	bool isGameOver = false;
	int cur_key = 'w'; 
	// i) arg를 확인해 입력파일이 있으면 파일 오픈(없을 시 통과)
	// ii) 테트리스 초기 화면 구성
	init();

	// iii) 종료시까지 게임진행
	while (!isGameOver)
	{

		//입력파일 존재 시 : 내용에 따라 블록위치 조정
		//미존재 시 : 키보드 입력
		/*
		if (argc > 1) inStream >> cur_key;
		else cur_key = input_key();
		*/

		/*
		main함수는 메뉴화면을 출력
		update의 기능
		1. 블록 객체를 가져와 1칸 내린뒤 출력
		2. 바닥에 도달 여부 판단 -> isFloor()
		3. 도달 시, 1줄 완성 여부 판단 -> isFull()
		*/
		Block block{ 0, 1 };
		block.printCurrentBlock();

		clock_t old_time = clock();
		clock_t cur_time = clock();

		//현재시간 - 시작시간을 사용해, 일정 시간 뒤 블록을 한칸 내림
		//회전 후 sleep으로 delay를 건다
		/*
		while (1)
		{
			//cur_time = clock();
			for (; cur_time - old_time <= 1000;)
			{
				cout << cur_time - old_time << endl;
				cur_time = clock();
				Sleep(100);
			}
			break;

		}
		*/
		while (1)
		{
			cur_key = input_key();
			if (cur_key == 'w')
				block.rotate();
			else if (cur_key == 'a')
				block.blockMove(LEFT);
			else if (cur_key == 's')
				block.blockMove(DOWN);
			else if (cur_key == 'd')
				block.blockMove(RIGHT);
			else if (cur_key == 'r')
				block.blockMove(TEST);
			else if (cur_key == 'q')
				break;
			
			//DrawScreen();
			//block.printCurrentBlock();
		}

		cout << "미완성!" << endl;
		isGameOver = update(); // 입력받은 키 처리 담당
		//display(); // 키보드 처리 후의 화면출력
	}
	//iv)쓰인 각종 리소스 반환
	finalize();
	
	return 0;
}

void tileSetting()
{
	tiles[0] = "□";
	tiles[1] = "■";
}

void DrawScreen()
{
	//Sleep(1000);	//1sec delay
	system("cls");

	int x, y;
	for (x = 0; x < BW + 2; x++) {		//겹치지 않게 2칸할당
		for (y = 0; y < BH + 2; y++) {
			gotoxy((BOARDX + x)*2, BOARDY + y);
			if (x == 0 || y == 0 || x == BW + 1 || y == BH + 1) {
				textcolor(wallColor);
				cout << tiles[WALL];
			}
			else {
				textcolor(BoardColor);
				cout << tiles[EMPTY];
			}
		}
		cout << endl;
	}
	textcolor();
}

void init()
{
	DrawScreen();
}

int input_key()
{
	int key; 
	while (1)
	{
		if (_kbhit()) {
			key = _getch();
			return key;
		}
	}
}

void finalize()
{

}

bool update()
{
	//if (cur_key == 'w')
		return true;
	//else
		//false;
}

