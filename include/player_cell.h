#pragma once
#include <stdlib.h>

typedef struct struct_player_cell{
	struct struct_player_cell*  prev;
	char name[20];
    int life_points;
    int x;
    int y;
	struct struct_player_cell*  next;
} player_cell;

player_cell* initCell(int d, player_cell* prev, player_cell* next);