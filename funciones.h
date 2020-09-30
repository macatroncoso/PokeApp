#ifndef funciones_h
#define funciones_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef struct Game{
 char * name;
 char * brand;
 List * types;
 int minPlayers;
 int maxPlayers;
 char * baseGame;

}Game;


Game * createGame(char * , char * , List * , int , int , char * );

const char *get_csv_field (char * , int );
void importGames(List*);
void getTypes(List *, char * );
addNewGame(List * );
void exportGames(List * );


#endif // funciones_h

