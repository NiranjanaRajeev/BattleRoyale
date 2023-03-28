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

void initialize(int num_players, int board_length, int board_width, player **players_array)
{
    char name[20];
    int i,x,y;

    srand(time(NULL));

    //Loop through the players array and initialize player name and life points
    for(i=0;i<num_players;i++)
    {
     printf("Enter player %d name",i+1);
     scanf("%s",name);
     player* new_player = (player*)malloc(sizeof(player));
     strncpy(new_player->name,name,20);
     new_player->life_points=5;
     //Assign the player to a random square on the board 
     do {
        x = rand() % board_length;
        y = rand() % board_width;
     }while(!is_tile_available(x,y,players_array,board_length,board_width,num_players));
     new_player->x =x;
     new_player->y =y;
     add_player(i,players_array,new_player);
    }
}