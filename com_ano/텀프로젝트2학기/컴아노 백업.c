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
	printf("|                              1860026 ��ð�               |\n");
	printf("|                              1860027 ������               |\n");
	printf("|                                          enter�� ��������.|\n");
	printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");

	getchar();
	system("cls");
}


void display_manual(void)
{
	printf("\n");
	printf("Ű���带 ������\n");
	printf("Ű���忡 ���� ǥ�õ˴ϴ�.\n");
	printf("Ű:'��'�� ��Ÿ�긦 �ϳ� �÷��ݴϴ�.\n");
	printf("Ű:'��'�� ��Ÿ�긦 �ϳ� �����ݴϴ�.\n");
	printf("enter�� ��������");
	printf("\n");

	//	getchar();
	getchar();
	system("cls");
	return;
}

//1.�����ϱ�
void practice_piano(void)
{
	int index[] = { 0,2,4,5,7,9,11,12 };
	//�� �� �� �� �� �� �� ��
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

//2.�����ϱ�
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
//		printf("\n\n\n\n\n\n������ �����մϴ�.\n");

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
//					printf("���� ����\n");
//				}
//			}
//		} while (c != 0);


//���ļ���?? �Ҹ����??
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
//���÷��̿� Ű���� ����� ǥ���ϴ� �Լ�
{
	int i;
	printf("1���� 8���� ���� Ű�� ������\n");
	printf("������ �Ҹ��� ��µ˴ϴ�\n\n");
	//	printf("��-��������-��-������������-��-����-��\n");
	printf("�� �������� �� ������������ �� ���� ��\n");
	printf("�� �������� �� ������������ �� ���� ��\n");
	printf("�� �������� �� ������������ �� ���� ��\n");
	printf("�� �������� �� ������������ �� ���� ��\n");
	printf("�� �������� �� ������������ �� ���� ��\n");
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	printf("��������������������������������������\n");
	char code[8][4] = { "��", "��", "��", "��", "��", "��", "��" ,"��" };

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
	printf("1). �����ϱ�\n");
	printf("2). �����ϱ�\n");
	//	printf("3). ���\n");					//����
	printf("3). ���Ϻ���\n");				//printf("4). ���Ϻ���\n");		
	printf("4). ���ϻ���\n");				//printf("5). ���ϻ���\n");	
	printf("5). ����\n");
	printf("6). �ʱ�ȭ������ ���ư���\n");	//�ƿ� �ʱ�ȭ������ ���ư���

	scanf("%2d", &title);
	system("cls");

	switch (title)
	{
	case 1:
		//1.�����ϱ�
		display_piano_keyboard();
		practice_piano();
		break;
	case 2:
		//2.�����ϱ�
		display_piano_keyboard();
		recode_piano();
		break;
	case 3:
		//3.���Ϻ���
		break;
	case 4:
		//4.���ϻ���
		break;
	case 5:
		//5.����
		break;
	case 6:
		//6.���θ޴��� ���ư���
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