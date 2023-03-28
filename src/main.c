#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main(int argc, char *argv[]) {

    // Check if the correct number of arguments were provided
    if (argc != 4) {
        printf("Usage: %s <num_players> <board_size>\n", argv[0]);
        return 1;
    }

    // Convert command-line arguments from strings to integers
    num_players = atoi(argv[1]);
    board_length = atoi(argv[2]);
    board_width = atoi(argv[3]);
    //initialize an array of player structures
    player *players_array=(player*)malloc(num_players * sizeof(player));
    initialize(players_array);
    int current_player=0;
    do{
        move_player(current_player,players_array);
        check_adjacent_tiles(current_player,players_array);
        if(current_player<num_players-1){
            current_player++;
        }
        else{
            current_player=0;
        }
        printf("number of players is %d \n",num_players);
    }while(num_players>1);

    printf("%s wins \n",players_array[0].name);
    return 0;
}
