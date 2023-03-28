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
     }while(!is_tile_available(new_x,new_y,players_array));
    players_array[index].x=new_x;
    players_array[index].y=new_y;
    printf("%s new location is %d,%d \n",players_array[index].name,players_array[index].x,players_array[index].y);
}

int find_player_index(int x, int y, player *players_array)
{
    for(int i=0;i<num_players;i++)
    {
        if(players_array[i].x == x && players_array[i].y == y)
        {
            return i;
        }
    }
    return -1;
}

void fight(int enemy_index,int player_index,player *players_array)
{
    int enemy_points, player_points,enemy_choice, player_choice;
    enemy_points=0;
    player_points=0;
    do {
        player_choice = (rand() % 3) + 1;
        enemy_choice = (rand() % 3) + 1;
        if(player_choice==enemy_choice)
        {
            printf("It is a tie\n");
        }
        else if(player_choice==1&&enemy_choice==3 || player_choice==2&&enemy_choice==1 || player_choice==3&&enemy_choice==2)
        {
            printf("%s wins this round against %s\n",players_array[player_index].name,players_array[enemy_index].name);
            player_points++;
        }
        else
        {
           printf("%s wins this round against %s\n",players_array[enemy_index].name,players_array[player_index].name);
           enemy_points++; 
        }
        printf("%s:%d points-%s:%d points \n",players_array[player_index].name,player_points,players_array[enemy_index].name,enemy_points);
    } while(enemy_points<2&&player_points<2);
    if(enemy_points==2)
    {
        players_array[player_index].life_points=players_array[player_index].life_points-1;
        printf("%s has now %d life points\n",players_array[player_index].name, players_array[player_index].life_points);
        if(players_array[player_index].life_points==0){
            
            delete_player(player_index,players_array);
        }
           
    }
    else if(player_points==2)
    {
        players_array[enemy_index].life_points=players_array[enemy_index].life_points-1;
        printf("%s has now %d life points\n",players_array[enemy_index].name, players_array[enemy_index].life_points);

        if(players_array[enemy_index].life_points==0){
            delete_player(enemy_index,players_array);
        }
    }
}


void check_fight(int player_index,int x, int y, player *players_array)
{
   if(!is_tile_out_of_bounds(x,y)&&!is_tile_available(x,y,players_array)){ 
        int enemy_index =find_player_index(x,y,players_array);
        fight(enemy_index,player_index, players_array);
    } 
}

void check_adjacent_tiles(int player_index,player *players_array){
    int x,y;
    x=players_array[player_index].x;
    y=players_array[player_index].y;
    check_fight(player_index,x,y+1,players_array);//Up Tile
    check_fight(player_index,x+1,y,players_array);//Right Tile
    check_fight(player_index,x,y-1,players_array);//Down Tile
    check_fight(player_index,x-1,y,players_array);//Left Tile
}

void delete_player(int index, player *players_array){
    printf("%s died \n",players_array[index].name);

    for(int i=index;i<num_players-1;i++)
    {
        players_array[i].life_points=players_array[i+1].life_points;
        strncpy(players_array[i].name,players_array[i+1].name,20);
        players_array[i].x=players_array[i+1].x;
        players_array[i].y=players_array[i+1].y;
    }
    num_players=num_players-1;
} 