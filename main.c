#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "hashmap.h"
#include "funciones.h"
#include "treemap.h"

int main()
{

    HashMap * pokeStorageMap = createMap(500);
    HashMap * pokeStorageRegion = createMap(500);
    HashMap * PokedexMap = createMap(500);
    TreeMap * pokeStorageTree = createTreeMap(lower_than_string);
    TreeMap * PokedexTree = createTreeMap(lower_than_string);
    TreeMap * pokedexNumber = createTreeMap(lower_than_int);  //Creates a treeMap with int key
    TreeMap * pokeStorageCP = createTreeMap (lower_than_int); //Creates a treeMap with int key
    TreeMap * pokeStorageHP = createTreeMap (lower_than_int); //Creates a treeMap with int key

    int contid = 0;


    int option; //a number to guide our menu :3

    while(1){


    //our menu to print all our options :D
    printf("\nWelcome to the Unicorn's PokeApp (n _ n) What would you like to do?  \n\n");
    printf("Option 1 <3 : Import and/or Export games from a file \n");
    printf("Option 2 <3 : Catch a Pokemon! \n");
    printf("Option 3 <3 : Search Pokemon by type/s \n");
    printf("Option 4 <3 : Search Pokemon by Name \n");
    printf("Option 5 <3 : Search Pokemon Name on the Pokedex \n");
    printf("Option 6 <3 : Show all the Pokemon on the Pokedex \n");
    printf("Option 7 <3 : Show Pokemon by higher CP  \n");
    printf("Option 8 <3 : Show Pokemon by higher HP \n");
    printf("Option 9 <3 : Release Pokemon \n");
    printf("Option 10 <3 : Show Pokemon by their Region \n");
    printf("Option 11 <3 : Exit \n");
        do{
            scanf("%d", &option);
            if ((option > 11) || (option < 1))
               printf("Invalid option (> n <) please enter a valid menu option <3 \n");

        }while ((option > 11) || (option < 1));  //this "While" validates that the option entered is valid!

        switch(option){
            case 1: contid = importAndExport(PokedexMap,pokeStorageMap,PokedexTree,pokeStorageTree,pokeStorageRegion,pokedexNumber,pokeStorageHP,pokeStorageCP);
            break;
            case 2:  contid = catchPokemon (PokedexMap,pokeStorageMap,PokedexTree,pokeStorageTree,contid,pokeStorageRegion,pokedexNumber,pokeStorageCP,pokeStorageHP);
                    // printf ("%d",contid);
            break;
            case 3: searchByType(PokedexMap);
            break;
            case 4: searchByName(pokeStorageMap);
            break;
            case 5: searchByNamePokedex(PokedexMap);
            break;
            case 6: showPokedexNumber(pokedexNumber); //Print pokemons from Pokedex, ordered from lower to higher (key= pokeNumber)
            break;
            case 7: showPokeStorageCP(pokeStorageCP); //Print pokemons from Storage, ordered from higher to lower (key= Combat Points)
            break;
            case 8: showPokeStorageHP(pokeStorageHP); //Print pokemons from Storage, ordered from higher to lower (key= Health Points)
            break;
            case 9: ReleasePokemon(PokedexMap, pokeStorageMap); //release the pokemon by the id
            break;
            case 10: MostrarPokemonPokedex(pokeStorageRegion);
            break;

        }

        if(option == 11){

            break;  //breaks the program

        }

    }




    return 0;
}

