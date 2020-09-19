/* Aamir Mazumdar 1001523593 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

#define MAPSIZE 10

char DirectionsFilename[20] = {};
char MapFilename[20]= {};

struct PlayerInfo {
char PlayerName[20];
int CurrentRow;
int CurrentCol;
};

int MoveNorth(char Map[MAPSIZE][MAPSIZE], struct PlayerInfo *PlayerPtr);
int MoveSouth(char Map[MAPSIZE][MAPSIZE], struct PlayerInfo *PlayerPtr);
int MoveEast(char Map[MAPSIZE][MAPSIZE], struct PlayerInfo *PlayerPtr);
int MoveWest(char Map[MAPSIZE][MAPSIZE], struct PlayerInfo *PlayerPtr);

int MoveNorth(char Map[][MAPSIZE], struct PlayerInfo *PlayerPtr) {
    if ((Map[PlayerPtr->CurrentRow - 1][PlayerPtr->CurrentCol] == 'S') || (Map[PlayerPtr->CurrentRow - 1][PlayerPtr->CurrentCol] == 'X') || (Map[PlayerPtr->CurrentRow - 1][PlayerPtr->CurrentCol] == 'E')) {
        PlayerPtr->CurrentRow--;
        printf("North is the correct move.\n");
        return 1;
    }
    else {
        printf("North is the wrong move.\n");
        return 0;
    }
}

int MoveSouth(char Map[][MAPSIZE], struct PlayerInfo *PlayerPtr) {
    if ((Map[PlayerPtr->CurrentRow + 1][PlayerPtr->CurrentCol] == 'S') ||(Map[PlayerPtr->CurrentRow + 1][PlayerPtr->CurrentCol] == 'X') || (Map[PlayerPtr->CurrentRow + 1][PlayerPtr->CurrentCol] == 'E')) {
        PlayerPtr->CurrentRow++;
        printf("South is the correct move.\n");
        return 1;
    }
    else {
        printf("South is the wrong move.\n");
        return 0;
    }
}

int MoveEast(char Map[][MAPSIZE], struct PlayerInfo *PlayerPtr) {
    if ((Map[PlayerPtr->CurrentRow][PlayerPtr->CurrentCol + 1] == 'S') || (Map[PlayerPtr->CurrentRow][PlayerPtr->CurrentCol + 1] == 'X') || (Map[PlayerPtr->CurrentRow][PlayerPtr->CurrentCol + 1] == 'E')) {
        PlayerPtr->CurrentCol++;
        printf("East is the correct move.\n");
        return 1;
    }
    else {
        printf("East is the wrong move.\n");
        return 0;
    }
}

int MoveWest(char Map[][MAPSIZE], struct PlayerInfo *PlayerPtr) {
    if ((Map[PlayerPtr->CurrentRow][PlayerPtr->CurrentCol - 1] == 'S') || (Map[PlayerPtr->CurrentRow][PlayerPtr->CurrentCol - 1] == 'X') ||(Map[PlayerPtr->CurrentRow][PlayerPtr->CurrentCol - 1] == 'E')) {
        PlayerPtr->CurrentCol--;
        printf("West is the correct move.\n");
        return 1;
    }
    else {
        printf("West is the wrong move.\n");
        return 0;
    }
}

void get_command_line_params(int argc, char *argv[]) {
    int i;
    for (i = 1; i < argc; i++) {
        if (!memcmp(*(argv + i), "MAP=", 4)) {
            memcpy(MapFilename, (strchr(*(argv + i), '=') + 1), 20);
        }
    }
    if (MapFilename == NULL) {
        printf("MAP= must be given on the command line!\n");
        exit(0);
    }
}

int main (int argc, char *argv[]) {
    FILE *TreasureMap;
    char MapList[500];
    char Map[MAPSIZE][MAPSIZE];
    char PlayerPath[MAPSIZE][MAPSIZE];
    char PlayerMove;
    int i,j,k;
    int MakeMove;
    struct PlayerInfo Player;
    struct PlayerInfo *PlayerPtr = &Player;

    get_command_line_params(argc, argv);

    TreasureMap = fopen(MapFilename, "r+");
    if (TreasureMap == NULL) {
        perror("TreasureMap did not open ");
        exit(0);
    }
    system("clear");
    printf("Enter Player Name: ");
    scanf("%s", &Player.PlayerName);
    getchar();

    Player.CurrentRow = 0;
    Player.CurrentCol = 0;

    fgets(MapList, 500, TreasureMap );
    i = 0;
    for (j = 0; j < MAPSIZE; j++) {
        for (k = 0; k < MAPSIZE; k++) {
            Map[j][k] = MapList[i];
            printf("%c ", Map[j][k]);
            i++;
            PlayerPath[j][k] = '-';
        }
        printf("\n");
    }
    printf("Press <Enter> when you are ready to start \n");
    getchar();
    system("clear");

    PlayerPath[0][0] = Map[0][0];
    do {
        printf("Enter a direction (NSEW) or 'Q' to quit \n");
        scanf("%c", &PlayerMove);
        getchar();
//        PlayerMove = toupper(PlayerMove);
        system("clear");

        if (toupper(PlayerMove) == 'N') {
            MakeMove = MoveNorth(Map, PlayerPtr);
        }
        else if (toupper(PlayerMove) == 'S') {
            MakeMove = MoveSouth(Map, PlayerPtr);
        }
        else if (toupper(PlayerMove) == 'W'){
            MakeMove = MoveWest(Map, PlayerPtr);
        }
        else if (toupper(PlayerMove) == 'E') {
            MakeMove = MoveEast(Map, PlayerPtr);
        }
        else {
            printf("Invalid move - must be NSEW\n");
            MakeMove = 0;
        }

        if (MakeMove == 1) {
            if (Map[Player.CurrentRow][Player.CurrentCol] == 'S') {
                printf("Player %s is back at start.\n", Player.PlayerName);
            }
            else if (Map[Player.CurrentRow][Player.CurrentCol] == 'X') {
                PlayerPath[Player.CurrentRow][Player.CurrentCol] = 'X';
            }
            else if (Map[Player.CurrentRow][Player.CurrentCol]== 'E') {
                printf("Player %s has made it to the end- WINNER!!\n", Player.PlayerName);
                PlayerPath[Player.CurrentRow][Player.CurrentCol] = 'E';
            }
        }
        for (j = 0; j < MAPSIZE; j++) {
            for (k = 0; k < MAPSIZE; k++){
                printf("%c  ", PlayerPath[j][k]);
            }
            printf("\n");
            }
    }while (!(toupper(PlayerMove) == 'Q'));



    fclose (TreasureMap);
    return 0;
}
