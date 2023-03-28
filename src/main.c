#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main(int argc, char *argv[]) {
    int num_players,board_length,board_width;
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
    initialize(num_players,board_length,board_width,&players_array);

    return 0;
}
