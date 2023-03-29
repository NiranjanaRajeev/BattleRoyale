#include "player_list.h"
#include <stdio.h>
#include <stdlib.h>
/* UNUSED


player_list* init()
{
	player_list* l = (player_list*)malloc(sizeof(player_list));
	l->firstCell = NULL;
	l->size = 0;

	return l;
}

int isEmpty(player_list* l)
{
	if (l->size == 0)
		return 1;
	return 0;
	//return !size(l);
}

int size(player_list* l)
{
	return l->size;
}

player_cell* appendData(player_list* l, int data)
{
	player_cell* cell = NULL;
	
	if (isEmpty(l))
	{
		cell = initCell(data, NULL, NULL);
		if (cell != NULL)
		{
			l->size++;
			l->firstCell = cell;
		}
	}
	else
	{
		l->size++;
		cell = initCell(data, l->firstCell->prev, l->firstCell);
	}
	return cell;
}

player_cell* prependData(player_list* l, int data)
{
	player_cell* c= appendData(l,data);
	if(c)
	  l->firstCell = c;
}

player_cell* getCell(player_list* l,int index)
{
	if(index < 0 || index >= l->size)
	 {
		printf(" The index is out of bounds");
		return NULL;
	 }

	player_cell* current = l->firstCell;
	for (int i =0; i<index; i++)
	{
		current = current->next;
	} 
	return current;
}

player_cell* insertData(player_list* l, int index, int data)
{
  
    player_cell* current = getCell(l, index);

    if (current == NULL) {
        // Failed to get cell at given index
        return NULL;
    }

    player_cell* newCell = initCell(data, current->prev, current);

    if (newCell == NULL) {
        // Failed to create new cell
        return NULL;
    }

    current->prev = newCell;

    if (index == 0) {
        // Inserting at the beginning of the list
        l->firstCell = newCell;
    } else {
        newCell->prev->next = newCell;
    }

    l->size++;

    return newCell;

}
player_cell* modifyData(player_list* l, int index, int data)
{
	player_cell* current = getCell(l, index);
	current->data = data;
	return current;
}

int supprCell(player_list* l, int index)
{
    player_cell* current = getCell(l, index);

    if (l->size == 1) {
        l->firstCell = NULL;
    }
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        if (index == 0) {
            l->firstCell = current->next;
        }
    }

    free(current);
    l->size--;
    return 1;
}

int substCells(player_list* l, int index1, int index2)
{
    if (index1 == index2) {
        printf("Indices are equal.\n");
        return 0;
    }

    player_cell* cell1 = getCell(l, index1);
    player_cell* cell2 = getCell(l, index2);

    int temp = cell1->data;
    cell1->data = cell2->data;
    cell2->data = temp;

    return 1;
}
int name(player_list* l, int index)
{
  player_cell* current = getCell(l, index);
  int temp_data = current->name;

  return temp_data;
}

player_cell* takeCell(player_list* l, int index)
{
	player_cell* current = getCell(l, index);

    if (l->size == 1) {
        l->firstCell = NULL;
    }
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        if (index == 0) {
            l->firstCell = current->next;
        }
    }
	l->size--;
	current->next=NULL;
	current->prev=NULL;

	return current; 
}

int findIndexData(player_list* l, int data)
{
    player_cell* current = l->firstCell;
	int currentIndex = 0;

	while(current->data !=data)
	{
		current=current->next;
		currentIndex++;

		if (current == l->firstCell) {
            return -1;
        }
	}
	return currentIndex;
}
*/