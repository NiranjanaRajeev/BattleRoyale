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
    //remove previous logfile
    remove("game_log.txt");
    //initialize an array of player structures
    player *players_array=(player*)malloc(num_players * sizeof(player));
    initialize(players_array);
    int current_player=0;
    //game loop
    sprintf(message,"The Battle Royale begins \n");
    log_action(message);
    do{ 
        sprintf(message,"%s turn starts \n",players_array[current_player].name);
        log_action(message);
        move_player(current_player,players_array); //moves current player
        check_adjacent_tiles(current_player,players_array); // checks and fights
        if(current_player<num_players-1){ //incrementing index of current_player for next player to have the turn
            current_player++;
        }
        else{ //when we reach last player we reset index to zero
            current_player=0;  
        }
    }while(num_players>1); //game condition is to play till there is only one person left
    printf("The final board status is \n");
    display_board(players_array);
    sprintf(message,"%s wins the Battle Royale \n",players_array[0].name);
    log_action(message);
    free(players_array);
    return 0;
}
