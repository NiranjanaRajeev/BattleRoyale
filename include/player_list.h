#pragma once
#include "player_cell.h"
#include <stdlib.h>

typedef struct{
	int size;
	player_cell* firstCell;
}player_list;


player_list* init();
int isEmpty(player_list* l);
int size(player_list* l);
player_cell* appendData(player_list* l, int data);
player_cell* prependData(player_list* l, int data);
player_cell* getCell(player_list* l, int index);
player_cell* insertData(player_list* l, int index, int data);
player_cell* modifyData(player_list* l, int index, int data);
int supprCell(player_list* l, int index);
int substCells(player_list* l, int index1, int index2);
int data(player_list* l, int index);
player_cell* takeCell(player_list* l, int index);
int nbOccurrence(player_list* l , int data);
player_cell* insertOrderedData(player_list* l, int data);
int findIndexData(player_list* l, int data);
int findIndexDataFrom(player_list* l, int data, int from);
player_list* copyList(player_list* l);
int removeDuplicates(player_list* l);
int supprData(player_list* l,int data);
int removeList(player_list* l);
