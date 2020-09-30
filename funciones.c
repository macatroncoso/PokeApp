#include "funciones.h"








void exportGames(List * games){

    char name_[50];
    printf("Please enter the name of the new File :D");
    scanf("%s", name_);
    strcat(name_, ".csv");
    bool itsok;

    FILE * fp = fopen(name_, "w");
    if(fp == NULL) printf("Invalid File :( Please enter a valid File!");

    Game * nameG = first(games);

    while(nameG != NULL){

        itsok = false;

        fprintf(fp, "%s,%s,", nameG->name, nameG->brand);

        char * type = first(nameG->types);

        if(type != NULL && next(nameG->types)){

            fprintf(fp, "\"");
            itsok = true;

        }

        while(type != NULL){

            if(next(nameG->types)){

                fprintf(fp, "%s, ", type);

            }
            else{

                fprintf(fp, "%s", type);

            }

            type = next(nameG->types);

        }

        if(itsok == true){
            fprintf(fp, "\"");
        }

        fprintf(fp, ",%d,%d,%s\n", nameG->minPlayers, nameG->maxPlayers, nameG->baseGame);

        nameG = next(games);

    }

}




void getTypes(List * typesList, char * types){

    char caracter[2] = ",";
    char * type;

    type = strtok(types, caracter);
    while(type != NULL){

        if(type[0] == ' '){ // cut the space at the beginning of the second type//

            size_t si_ze = strlen(type);
            int i;
            for (i = 0 ; i < si_ze - 1; i++){

                type[i] = type[i + 1];

            }

            type[si_ze - 1] = '\0';

        }
        pushBack(typesList, type);
        type = strtok(NULL, caracter);

    }

}


addNewGame(List * Games){

    char name[60];

    printf("Please enter the name of the New Game : ");
    fflush(stdin);
    scanf("%[^\n]s");
    fflush(stdin);

    int cont;
    printf("How many types does the New Game have? ");
    scanf("%d", &cont);

    while(cont>0){
        List * typessList = createList();
        int i = 1;
        char type[50];
        printf("Please enter type number %d: ", i);
        scanf("%[^\n]s", type);
        fflush(stdin);

        pushBack(typessList, type);

        i++;
        cont--;
    }

    Game * newGame ;
    pushBack(Games, newGame);

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





Game * createGame(char * name, char * brand, List * types, int minPlayers, int maxPlayers, char * baseGame){

    Game * game = (Game *) malloc (sizeof(Game));
    game->name = name;
    game->brand = brand;
    game->types = types;
    game->minPlayers = minPlayers;
    game->maxPlayers = maxPlayers;
    game->baseGame = baseGame;
    return game;

}








void importGames(List* games){
 system("cls");
 printf("Please enter the file name (n_n) ");
 char name[50];
    fflush(stdin);
    scanf("%[^\n]s", name);
 FILE * fp = fopen( name , "r");
  if (fp == NULL){
    printf("Invalid file :( Please enter a valid file! \n");
  }
  fflush(stdin);


 char line [1024];

 while( fgets(line, 1023, fp) != NULL ){

        char * name = get_csv_field(line, 0);
        char * brand = get_csv_field(line, 1);

        List * typesList = createList();

        char * types = get_csv_field(line, 2);
        getTypes(typesList, types);

        int minPlayers = atoi(get_csv_field(line, 3));
        int maxPlayers = atoi(get_csv_field(line, 4));

        char * baseGame = get_csv_field(line, 5);

        Game * newGame = createGame(name, brand, typesList, minPlayers, maxPlayers, baseGame);

        pushBack(games, newGame);

    }

    exportGames(games);

    return 0;


 system("pause");
}


