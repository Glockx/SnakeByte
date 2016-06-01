#pragma once
#ifndef _SNAKE_H
#define _SNAKE_H

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#include "screen.h"

#define ROW 20
#define COL 40

#define L 75
#define R 77
#define U 72
#define D 80

#define SNAKE_MAX_LEN 100
#define SNAKE_LEN 5

typedef enum _dir { LEFT, RIGHT, UP, DOWN } direction;

typedef struct _pos
{
	int x;
	int y;
} pos;

typedef struct _object
{
	int szCount;
	pos objPos[100];
} object;

typedef struct _snake
{
	int szLength;
	pos head;
} snake;

typedef struct turn_points
{
	int szCount;
	pos p[SNAKE_MAX_LEN];
} turn_points;

snake sn;
object obj;
turn_points turns;

// Direction of snake
direction kb_direction;


void init();
void update();
void draw();
void release();

void draw_walls();
void draw_objects();
void init_objects();
void init_snake();
void draw_snake();
void check_collision();
int game_is_going();

int random(int from, int to);

#endif
