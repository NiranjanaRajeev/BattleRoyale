#include <stdio.h>


//the struct for the player
typedef struct {                
    char name[20];
    int points;
    int x;
    int y;
} player; 

//the struct for the board
typedef struct {                
    int size;
    player players[5];
} checkerboard;



