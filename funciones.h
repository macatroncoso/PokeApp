#ifndef funciones_h
#define funciones_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef struct poke_storage{
    char * name;
    char * gender;
    int id;
     int combat_power;
     int health_points;
    }poke_storage;  //arbol binario /   table hash

     typedef struct pokedex{
    char * name;
    int  amountOf_pokemon;
    List* types;
     char * prev_evolution;
     char * next_evolution;
    int  poke_number;
    char * region;
    }Pokedex;

   typedef struct new_pokemon{
    char * name;
    List* types;
     char * prev_evolution;
     char * next_evolution;
    int  poke_number;
    char * region;
    char * gender;
    int combat_power;
     int health_points;

    }new_pokemon;



const char *get_csv_field (char * , int );
void importGames(List*);
void getTypes(List *, char * );
addNewGame(List * );
void exportGames(List * );


#endif // funciones_h

