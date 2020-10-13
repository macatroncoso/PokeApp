#include "funciones.h"
#include <stdbool.h>


void showPokemonInformation(Pokedex * puchi){


  // this function is very important to our program, because it's used in almost all the functions that search by a category
    printf("\n");
    printf("Pokemon's name: %s\n", puchi->name); //print the name
    printf("Amount of Pokemon in Storage: %d\n", puchi->amountOf_pokemon); //print the amount of pokemon in the storage
    printf("Pokemon's type(s):\n"); //print the pokemon types

    char * type = first(puchi->types); //access to the List of types

    while(type){

        printf("    %s\n", type); //print the types
        type = next(puchi->types); //proceed to next type

    }

    printf("Pokemon's Previous Evolution: %s\n", puchi->prev_evolution);//print the previous evolution
     printf("Pokemon's Next Evolution: %s\n", puchi->next_evolution);//print the next evolution
    printf("Pokemon's number on the Pokedex: %d\n", puchi->poke_number);//print the number of the pokemon
   printf("Pokemon's Region: %s\n\n", puchi->region);//print the region of the pokemon




}

const char *get_csv_field (char * tmp, int k) {

    int open_mark = 0;
    char* ret=(char*) malloc (100*sizeof(char));
    int ini_i=0, i=0;
    int j=0;
    while(tmp[i+1]!='\0'){

        if(tmp[i]== '\"'){
            open_mark = 1-open_mark;
            if(open_mark) ini_i = i+1;
            i++;
            continue;
        }

        if(open_mark || tmp[i]!= ','){
            if(k==j) ret[i-ini_i] = tmp[i];
            i++;
            continue;
        }

        if(tmp[i]== ','){
            if(k==j) {
               ret[i-ini_i] = 0;
               return ret;
            }
            j++; ini_i = i+1;
        }

        i++;
    }

    if(k==j) {
       ret[i-ini_i] = 0;
       return ret;
    }

    return NULL;
}

int lower_than_string(void* key1, void* key2){
    char* k1=(char*) key1;
    char* k2=(char*) key2;
    if(strcmp(k1,k2)<0) return 1;
    return 0;
}

int lower_than_int(void* key1, void* key2){ //This function compare 2 keys *int
    int k1 = *((int*) (key1));
    int k2 = *((int*) (key2));
    return k1<k2;
}

void showCombatInformation(poke_storage * puchi){


  // esta funcion muestra la informacion de combate de los pokemon
    printf("\n");
    printf("Pokemon's name: %s\n", puchi->name); //print the name
    printf("pokemon's ID: %d\n", puchi->id); //print the brand
    printf("Pokemon's gender: %s\n", puchi->gender); //print game types
    printf("pokemon's combats points: %d\n", puchi->combat_points);
    printf("pokemon's life: %d\n", puchi->health_points);

}

void searchByName(HashMap * pokeStorageMap){

    system("cls");
    // se pide al usuario que digite el nombre del pokemon que se busca
    printf("Please enter the name of the pokemon you are looking for: ");
    char name_[50];
    fflush(stdin);
    scanf("%[^\n]s", name_);
    fflush(stdin);
    bool found = false;

    // se crea una lista de pokemon y a la vez se busca en el pokeStorageMap con su respectivo nombre
    List * listadepokemones = searchMap(pokeStorageMap,name_);
    poke_storage * pukistorage = first(listadepokemones);

    if (pukistorage == NULL) {
    printf( "\nWe could not find a Pokemon  :(\n\n");
    return;}

    while(pukistorage != NULL){

        if(strcmp(pukistorage->name, name_) == 0){
             // si se encuentra el nombre que ingreso el usuario, se muestra la informacion de combate del pokemon
            showCombatInformation(pukistorage);
        }

        pukistorage = next(listadepokemones);
    }
    return;


    system("pause");
    system("cls");

}

void MostrarPokemonPokedex(HashMap * pokeStorageRegion){
    system("cls");

   // el usuario ingresa la region a buscar
    printf("Please enter the region: ");
    char region_[50];
    fflush(stdin);
    scanf("%[^\n]s", region_);
    fflush(stdin);
    bool found = false;

    // se crea una lista de pokemones por region y a la vez se busca que exista tal region
    List * listadepokemonesPorRegion = searchMap(pokeStorageRegion,region_);
    if (listadepokemonesPorRegion==NULL){
        printf("esta nulo");
    }
    if (listadepokemonesPorRegion!=NULL){
        showPokemonInformation(first(listadepokemonesPorRegion));
        for (int i =1; i<listCount(listadepokemonesPorRegion); i++){
           //se va recorriendo a traves de un for y se va mostrando por pantalla todos los pokemones que tengan la region ingresada por el usuario
            showPokemonInformation(next(listadepokemonesPorRegion));
        }
        found=true;
    }

    if(found == false) {
      // si no se encuentra
        printf("\nWe could not find the region :(\n\n");
    }
    system("pause");
    system("cls");

}

void searchByType(HashMap * PokedexMap){

//searches the pokemon by types
    system("cls");

    printf("Please enter the name of the Type you are looking for: ");
    char type[50];
    fflush(stdin);
    scanf("%[^\n]s", type);
    fflush(stdin);

    bool found = false;

    Pokedex * puchi = firstMap(PokedexMap);
    while(puchi != NULL ){

        char * typeList = first(puchi->types);
        while(typeList != NULL){

            if(strcmp(type, typeList) == 0){

                showPokemonInformation(puchi);
                found = true;

            }

            typeList = next(puchi->types);  //proceed to the next type
        }

        puchi = nextMap(PokedexMap);
    }

    if(found == false) {

        printf("\nWe could not find a Pokemon that matches that type  :(\n\n");

    }
    system("pause");
    system("cls");

}

void searchByNamePokedex(HashMap * PokedexMap){

//Function that search by the name of the pokemon

    system("cls");

    printf("Please enter the name of the Pokemon you are looking for: ");
    char name[50];
    fflush(stdin);
    scanf("%[^\n]s", name);
    fflush(stdin);

    Pokedex * puchi = searchMap(PokedexMap,name);


        if(searchMap(PokedexMap,name) != NULL){

            showPokemonInformation(puchi);
        }
        else{
    printf("\nWe could not find the Pokemon :(\n\n");
        system("pause");
        system("cls");

        }



}

void getTypes(List * typesList, char * types){

//function that get the different types of the pokemon :)

    char caracter[2] = ",";
    char * type;

    type = strtok(types, caracter); //separates the string if there's more than one type//
    while(type != NULL){

        if(type[0] == ' '){

            size_t si_ze = strlen(type);
            int i;
            for (i = 0 ; i < si_ze - 1; i++){

                type[i] = type[i + 1];

            }

            type[si_ze - 1] = '\0';

        }
        push_back(typesList, type);
        type = strtok(NULL, caracter);

    }

}

char * toString(int id){
 //function that convert a string to a int
    int digitos = 0;
    int aux = id;
    int numAlreves = 0;
    int auxDigitos;

    while(aux != 0){

        aux = aux / 10;
        digitos++;

    }

    aux = id;
    auxDigitos = digitos;
    digitos--;

    char * idString = (char *) malloc ( (auxDigitos + 1) * sizeof(char));

    while(aux != 0){

        numAlreves = numAlreves + ( (aux % 10) * pow(10, digitos) );
        aux = aux / 10;
        digitos--;

    }

    aux = id;
    digitos = auxDigitos;
    int i = 0;

    while(numAlreves > 0){

        idString[i] = (numAlreves%10) + 48;
        i++;
        numAlreves = numAlreves / 10;

    }

    idString[i] = '\0';

    return idString;

}

Pokedex * create_pokemon_P(char * name,  List * types, char *  prev_evolution, char *  next_evolution, char * region, int  poke_number){

   //very important function that creates a pokemon in the pokedex

    Pokedex * puchidex = (Pokedex *) malloc (sizeof(Pokedex));
    puchidex->name = name;
    puchidex->types = types;
    puchidex->amountOf_pokemon = 0;
    puchidex->next_evolution = next_evolution;
    puchidex->prev_evolution = prev_evolution;
    puchidex->region = region;
    puchidex->poke_number = poke_number;
    return puchidex;


}

poke_storage * create_pokemon_S(char * name, int id, char *  gender,  int  combat_points, int  health_points){
       //very important function that creates a pokemon in the storage

    poke_storage * puchidex = (poke_storage *) malloc (sizeof(poke_storage));
    puchidex->name = name;
    puchidex->id = id;
    puchidex->gender = gender;
    puchidex->combat_points = combat_points;
    puchidex->health_points = health_points;
    return puchidex;

}

void  * catchPokemon (HashMap * PokedexMap, HashMap * pokeStorageMap,TreeMap * pokeStorageTree, TreeMap * PokedexTree, int contid, HashMap * pokeStorageRegion,TreeMap * pokedexNumber, TreeMap *pokeStorageCP, TreeMap * pokeStorageHP  ) {



    if (mapsize(pokeStorageMap)>100){
        printf("Pokemon Storage is full.");
        return;

      }

    char * name = (char *) malloc (20 * sizeof(char));
    int combat_points;
    int health_points;
    int poke_number;
    int id = contid + 1;
    List * types = create_list();
    char * gender = (char *) malloc (20 * sizeof(char));
    char * prev_evolution = (char *) malloc (20 * sizeof(char));
    char * next_evolution = (char *) malloc (20 * sizeof(char));
    char * region = (char *) malloc (20 * sizeof(char));

    printf("Please enter the name of the Pokemon :D \n");
    fflush(stdin);
    scanf("%s",name);
    fflush(stdin);

    printf("Please enter the Combat Points of the Pokemon :D\n");
    scanf("%d", &combat_points);
    fflush(stdin);

    printf("Please enter the Health Points of the Pokemon :D\n");
    scanf("%d", &health_points);
    fflush(stdin);

    printf("Please enter the Gender of the Pokemon :D\n");
    scanf("%s",gender);
    fflush(stdin);

       printf("Please enter the Previous Evolution of the Pokemon :D\n");
    scanf("%s",prev_evolution);
    fflush(stdin);

       printf("Please enter the Next Evolution of the Pokemon :D\n");
    scanf("%s",next_evolution);
    fflush(stdin);

       printf("Please enter the Region of the Pokemon :D\n");
    scanf("%s",region);
    fflush(stdin);

    List * typesList = create_list();

    printf("\nHow many types does the Pokemon have? ");
        int cont;
        scanf("%d", &cont);
        int i = 1;

        while(cont>0){

            char * type = (char *) malloc (20 * sizeof(char)); ; //reads all the types entered by the user
            printf("Please enter the type number %d: ", i);
            fflush(stdin);
            scanf("%[^\n]s", type);
            fflush(stdin);

            push_back(typesList, type);

            i++;
            cont--;
        }

        Pokedex * new_poke = create_pokemon_P(name, types,  prev_evolution,   next_evolution, region, poke_number);
        poke_storage * newPoke = create_pokemon_S( name, id,  gender,   combat_points,  health_points);


        if (searchMap(PokedexMap, name) == NULL){
            insertMap(PokedexMap, new_poke->name ,new_poke);
            insertTreeMap(PokedexTree, new_poke->name ,new_poke);
            insertTreeMap(pokedexNumber, &new_poke->poke_number ,new_poke); //Insert pokemon in PokeNumber(key) Tree Map type Pokedex
            insertTreeMap(pokeStorageCP, &newPoke->combat_points, newPoke); //Insert pokemon in Combat Points(key) Tree Map type Storage
            insertTreeMap(pokeStorageHP, &newPoke->health_points, newPoke); //Insert pokemon in Health Points(key) Tree Map type Storage
           if (searchMap(pokeStorageRegion, region) == NULL){
            List* pokelist = create_list();
            push_back(pokelist, new_poke);
            insertMap(pokeStorageRegion, new_poke->region, pokelist);
           }

        else {
            List* pokelist = searchMap(pokeStorageRegion,new_poke->region);
            push_back(pokelist, new_poke);
            Pokedex * pokeaux = searchMap(PokedexMap, name);

        }
        }




           if (searchMap(PokedexMap, name) == NULL){
            insertMap(PokedexMap, new_poke->name ,new_poke);
        }



       if (mapsize(pokeStorageMap)>100){
            printf("Pokemon Storage is full.\n");
            return;
         }
       else{
        if (searchMap(pokeStorageMap, name) == NULL){

            List* pokelist = create_list();
            push_back(pokelist, newPoke);
            insertMap(pokeStorageMap, newPoke->name, pokelist);
            new_poke->amountOf_pokemon = 1;

        }
        else{
            List* pokelist = searchMap(pokeStorageMap,newPoke->name);
            push_back(pokelist, newPoke);
            Pokedex * pokeaux = searchMap(PokedexMap, name);
            pokeaux->amountOf_pokemon++;

        }
       }


             if (searchTreeMap(pokeStorageTree, name) == NULL){

            List* pokelistTree= create_list();
            push_back(pokelistTree, newPoke);
            insertTreeMap(pokeStorageTree, newPoke->name, pokelistTree);


        }
        else{
            List* pokelistTree = searchTreeMap(pokeStorageTree,newPoke->name);
            push_back(pokelistTree, newPoke);
            Pokedex * pokeauxtree = searchTreeMap(PokedexTree, name);


        }

   return id;
}

void * importAndExport(HashMap* PokedexMap, HashMap * pokeStorageMap, TreeMap * pokeStorageTree, TreeMap * PokedexTree, HashMap * pokeStorageRegion, TreeMap * pokedexNumber, TreeMap * pokeStorageHP, TreeMap * pokeStorageCP){
    //very important function that imports all the pokemon from a csv file

    system("cls");

    printf("\nWhat do you want to do?\n");
    printf("1: Import archive\n");
    printf("2: Export archive\n");


    int option;
    do{

        scanf("%d", &option);

        if(option != 1 && option != 2){
            printf("Invalid option (> n <) please enter a valid option <3 \n");
        }

    }while(option != 1 && option != 2);


    if(option == 1){

    int n;
    int cont = 0;
    printf("How many archives do you want to import? ");
    while(1){
        char buffer[3];
        fflush(stdin);
        memset(buffer,0,3);
        fread(buffer, 2, 1, stdin);
        n = atoi(buffer);
        if(n > cont && n< 100){
            break;
        }else{
        printf("Enter a valid value (integer number)\n");
        }
    }

     int id;
    while(cont < n){
        printf("Please enter the file name (n_n) ");
    char name[50]; //the name of the file that has the pokemon
    FILE * fp;

    do{

        fflush(stdin);
        scanf("%[^\n]s", name);
        fflush(stdin);
        fp = fopen( name , "r"); //opens the file in read
        if (fp == NULL){
            printf("Invalid file :( Please enter a valid file! "); //if the file isn't valid this message will pop on the screen
        }

    }while(fp == NULL);

    char line [1024];

    fgets(line, 1023, fp);
    while( fgets(line, 1023, fp) != NULL ){  //read and get every field of the csv file

        id = atoi(get_csv_field(line, 0));
        char * name = get_csv_field(line, 1);

        List * typesList = create_list();

        char * types = get_csv_field(line, 2);

        getTypes(typesList, types);

        int  combat_points = atoi(get_csv_field(line, 3));
        int health_points = atoi(get_csv_field(line, 4));

        char * gender = get_csv_field(line, 5);

        char * prev_evolution = get_csv_field(line, 6);
        char * next_evolution = get_csv_field(line, 7);
        int  poke_number =atoi(get_csv_field(line, 8));

        char * region = get_csv_field(line, 9);

        Pokedex * new_poke = create_pokemon_P( name,  typesList,   prev_evolution,   next_evolution,  region, poke_number);
        poke_storage * newPoke = create_pokemon_S( name, id,  gender,   combat_points,   health_points);




        if (searchMap(PokedexMap, name) == NULL){
            insertMap(PokedexMap, new_poke->name ,new_poke);
            insertTreeMap(PokedexTree, new_poke->name ,new_poke);
            insertTreeMap(pokedexNumber, &new_poke->poke_number ,new_poke); //Insert pokemon in PokeNumber(key) Tree Map type Pokedex
            insertTreeMap(pokeStorageCP, &newPoke->combat_points, newPoke); //Insert pokemon in Combat Points(key) Tree Map type Storage
            insertTreeMap(pokeStorageHP, &newPoke->health_points, newPoke); //Insert pokemon in Health Points(key) Tree Map type Storage
           if (searchMap(pokeStorageRegion, region) == NULL){
            List* pokelist = create_list();
            push_back(pokelist, new_poke);
            insertMap(pokeStorageRegion, new_poke->region, pokelist);
           }

        else {
            List* pokelist = searchMap(pokeStorageRegion,new_poke->region);
            push_back(pokelist, new_poke);
            Pokedex * pokeaux = searchMap(PokedexMap, name);

        }
        }



        if (mapsize(pokeStorageMap)>100){
            printf("Pokemon Storage is full.");
            return;
        }
        else{
        if (searchMap(pokeStorageMap, name) == NULL){

            List* pokelist = create_list();
            push_back(pokelist, newPoke);
            insertMap(pokeStorageMap, newPoke->name, pokelist);
            new_poke->amountOf_pokemon = 1;
           }

        else{
            List* pokelist = searchMap(pokeStorageMap,newPoke->name);
            push_back(pokelist, newPoke);
            Pokedex * pokeaux = searchMap(PokedexMap, name);
            pokeaux->amountOf_pokemon++;

            }
        }

        if (searchTreeMap(pokeStorageTree, name) == NULL){
            List* pokelistTree= create_list();
            push_back(pokelistTree, newPoke);
            insertTreeMap(pokeStorageTree, newPoke->name, pokelistTree);

           }


        else{
            List* pokelistTree = searchTreeMap(pokeStorageTree,newPoke->name);
            push_back(pokelistTree, newPoke);
            Pokedex * pokeauxtree = searchTreeMap(PokedexTree, name);


        }
    }
    cont++;
    }

    printf("All the Pokemon were imported correctly (^_^) "); //message that pops out on the window if all the pokemon were imported correctly
    system("pause");
    system("cls");
    printf("%d",id);
    return id;


    }

    else{

    char name_[50];
    printf("Please enter the name of the new File :D ");
    fflush(stdin);
    scanf("%[^\n]s", name_);
    fflush(stdin);
    strcat(name_, ".csv");

    FILE * fp = fopen(name_, "w");

    List * pokelist = firstMap(pokeStorageMap);

    while(pokelist != NULL){

        poke_storage * pokiStorage = first(pokelist);
        Pokedex * poki = searchMap(PokedexMap, pokiStorage->name);

        while(pokiStorage != NULL){

            fprintf(fp, "%d,%s,", pokiStorage->id,poki->name);

            char * type = first(poki->types);

            if( (type != NULL ) && ( next(poki->types) != NULL ) ){

                prev(poki->types);

                fprintf(fp, "\"");

                while(type != NULL){

                    if(next(poki->types) != NULL){
                        prev(poki->types);
                        fprintf(fp, "%s, ", type);

                    }
                    else{

                        fprintf(fp, "%s", type);

                    }

                    type = next(poki->types);

                }

                fprintf(fp, "\"");

            }
            else{

                fprintf(fp, "%s", type);

            }

            fprintf(fp, ",%d,%d,%s,%s,%s,%s\n", pokiStorage->combat_points,pokiStorage->health_points,pokiStorage->gender,poki->prev_evolution, poki->next_evolution, poki->region);

            pokiStorage = next(pokelist);

        }

        pokelist = nextMap(pokeStorageMap);
    }

    fclose(fp);

    system("pause");
    system("cls");

    }

}

void  showPokedexNumber(TreeMap * pokedexNumber){ //Show all pokemons from pokedex (poke Number,lower to higher)
    printf("\n");

    if (pokedexNumber == NULL) return;
    Pokedex * pokePokedex;
    pokePokedex= firstTreeMap (pokedexNumber);

    while (pokePokedex !=NULL){
        showPokemonInfo2 (pokePokedex);
        pokePokedex= nextTreeMap (pokedexNumber);
    }


}

void showPokemonInfo2(Pokedex * pokePoke){ //Show info from pokedex, 1 line for each pokemon
    printf("%s, ", pokePoke->name); //print the name
    printf("%d, ", pokePoke->amountOf_pokemon); //print the brand
    //printf(""); //print game types

    char * type = first(pokePoke->types); //access to the List of types

    while(type){

        printf("%s, ", type); //print the types
        type = next(pokePoke->types); //proceed to next type

    }

    printf("%s, ", pokePoke->prev_evolution);//print the min amount of players
     printf("%s, ", pokePoke->next_evolution);//print the min amount of players
    printf("%d, ", pokePoke->poke_number);//print the name of the Base Game
   printf("%s\n", pokePoke->region);//print the name of the Base Game
}


void showPokeStorageCP(TreeMap * treeCP){ //Show all pokemons from storage (Combat points, higher to lower)
    printf("\n");

    if (treeCP == NULL) return; // If tree is empty
    poke_storage * pokeAux; //auxVar to save info and show it
    pokeAux= lastTreeMap (treeCP); //gets the last value, higher from map

    while (pokeAux != NULL){
        showPokemonInfo3 (pokeAux);
        pokeAux= backTreeMap (treeCP); //Previous value, lower than current
    }

}


void showPokeStorageHP(TreeMap * treeHP){//Show all pokemons from storage (Health points, higher to lower)
    printf("\n");

    if (treeHP == NULL) return; // If tree is empty
    poke_storage * pokeAux; //auxVar to save info and show it
    pokeAux= lastTreeMap (treeHP);  //gets the last value, higher from map

    while (pokeAux != NULL){
        showPokemonInfo3 (pokeAux);
        pokeAux= backTreeMap (treeHP); //Previous value, lower than current
    }

}

//Works Correctly
void showPokemonInfo3(poke_storage * pokeS){ //Show info from Storage, output

    printf("%s, ", pokeS->name); //print the name

    printf("%s, ", pokeS->gender); //print the geneder

    printf("%d, ", pokeS->id);//print the id

     printf("%d, ", pokeS->combat_points);//print the combat points

    printf("%d \n", pokeS->health_points);//print the health points
}

void ReleasePokemon( HashMap * PokedexMap, HashMap * pokeStorageMap)
{
    char name[25];
    printf("Please enter the name of the Pokemon you want to release :smile: \n");
    fflush(stdin);
    scanf("%[^\n]s",name);
    fflush(stdin);
    int id;
    printf("Please enter the id of the Pokemon you want to release :smile: \n");
    scanf("%d",&id);
    fflush(stdin);

    Pokedex * pukidex = searchMap(PokedexMap, name);

    if(pukidex==NULL)
    {
        printf("the Pokemon was not found \n");
        return;
    }

    List * pokelist = searchMap(pokeStorageMap, pukidex->name);

    if(pokelist == NULL)
    {
        printf("the Pokemon was not found \n");
        return;
    }

    poke_storage * pukistorage = first(pokelist);

    if(pukidex->amountOf_pokemon == 1){

        //if there is only one data, we delete the list
        pukidex->amountOf_pokemon--;
        removeAllList(pokelist);
        return;
    }

    while(pukistorage != NULL){

        if(pukistorage->id == id){

            pukidex->amountOf_pokemon--;
            pop_current(pokelist);

            return;

        }

        pukistorage = next(pokelist);

    }

    printf("No pokemon with the given id was found\n");

}
