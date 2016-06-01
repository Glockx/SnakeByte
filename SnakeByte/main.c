#include <stdio.h>
#include "snake.h"

int main()
{
	printf("Enter the number of items: ");
	scanf_s("%d", &obj.szCount);

	int ekey = 0;

	init();

	int win = 0;

	while (1)
	{

		if (_kbhit())
		{
			ekey = _getch();
			_flushall();

			switch (ekey)
			{
			case L:
				if (kb_direction != RIGHT) kb_direction = LEFT;
				break;
			case R:
				if (kb_direction != LEFT) kb_direction = RIGHT;
				break;
			case U:
				if (kb_direction != DOWN) kb_direction = UP;
				break;
			case D:
				if (kb_direction != UP) kb_direction = DOWN;
				break;
			default:
				break;
			}

		}
		update();

		win = game_is_going();

		if (win != 0)
		{
			break;
		}

		draw();
		Sleep(100);
	}
	release();
	if (win == 1)
	{

		printf("YOU WIN!\n");
	}
	else
	{
		printf("YOU LOSE!\n");
	}
	system("PAUSE");
}

