#ifndef funciones_h
#define funciones_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "hashmap.h"
#include "treemap.h"

typedef struct poke_storage{
    char * name;
    char * gender;
    int id;
     int combat_points;
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




const char *get_csv_field (char * , int );

char * toString(int );

void searchByNamePokedex(HashMap * );

void searchByName(HashMap * );

void showCombatInformation(poke_storage * );

void  * importAndExport(HashMap* ,HashMap*,TreeMap * , TreeMap *, HashMap * );

int lower_than_string(void* , void* );

void searchByType(HashMap * );

poke_storage * create_pokemon_S(char * ,int , char *  , int  , int  );

void * catchPokemon (HashMap * ,HashMap *,TreeMap * , TreeMap * , int , HashMap * );

Pokedex * create_pokemon_P(char * , List * , char *  , char *  , char * ,int );

void showPokemonInformation(Pokedex * );

void getTypes(List *, char * );


#endif // funciones_h

