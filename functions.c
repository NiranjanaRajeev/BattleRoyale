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