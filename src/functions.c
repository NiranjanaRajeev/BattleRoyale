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
        if(players_array[i].x == x && players_array[i].y == y){ //checking if x and y coordinates match with another player
        return 0; //tile unavailable
    }
    }
    return 1; //tile available
}

int is_name_available(char *name,player *players_array)
{
 for(int i=0;i<num_players;i++)
 {  
    
    /*if(strcmp(name,players_array[i].name)==0) //comparing random name with names in players_array
    {
        return 0;
    }*/
    if(name[0]==players_array[i].name[0])
    {
        return 0;
    }

    
 }
 return 1;
}
int get_name_count(char* file) {
    FILE* fp;
    int count = 0;

    fp = fopen(file, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%*s\n") == 0) {
        count++;
    }

    fclose(fp);
    return count;
}

int get_name(char* file, char* name) {
    FILE* fp;
    int count = get_name_count(file);
    int random_index = rand() % count;
    int i = 0;

    fp = fopen(file, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", name) != EOF) {
        if (i == random_index) {
            fclose(fp);
            return 1;
        }
        i++;
    }

    fclose(fp);
    return 0;
}

void initialize( player* players_array,char *file)
{
    char name[20];
    int i,x,y;

    srand(time(NULL));
 //Loop through the players array and initialize player names and life points
    for(i=0;i<num_players;i++)
    {
     player new_player;
     new_player.life_points=5; //each player has 5 life points at game start
     do {
        get_name(file,name);
     }while(!is_name_available(name,players_array));
     strncpy(new_player.name,name,20);
     /*printf("Enter player %d name\n",i+1);
     scanf("%s",name);
     strncpy(new_player.name,name,20);*/
     
     //Assign the player to a random square on the board 
     do {
        x = rand() % board_length;
        y = rand() % board_width;
     }while(!is_tile_available(x,y,players_array));  //repeat until there is an available tile
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
     do {   //randomly assigning a new x and y
        new_x = rand() % board_length;
        new_y = rand() % board_width;
     }while(!is_tile_available(new_x,new_y,players_array)); //repeat until there is an available tile
    players_array[index].x=new_x;
    players_array[index].y=new_y;
    sprintf(message,"%s moves to %d,%d \n",players_array[index].name,players_array[index].x,players_array[index].y);
    log_action(message);
    printf("The current board status is : \n");
    display_board(players_array);
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

void display_board(player *players_array)
{
    for (int j = 0; j < board_length; j++) {  // Print top row of Xs surrounding the board
        if(j==0){
            printf("XXXXX"); 
        }else if(j==board_length-1){
            printf("XXXXXX\n"); 
        }
        else{
            printf("XXXX");
        }
    }
    for (int i = 0; i < board_width; i++) {
        printf("X");   //Print an X at the start of every row
        for (int j = 0; j < board_length; j++) {
            printf("+---"); // Print top edge of cell
        }
        printf("+X\n"); // End of row, print right edge of last cell

        for (int j = 0; j < board_length; j++) {
            if(is_tile_available(j,i,players_array))
            {
                if(j==0){
                    printf("X|   ");  //if available tile is a tile on left corner
                }
                
                else{
                    printf("|   "); // Print left and right edges of cell, with empty space in the middle
                }}
            else
            {
                int index = find_player_index(j,i,players_array);
                char initial = players_array[index].name[0];
                if(j==0){
                    printf("X| %c ",initial);  //if the tile with the player is on left corner
                }else{
                    printf("| %c ",initial); // Print left and right edges of cell, with empty space in the middle
                }
            }
        }
        printf("|X\n"); // End of row, print right edge of last cell with an X on the end
    }

    for (int j = 0; j < board_length; j++) {
        if(j==0){
            printf("X+---"); 
        }else{
            printf("+---"); // Print bottom edge of last row of cells
        }
    }
    printf("+X\n"); // End of board, print right edge of last cell and give X at the end
    
    for (int j = 0; j < board_length; j++) { //For adding bottom edge with Xs surrounding the board
        if(j==0){
            printf("XXXXX"); 
        }else if(j==board_length-1){
            printf("XXXXXX\n\n"); 
        }
        else{
            printf("XXXX");
        }
    }
}

void fight(int enemy_index,int player_index,player *players_array)
{
    int enemy_points, player_points,enemy_choice, player_choice,round; //declaring variables to store player choice and points in rock-paper scissors
    enemy_points=0;
    player_points=0;
    round = 1;

    do { //randomly generating choices 1=rock,2=paper,3=scissors
        player_choice = (rand() % 3) + 1;
        enemy_choice = (rand() % 3) + 1;
        if(player_choice==enemy_choice) //case tie
        {
            sprintf(message,"Round %d is a tie\n",round);
            log_action(message);
        }
        else if(player_choice==1&&enemy_choice==3 || player_choice==2&&enemy_choice==1 || player_choice==3&&enemy_choice==2) //case player wins
        {
            sprintf(message,"%s wins round %d against %s\n",players_array[player_index].name,round,players_array[enemy_index].name);
            log_action(message);
            player_points++;
        }
        else     //enemy wins
        {
           sprintf(message,"%s wins round %d against %s\n",players_array[enemy_index].name,round,players_array[player_index].name);
           log_action(message);
           enemy_points++; 
        }
        sprintf(message,"At the end of round %d %s:%d points-%s:%d points \n",round,players_array[player_index].name,player_points,players_array[enemy_index].name,enemy_points);
        log_action(message);
        round++;
    } while(enemy_points<2&&player_points<2); //The condition to declare a winner is when one of them has 2 points or 2 wins

    if(enemy_points==2) //when enemy wins
    {
        players_array[player_index].life_points-=1; //player loses 1 life point
        sprintf(message,"%s wins the Rock-Paper-Scissors game\n",players_array[enemy_index].name);
        log_action(message);
        sprintf(message,"%s has now %d life points\n",players_array[player_index].name, players_array[player_index].life_points);
        log_action(message);
        if(players_array[player_index].life_points==0){ //checking to see if player reached zero points
            delete_player(player_index,players_array); //deleting player from the array
        }
           
    }
    else if(player_points==2) //when player wins
    {
        players_array[enemy_index].life_points-=1; //enemy loses 1 life point
        sprintf(message,"%s wins the Rock-Paper-Scissors game\n",players_array[player_index].name);
        log_action(message);
        sprintf(message,"%s has now %d life points\n",players_array[enemy_index].name, players_array[enemy_index].life_points);
        log_action(message);
        if(players_array[enemy_index].life_points==0){ //checking to see if enemy reached zero points
            delete_player(enemy_index,players_array); //deleting enemy from the array
        }
    }
}


void check_fight(int player_index,int x, int y, player *players_array)
{
   if(!is_tile_out_of_bounds(x,y)&&!is_tile_available(x,y,players_array)){ 
        int enemy_index =find_player_index(x,y,players_array); //finds which player is on the adjacent enemy tile
        sprintf(message,"%s and %s will do rock-paper-scissors",players_array[player_index].name,players_array[enemy_index].name);
        log_action(message);
        fight(enemy_index,player_index, players_array);
    } 
}

void check_adjacent_tiles(int player_index,player *players_array){
    int x,y;
    x=players_array[player_index].x;
    y=players_array[player_index].y;
    check_fight(player_index,x,y+1,players_array);//checking the upper tile
    check_fight(player_index,x+1,y,players_array);//checking the right Tile
    check_fight(player_index,x,y-1,players_array);//checking the lower Tile
    check_fight(player_index,x-1,y,players_array);//checking the left Tile
    sprintf(message,"The turn of %s is over\n",players_array[player_index].name);
    log_action(message);
}

void delete_player(int index, player *players_array){
    sprintf(message,"%s died \n",players_array[index].name);
    log_action(message);
    for(int i=index;i<num_players-1;i++)
    {
        players_array[i]=players_array[i+1];  //shifting players to left
    }
    num_players=num_players-1; //decreasing array size
} 