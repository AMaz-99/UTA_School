/* Aamir Mazumdar 1001523593 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#define MAPSIZE 10

char DirectionsFilename[20] = {};
char MapFilename[20]= {};

struct RowCol {
int row, col;
};

void MoveNorth(struct RowCol *Positionptr);
void MoveSouth(struct RowCol *Positionptr);
void MoveEast(struct RowCol *Positionptr);
void MoveWest(struct RowCol *Positionptr);

void MoveNorth(struct RowCol *PositionPtr) {
    if ((PositionPtr->row -1 < 0)) {
        printf("This takes you outside the map into the deep dark woods. "
               "You decide,\n as a reasonable individual to not go into the "
               "deep dark woods.\n");
    }
    else {
        PositionPtr->row--;
    }
    return;
}

void MoveSouth(struct RowCol *PositionPtr) {
    if ((PositionPtr->row + 1 > 9)) {
        printf("This takes you outside the map into the deep dark woods. "
               "You decide,\n as a reasonable individual to not go into the "
               "deep dark woods.\n");
    }
    else {
        PositionPtr->row++;
    }
    return;
}

void MoveEast(struct RowCol *PositionPtr) {
    if ((PositionPtr->col + 1 > 9)) {
        printf("This takes you outside the map into the deep dark woods. "
               "You decide,\n as a reasonable individual to not go into the "
               "deep dark woods.\n");
    }
    else {
        PositionPtr->col++;
    }
    return;
}

void MoveWest(struct RowCol *PositionPtr) {
    if ((PositionPtr->col - 1 < 0)) {
        printf("This takes you outside the map into the deep dark woods. "
               "You decide,\n as a reasonable individual to not go into the "
               "deep dark woods.\n");
    }
    else {
        PositionPtr->col--;
    }
    return;
}

void get_command_line_params(int argc, char *argv[]) {
    int i;
    for (i = 1; i < argc; i++) {
        if (!memcmp(*(argv + i),"DIRECTIONS=", 11)) {
            memcpy(DirectionsFilename, (strchr(*(argv+i), '=') +1), 20);
        }
        if (!memcmp(*(argv + i), "MAP=", 4)) {
            memcpy(MapFilename, (strchr(*(argv + i), '=') + 1), 20);
        }
    }
    if (DirectionsFilename == NULL || MapFilename == NULL) {
        printf("DIRECTIONS- and MAP- must be given on the command line!\n");
        exit(0);
    }
}

int main (int argc, char *argv[]) {
    FILE *DirectionFile, *TreasureMap;
    char DirectionList[500];
    char Map[MAPSIZE][MAPSIZE];
    int i,j,k;
    char buffer[2];
    struct RowCol Position;
    struct RowCol *PositionPtr = &Position;

    get_command_line_params(argc, argv);

    DirectionFile = fopen(DirectionsFilename, "r+");
    if (DirectionFile == NULL) {
        perror("DirectionFile did not open ");
        exit(0);
    }

    TreasureMap = fopen(MapFilename, "w+");
    if (TreasureMap == NULL) {
        perror("TreasureMap did not open ");
        exit(0);
    }

    fgets(DirectionList, 500, DirectionFile);

    for (j = 0; j < MAPSIZE; j++) {
        for (k = 0; k < MAPSIZE; k++) {
            Map[j][k] = '-';
        }
    }
    Position.row = 0;
    Position.col = 0;

    Map[Position.row][Position.col] = 'S';
    for (i = 0; i < strlen(DirectionList); i++) {
        if (DirectionList[i] == 'N')
            MoveNorth(PositionPtr);
        else if (DirectionList[i] == 'S')
            MoveSouth(PositionPtr);
        else if (DirectionList[i] == 'W')
            MoveWest(PositionPtr);
        else
            MoveEast(PositionPtr);
        Map[Position.row][Position.col] = 'X';
    }

    Map[Position.row][Position.col] = 'E';
    for (j = 0; j < MAPSIZE; j++){
        for (k = 0; k < MAPSIZE; k++){
            printf("%c  ", Map[j][k]);
            sprintf(buffer, "%c", Map[j][k]);
            fputs(buffer, TreasureMap);
        }
        printf("\n\n");
        sprintf(buffer, "\r\n");
        fputs(buffer, TreasureMap);
    }



    fclose (DirectionFile);
    fclose (TreasureMap);
    return 0;
}
