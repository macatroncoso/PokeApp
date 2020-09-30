#include "funciones.h"
#include <stdbool.h>








new_pokemon * catchPokemon (char* name, List* types, int CP, int HP, char* gender, char* prev_evolution, char* next_evolution, int poke_number, char* region): {

    new_pokemon * poke = (new_pokemon *) malloc (sizeof(new_pokemon));
    poke->name = name;
    poke->CP = CP;
    poke->types = types;
    poke->HP = HP;
    poke->gender = gender;
    poke->prev_evolution = prev_evolution;
    poke->next_evolution = next_evolution;
    poke->poke_number = poke_number;
    poke->region = region;



    return poke;

}
