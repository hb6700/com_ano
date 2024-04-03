#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

#define NUM_KEYS 4

char key_list[] = {'a', 's', 'd', 'f'};
float frequency_list[] = { 261.626, 293.665, 329.628, 349.228 };

float getFrequencyFromkey(char key)
{
	for(int n = 0; n < NUM_KEYS ; n++)
	{
		if (key_list[n] == key)
		{
			return frequency_list[n];
		}
	}

	//return 0.0f;
	return 0;
}

void  playSound(void)
{
	char ch = getch();

	Beep(getFrequencyFromkey(ch), 150);

/*
	switch (ch)
	{
	case 'a':
		Beep(261.626, 500);
		break;
	case 's':
		Beep(293.665, 500);
		break;
	case 'd':
		Beep(329.628, 500);
		break;
	case 'f':
		Beep(, 500);
		break;
	}
	*/
	return 0;
}

void main()
{
	while(true)
		playSound();
}