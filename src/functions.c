#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "functions.h"



int is_tile_out_of_bounds(int x, int y)
{
    if(x<0 || x>=board_length || y<0 || y>=board_width)
    {
        return 1; //out of bounds
    }
    return 0;  //within bounds
}

int is_tile_available(int x, int y, player *players_array)
{
    int i;
    //check if the tile is within bounds
    if(is_tile_out_of_bounds(x,y)){
        return 0;
    }
    //Loop through players array to check if tile is occupied
    for(i=0;i<num_players;i++)
    {
        if(players_array[i].x == x && players_array[i].y == y){
        return 0; //tile unavailable
    }
    }
    return 1; //tile available
}

void initialize( player* players_array)
{
    char name[20];
    int i,x,y;

    srand(time(NULL));
 //Loop through the players array and initialize player name and life points
    for(i=0;i<num_players;i++)
    {
     player new_player;
     printf("Enter player %d name\n",i+1);
     scanf("%s",name);
     strncpy(new_player.name,name,20);
     new_player.life_points=5;
     //Assign the player to a random square on the board 
     do {
        x = rand() % board_length;
        y = rand() % board_width;
     }while(!is_tile_available(x,y,players_array));
     new_player.x=x;
     new_player.y=y;
     players_array[i]=new_player;
    }
}

// Function to log all actions into a file
void log_action(char* message) {
    FILE* logfile;
    logfile = fopen("game_log.txt", "a");
    fprintf(logfile, "%s\n", message);
    fclose(logfile);
}
void move_player(int index,player *players_array)
{
    int new_x,new_y;
     do {
        new_x = rand() % board_length;
        new_y = rand() % board_width;
        printf("we try %d,%d ",new_x,new_y);
     }while(!is_tile_available(new_x,new_y,players_array));

    players_array[index].x=new_x;
    players_array[index].y=new_y;
    printf("player new location is %d,%d ",players_array[index].x,players_array[index].y);
}
void check_adjacent_tiles(int index,player *players_array){
    int player_x,player_y;
    players_array[index].x=player_x;
    players_array[index].y=player_y;
    if(!is_tile_out_of_bounds(player_x,player_y+1)){return 0;}

    
}
