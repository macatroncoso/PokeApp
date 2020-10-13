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
    int   poke_number;
    char * region;
}Pokedex;




const char *get_csv_field (char * , int );

char * toString(int );

void searchByNamePokedex(HashMap * );//search the pokemon in the pokedex by the name

void searchByName(HashMap * );//search the pokemon in the pokestorage by the name

void showCombatInformation(poke_storage * );

void * importAndExport(HashMap* ,HashMap*,TreeMap * , TreeMap *, HashMap *, TreeMap *, TreeMap *, TreeMap * );//this function export or import the file we work with

int lower_than_string(void* , void* );

int lower_than_int(void* , void* ); //This function compare 2 keys *int

void searchByType(HashMap * );//search the pokemon by the desire type  

poke_storage * create_pokemon_S(char * ,int , char *  , int  , int  );

void * catchPokemon (HashMap * ,HashMap *,TreeMap * , TreeMap * , int , HashMap * );

Pokedex * create_pokemon_P(char * , List * , char *  , char *  , char * ,int  );

void showPokemonInformation(Pokedex * );//show the info of the pokemon in all function

void getTypes(List *, char * );

void  showPokedexNumber(TreeMap *); //Show pokemons from Pokedez (Poke Number, lower to higer)

void showPokemonInfo2(Pokedex * ); //Show info from Pokedex, output

void showPokeStorageHP(TreeMap *); //Show pokemons from storage (Health points, higher to lower)

void showPokeStorageCP (TreeMap *); //Show pokemons from storage (Combat points, higher to lower)

void showPokemonInfo3 (poke_storage *); //Show info from Storage, output

void ReleasePokemon( HashMap *, HashMap *);// release the pokemon by ID

#endif // funciones_h
