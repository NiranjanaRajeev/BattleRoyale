#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "functions.h"

int is_tile_out_of_bounds(int x, int y, int board_length, int board_width)
{
    if(x<0 || x>=board_length && y<0 || y>=board_width)
    {
        return 1; //out of bounds
    }
    return 0;  //within bounds
}

int is_tile_available(int x, int y, player **players_array,int board_length, int board_width,int num_players)
{
    int i;
    //check if the tile is within bounds
    if(is_tile_out_of_bounds(x,y,board_length,board_width)){
        return 0;
    }
    //Loop through players array to check if tile is occupied
    for(i=0;i<num_players;i++)
    {
        if(players_array[i]->x == x && players_array[i]->y == y){
        return 0; //tile unavailable
    }
    }
    return 1; //tile available
}

void add_player(int index, player **players_array,player *new_player)
{
    players_array[index]= new_player;
}
