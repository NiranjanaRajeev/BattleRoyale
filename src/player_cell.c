#include "player_cell.h"

/* UNUSED
player_cell* initCell(int d, player_cell* prev, player_cell* next)
{
	player_cell* currentAddress;
	currentAddress = (player_cell*)malloc(sizeof(player_cell));
	currentAddress->data = d;
	if (prev == NULL || next == NULL)
	{
		currentAddress->next = currentAddress;
		currentAddress->prev = currentAddress;
	}
	else
	{
		currentAddress->next = next;
		currentAddress->prev = prev;

		
		next->prev = currentAddress;//retour->next->prev = retour;		
		prev->next = currentAddress;//retour->prev->next = retour;
	}	
	return currentAddress;
}
*/