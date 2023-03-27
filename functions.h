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

void initialize_checkerboard(checkerboard* board, int num_players, int board_size);  //Initialize the board in the beginning of the game
void display_checkerboard(checkerboard board); //To display the board 
void log_action(char* message)//To log messages
void move_player(player *currentplayer, checkerboard *board, int x, int y) //To move player to a location
void check_adjacent_players(player *player1, player *player2, checkerboard *board);//check if adjacent and play rock-paper-scissors


