#include <stdio.h>


//the struct for the player
typedef struct {                
    char name[20];
    int life_points;
    int x;
    int y;
} player; 

int is_tile_out_of_bounds(int x, int y, int board_length, int board_width);//To know if the tile is out of bounds
int is_tile_available(int x, int y, player *players_array,int board_length, int board_width,int num_players); //to know if the tile is occupied by another player
void initialize(int num_players, int board_length, int board_width, player *players_array);  //Initialize the board in the beginning of the game
void log_action(char* message);//To log messages
void move_player(int index,player *players_array,int x,int y,int board_length,int board_width,int num_players); //To move player to a location
void check_adjacent_tiles(player *currentplayer, player **players_array);//check adjacent tiles
void check_tile(int x, int y,player **players_array);//Check if tile is occupied and fight if there is a player
void fight(player *player1, player *player2); // fight and the first who wins two times wins the fight, the other loses hp
void display_board( player **players_array); //To display the board 
void delete_player(int index, player **players_array); //To delete a player from the array
