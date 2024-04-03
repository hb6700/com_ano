#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

void intro();
void display_manual(void);
void display_piano_keyboard(void);
int calc_frequency(int octave, int inx);
void practice_piano(void);
void manual(void);
void gotoxy(int x, int y);

int main(void)
{
	intro();
	display_manual();
	manual();
	practice_piano();
	display_piano_keyboard();

	getchar();
	getchar();
	return 0;
}


void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}

void intro()
{
	printf("\n");
	printf("\n");
	printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|   |||   |||   |||   |||   |||   |||   |||   |||   |||     |\n");
	printf("|   |||   |||   |||   |||   |||   |||   |||   |||   |||     |\n");
	printf("|    |     |     |     |     |     |     |     |     |      |\n");
	printf("|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n");
	printf("|   |||   |||   |||   |||   |||   |||   |||   |||   |||     |\n");
	printf("|   |||   |||   |||   |||   |||   |||   |||   |||   |||     |\n");
	printf("|    |     |     |     |     |     |     |     |     |      |\n");
	printf("|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n");
	printf("|   |||   |||   |||   |||   |||   |||   |||   |||   |||     |\n");
	printf("|   |||   |||   |||   |||   |||   |||   |||   |||   |||     |\n");
	printf("|    |     |     |     |     |     |     |     |     |      |\n");
	printf("|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n");
	printf("|                                                           |\n");
	printf("|    ****************                                       |\n");
	printf("|    *    comano    *                                       |\n");
	printf("|    ****************                                       |\n");
	printf("|                              1860026 양시관               |\n");
	printf("|                              1860027 염현빈               |\n");
	printf("|                                          enter을 누르세요.|\n");
	printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");

	getchar();
	system("cls");
}


void display_manual(void)
{
	printf("\n");
	printf("키보드를 누르면\n");
	printf("키보드에 음이 표시됩니다.\n");
	printf("키:'↑'는 옥타브를 하나 올려줍니다.\n");
	printf("키:'↓'는 옥타브를 하나 내려줍니다.\n");
	printf("enter를 누르세요");
	printf("\n");

	//	getchar();
	getchar();
	system("cls");
	return;
}

//1.연습하기
void practice_piano(void)
{
	int index[] = { 0,2,4,5,7,9,11,12 };
	//도 레 미 파 솔 라 시 도
	int freq[8], code, i;
	for (i = 0; i < 8; i++)
		freq[i] = calc_frequency(4, index[i]);
	//int calc_frequency(int octave, int inx);
	do
	{
		code = _getch();
		if ('1' <= code && code <= '8')
		{
			code -= 49;
			Beep(freq[code], 200);
		}
	} while (code != 27);
}

//2.녹음하기
void recode_piano(void)
{
	int index[] = { 0,2,4,5,7,9,11,12 };
	int freq[8], code, i;
	for (i = 0; i < 8; i++)
	{
		freq[i] = calc_frequency(4, index[i]);
	}
	do
	{
		code = _getch();
		if ('1' <= code && code <= '8')
		{
			code -= 49;
			Beep(freq[code], 200);
		}

	} while (code != 27);

	int c = 0;
	int j = 0;
	int a[100];
	for (j = 0; j < 100; j++)
	{
		a[j] = c;
		scanf("%d", &c);
		printf("%d", a[j]);
		_getch();
	}
}
//		printf("\n\n\n\n\n\n녹음을 시작합니다.\n");

//		int c, j = 0;
//		int a[100];

//		do
//		{
//			if (c == 0)
//			{
//				break;
//			}
//			else
//			{
//				printf("%d\t", a[j]);
//				a[j] = c;
//				for (j = 0; j < 100; j++)
//				{
//					printf("녹음 시작\n");
//				}
//			}
//		} while (c != 0);


//주파수값?? 소리출력??
int calc_frequency(int octave, int inx)
{
	double do_scale = 32.7032;
	double ratio = pow(2., 1 / 12.);
	int i;
	double temp = do_scale * pow(2., octave - 1);
	for (i = 0; i < inx; i++)
	{
		temp = (int)(temp + 0.5);
		temp *= ratio;
	}
	return (int)temp;
}

void display_piano_keyboard(void)
//디스플레이에 키보드 모양을 표시하는 함수
{
	int i;
	printf("1부터 8까지 숫자 키를 누르면\n");
	printf("각음의 소리가 출력됩니다\n\n");
	//	printf("┌-┬┬┬┬-┬-┬┬┬┬┬┬-┬-┬┬-┐\n");
	printf("│ ││││ │ ││││││ │ ││ │\n");
	printf("│ ││││ │ ││││││ │ ││ │\n");
	printf("│ ││││ │ ││││││ │ ││ │\n");
	printf("│ ││││ │ ││││││ │ ││ │\n");
	printf("│ └┘└┘ │ └┘└┘└┘ │ └┘ │\n");
	printf("│  │  │  │  │  │  │  │  │  │\n");
	printf("│  │  │  │  │  │  │  │  │  │\n");
	printf("│  │  │  │  │  │  │  │  │  │\n");
	printf("│  │  │  │  │  │  │  │  │  │\n");
	printf("└─┴─┴─┴─┴─┴─┴─┴─┴─┘\n");
	char code[8][4] = { "도", "레", "미", "파", "솔", "라", "시" ,"도" };

	for (i = 0; i < 8; i++)
	{
		gotoxy(3 + i * 4, 9);
		printf("%2d", i + 1);
	}

	for (i = 0; i < 8; i++)
	{
		gotoxy(3 + i * 4, 11);
		printf("%s", code[i]);
	}

	getchar();
}

void manual(void)
{
	int title;
	printf("1). 연습하기\n");
	printf("2). 녹음하기\n");
	//	printf("3). 듣기\n");					//삭제
	printf("3). 파일보기\n");				//printf("4). 파일보기\n");		
	printf("4). 파일삭제\n");				//printf("5). 파일삭제\n");	
	printf("5). 종료\n");
	printf("6). 초기화면으로 돌아가기\n");	//아예 초기화면으로 돌아가기

	scanf("%2d", &title);
	system("cls");

	switch (title)
	{
	case 1:
		//1.연습하기
		display_piano_keyboard();
		practice_piano();
		break;
	case 2:
		//2.녹음하기
		display_piano_keyboard();
		recode_piano();
		break;
	case 3:
		//3.파일보기
		break;
	case 4:
		//4.파일삭제
		break;
	case 5:
		//5.종료
		break;
	case 6:
		//6.메인메뉴로 돌아가기
		intro();
		intro();
		display_manual();
		manual();
		switch (title)
		{
		case 1:
			display_piano_keyboard();
			practice_piano();
			//					break;
		case 2:
			//					display_piano_keyboard();
				//				recode_piano();
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		}
		//			display_piano_keyboard();
		//			int calc_frequency(int octave, int inx);
		//			practice_piano();
		//			recode_piano();
		//			manual();
		//			void gotoxy(int x, int y);
		//			getchar();
		break;
	}
	getchar();
	getchar();
	system("cls");
	return;
}