#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include<string.h>  

void gotoxy(int x, int y);
void map(int m2[17][17]);
void Move();
void CursorView();

int direction = 0;
int score = 3;
int move[17][17] = {0,};
int oj[225] = { 0, };

	int main() {
	CursorView();
	int key = 0;
	int s = 3;

	for (int i = 224; i > 224 - score; i--) {
		oj[i] = i;
	}
	move[8][3] = 222; //꼬리
	move[8][4] = 223;
	move[8][5] = 224; //몸통
	move[8][6] = 225; //머리

	//Move(s);
	while (1) {
		Move();
		map(move);
		Sleep(300);
		system("cls");
		while (1) {
			if (_kbhit()) {

				key = _getch();
				if (key == 224) {
					key = _getch();
					switch (key)
					{
					case 72:
						if (direction != 4) {
							direction = 1;


							break;
						}

						//위 화살표
					case 75: 
						if (direction != 3) {
							direction = 2;


							break;
						}

						//왼쪽 화살표
					case 77:
						if (direction != 2) {
							direction = 3;


							break;
						}

						//오른쪽 화살표
					case 80:
						if (direction != 1) {
							direction = 4;
							break;
						}

						//아래 화살표
					default:
						break;
					}
				}
			}
			else
			{	

				break;
			}

		}


	}
	return 0;
}

	void Move() {

		int move1[17][17];
		int s1 = 0;
		int a = 0;
		int e = 0;


		if (direction == 1) { //위
			a = 0;
			for (int i = 1; i < 16; i++) {
				for (int j = 1; j < 16; j++) {
					if (move[i][j] == 225 && a == 0) {

						if (move[i - 1][j] == -255) {
							e = 1;
						}
						move[i - 1][j] = move[i][j];
						move[i][j] = -225;
						a = 1;


					}
				}
			}

			for (int k = 224; k > 224 - score; k--) {
				a = 0;
				for (int i = 1; i < 16; i++) {
					for (int j = 1; j < 16; j++) {
						if (move[i][j] == k && a == 0) {
							move[i][j] = -k;
							a = 1;
						}
					}
				}
				a = 0;
				for (int i = 1; i < 16; i++) {
					for (int j = 1; j < 16; j++) {
						if (move[i][j] == -(k + 1) && a == 0) {

							move[i][j] = k;
							a = 1;
						}
					}
				}
			}
			for (int i = 1; i < 16; i++) {
				for (int j = 1; j < 16; j++) {
					if (move[i][j] == -(225 - score) && a == 0) {

						move[i][j] = 0;

						a = 1;
					}
				}
			}
			a = 0;  
			if (e == 1) {
				score += 1;
			}
		}
		else if (direction == 2) { // 왼쪽
			a = 0;
			for (int i = 1; i < 16; i++) {
				for (int j = 1; j < 16; j++) {
					if (move[i][j] == 225 && a == 0) {

						if (move[i][j - 1] == -255) {
							e = 1;
						}
						move[i][j - 1] = move[i][j];
						move[i][j] = -225;
						a = 1;


					}
				}
			}
			for (int k = 224; k > 224 - score; k--) {
				a = 0;
				for (int i = 1; i < 16; i++) {
					for (int j = 1; j < 16; j++) {
						if (move[i][j] == k && a == 0) {
							move[i][j] = -k;
							a = 1;
						}
					}
				}
				a = 0;
				for (int i = 1; i < 16; i++) {
					for (int j = 1; j < 16; j++) {
						if (move[i][j] == -(k + 1) && a == 0) {
							move[i][j] = k;

							a = 1;
						}
					}
				}
			}
			for (int i = 1; i < 16; i++) {
				for (int j = 1; j < 16; j++) {
					if (move[i][j] == -(225 - score) && a == 0) {

						move[i][j] = 0;

						a = 1;
					}
				}
			}
			a = 0;
			if (e == 1) {
				score += 1;
			}
		}

		else if (direction == 3) { //오른쪽
			a = 0;
			for (int i = 1; i < 16; i++) {
				for (int j = 1; j < 16; j++) {
					if (move[i][j] == 225 && a == 0) {

						if (move[i][j + 1] == -255) {
							e = 1;
						}
						move[i][j + 1] = move[i][j];
						move[i][j] = -225;
						a = 1;


					}
				}
			}

			for (int k = 224; k > 224 - score; k--) {
				a = 0;
				for (int i = 1; i < 16; i++) {
					for (int j = 1; j < 16; j++) {
						if (move[i][j] == k && a == 0) {
							move[i][j] = -k;
							printf("%d", move[8][3]);
							Sleep(500);
							a = 1;
						}
					}
				}
				a = 0;
				for (int i = 1; i < 16; i++) {
					for (int j = 1; j < 16; j++) {
						if (move[i][j] == -(k + 1) && a == 0) {
							
							move[i][j] = k;
							
							a = 1;
						}
					}
				}
			}
			for (int i = 1; i < 16; i++) {
				for (int j = 1; j < 16; j++) {
					if (move[i][j] == -(225 - score) && a == 0) {

						move[i][j] = 0;

						a = 1;
					}
				}
			}
			a = 0;
			if (e == 1) {
				score += 1;
			}
		}
		else if (direction == 4) { //아래	
			a = 0;
			for (int i = 1; i < 16; i++) {
				for (int j = 1; j < 16; j++) {
					if (move[i][j] == 225 && a == 0) {
						if (move[i + 1][j] == -255) {
							e = 1;
						}

						move[i + 1][j] = move[i][j];
						move[i][j] = -225;
						a = 1;


					}
				}
			}

			for (int k = 224; k > 224 - score; k--) {
				a = 0;
				for (int i = 1; i < 16; i++) {
					for (int j = 1; j < 16; j++) {
						if (move[i][j] == k && a == 0) {
							move[i][j] = -k;
							a = 1;
						}
					}
				}
				a = 0;
				for (int i = 1; i < 16; i++) {
					for (int j = 1; j < 16; j++) {
						if (move[i][j] == -(k + 1) && a == 0) {

							move[i][j] = k;
							a = 1;
						}
					}
				}
			}
			for (int i = 1; i < 16; i++) {
				for (int j = 1; j < 16; j++) {
					if (move[i][j] == -(225 - score) && a == 0) {

						move[i][j] = 0;

						a = 1;
					}
				}
			}
			a = 0;
			if (e == 1) {
				score += 1;
			}
		}
	}


void map(int m2[17][17]) {

	int randomx = rand() % 15 + 1;
	int randomy = rand() % 15 + 1;
	int a = 0;

	int m[17][17];
	for (int i = 1; i < 16; i++) {
		for (int j = 1; j < 16; j++) {
			m[i][j] = m2[i][j];
		}
	}
	for (int i = 1; i < 16; i++) {
		for (int j = 1; j < 16; j++) {
			if (m2[i][j] == -255) {
				a = 1;
			}

		}
	}
	if (a == 0 && m2[randomx][randomy] == 0) {
		m2[randomx][randomy] = -255;
		a = 1;
	}
	

	for (int i = 0; i < 17; i++) {
		m2[0][i] = -256;
		m2[16][i] = -256;
		m2[i][16] = -256;
		m2[i][0] = -256;
	}
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 17; j++) {
			if (m[i][j] != 0 && m[i][j] > 0) {
				if (m[i][j] == 225) {
					m[i][j] = 2;
				}
				else {
					m[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 17; j++) {
			if (m2[i][j] != 0 && m2[i][j] == -256|| m2[i][j] == -255 || m[i][j] == 1 || m[i][j] == 2) {
				if (m[i][j] == 2) {
					printf("\u25A1");
				}
				else {
					printf("\033[32m\u25A0");
				}
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}


void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
 