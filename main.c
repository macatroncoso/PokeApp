#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "hashmap.h"
#include "funciones.h"

int main()
{

    List * Pokemon = create_list();



    int option; //a number to guide our menu :3

    while(1){


    //our menu to print all our options :D
    printf("Welcome to the Unicorn's PokeApp (n _ n) What would you like to do?  \n\n");
    printf("Option 1 <3 : Import and/or Export games from a file \n");
    printf("Option 2 <3 : Catch a Pokemon! \n");
    printf("Option 3 <3 : Search Pokemon by type/s \n");
    printf("Option 4 <3 : Search Pokemon by Name \n");
    printf("Option 5 <3 : Search Pokemon by number on the Pokedex \n");
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
            case 1: importGames(games);
            break;
            case 2: exportGames(games);
            break;
            case 3: addNewGame(games);
            break;
            case 4: searchByName(games);
            break;
            case 5: searchByType(games);
            break;
            case 6:  searchByPlayers(games);
            break;
            case 7: searchByBrand(games);
            break;
            case 8: searchByCategories(games);
            break;
            case 9: printgames (games);
            break;
            case 10: printextensions (games);
            break;
        }

        if(option == 11){

            break;  //breaks the program

        }

    }




    return 0;
}
