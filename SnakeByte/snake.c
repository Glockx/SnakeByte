#include"snake.h"

time_t t;

int game_state = 0;

void init()
{
	sInit();

	init_snake();
	init_objects();

}

void init_objects()
{
	//TODO:
	//FIXME: It should not collide with snake
	srand((unsigned)time(&t));
	int i;
	int j;
	for (i = 0; i < obj.szCount; i++)
	{
		int r_x = random(1, COL - 2);
		int r_y = random(1, ROW - 3);

		for (j = 0; j<turns.szCount; j++)
		{
			if (turns.p[i].x == r_x && turns.p[i].y == r_y) r_y++;
		}
		if (sn.head.x == r_x && sn.head.y == r_y) r_y++;
		obj.objPos[i].x = r_x;
		obj.objPos[i].y = r_y;
	}
}

void init_snake()
{
	//TODO:
	int i;

	sn.head.x = 10;
	sn.head.y = 10;
	sn.szLength = SNAKE_LEN;
	turns.szCount = SNAKE_LEN;
	for (i = SNAKE_LEN; i >= 0; i--)
	{
		turns.p[SNAKE_LEN - i].x = sn.head.x + i;
		turns.p[i].y = sn.head.y;
	}
}

void update()
{
	//move

	int i;
	int x_chg = 0, y_chg = 0;

	switch (kb_direction)
	{
	case LEFT:
		if (sn.head.x>1) x_chg = -1;
		y_chg = 0;
		break;
	case RIGHT:
		if (sn.head.x<COL - 2) x_chg = 1;
		y_chg = 0;
		break;
	case UP:
		x_chg = 0;
		if (sn.head.y>1) y_chg = -1;
		break;
	case DOWN:
		x_chg = 0;
		if (sn.head.y<ROW - 2) y_chg = 1;
		break;
	}

	if (x_chg != 0 || y_chg != 0)
	{
		turns.szCount++;
		turns.p[turns.szCount - 1].x = sn.head.x;
		turns.p[turns.szCount - 1].y = sn.head.y;

		if (turns.szCount>sn.szLength)
		{
			for (i = 0; i<turns.szCount - 1; i++)
			{
				turns.p[i].x = turns.p[i + 1].x;
				turns.p[i].y = turns.p[i + 1].y;
			}
			turns.szCount--;
		}
	}
	sn.head.x += x_chg;
	sn.head.y += y_chg;

	check_collision();




	//collision
}



void draw()
{
	int x = 30, y = 20;

	sClear();

	draw_walls();
	draw_objects();
	draw_snake();


	//sPrint(x*2, y, "hello");


	sFlipping();
}

void release()
{
	sRelease();
	system("CLS");
}

void draw_walls()
{
	int x = 0;
	int y = 0;
	for (x = 0; x < COL; ++x)
	{
		sPrint(x, 0, "#");
		sPrint(x, ROW - 1, "#");
	}

	for (y = 0; y < ROW; ++y)
	{
		sPrint(0, y, "#");
		sPrint(COL - 1, y, "#");
	}
}

void draw_snake()
{
	int i;
	for (i = 0; i<turns.szCount; i++)
	{
		sPrint(turns.p[i].x, turns.p[i].y, "*");
	}
	sPrint(sn.head.x, sn.head.y, "@");
}

int random(int from, int to)
{
	int r = from + rand() % to;
	return r;
}

void draw_objects()
{
	int i;
	for (i = 0; i < obj.szCount; i++)
	{
		sPrint(obj.objPos[i].x, obj.objPos[i].y, "0");
	}
}

void check_collision()
{
	int i;

	for (i = 0; i<turns.szCount; i++)
	{
		if (turns.p[i].x == sn.head.x && turns.p[i].y == sn.head.y)
		{
			game_state = -1;
			return;
		}
	}

	for (i = 0; i<obj.szCount; i++)
	{
		if (obj.objPos[i].x == sn.head.x && obj.objPos[i].y == sn.head.y)
		{
			int j;
			for (j = i; j<obj.szCount; j++)
			{
				obj.objPos[j].x = obj.objPos[j + 1].x;
				obj.objPos[j].y = obj.objPos[j + 1].y;
			}
			obj.szCount--;
			break;
		}
	}

	if (obj.szCount == 0) game_state = 1;
}

int game_is_going()
{
	return game_state;
}
