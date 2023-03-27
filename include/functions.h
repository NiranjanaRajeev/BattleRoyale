#include <stdio.h>

typedef struct {
    char name[20];
    int points;
    int x;
    int y;
} player;

typedef struct {
    int size;
    player players[5];
} checkerboard;