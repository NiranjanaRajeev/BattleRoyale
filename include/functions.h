#include <stdio.h>


//the struct for the player
typedef struct {                
    char name[20];
    int life_points;
    int x;
    int y;
} player; 

int num_players,board_length,board_width;

int is_tile_out_of_bounds(int x, int y);//To know if the tile is out of bounds
int is_tile_available(int x, int y, player *players_array); //to know if the tile is occupied by another player
void initialize(player *players_array);  //Initialize the board in the beginning of the game
void log_action(char* message);//To log messages
void move_player(int index,player *players_array); //To move player to a location
void check_fight(int player_index,int x, int y, player *players_array);//To check a single neighbour and fight
int find_player_index(int x, int y, player *players_array);//find player index from x and y
void check_adjacent_tiles(int index, player *players_array);//check adjacent tiles
void fight(int enemy_index, int player_index, player *players_array); // fight and the first who wins two times wins the fight, the other loses hp
//void display_board( player **players_array); //To display the board 
void delete_player(int index, player *players_array); //To delete a player from the array  
