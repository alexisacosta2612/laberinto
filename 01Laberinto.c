//MATERIA: LENGUAJE ENSAMBLADOR
//PROYECTO FINAL: LABERINTO
//MATERIA: LENGUAJE ENSAMBLADOR
//PROYECTO FINAL: LABERINTO
//INTEGRANTES : ACOSTA VILLALPANDO ALVARO ALEXIS
//              HERNANDEZ RODRIGUEZ ITALIA LUCERO
//              ROSALES SANTOS ANDRE ELIZABETH

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

//define limites del tablero
#define FILAS 100 //->
#define COLUMNAS 100

//funcion que inicaliza el tablero
inicializarTablero(char tablero[FILAS][COLUMNAS], int *coordenadaX, int *coordenadaY, int *salidaX, int *salidaY, int aleatorio){
    char tableroInicial[FILAS][COLUMNAS];       //alamacena el tablero que el aleatorio indique
	switch (aleatorio){
        case 0:
            printf("\nTABLERO 1");
            strcpy(tableroInicial[0],"############################");
            strcpy(tableroInicial[1],"#P.........#...............#");
            strcpy(tableroInicial[2],"##########.#.#############.#");
            strcpy(tableroInicial[3],"#..........#.##.##.###.#####");
            strcpy(tableroInicial[4],"#.########.................#");
            strcpy(tableroInicial[5],"#........#.###############.#");
            strcpy(tableroInicial[6],"#.######.#.#...............#");
            strcpy(tableroInicial[7],"#.#......#.#.###############");
            strcpy(tableroInicial[8],"#..........#..............X#");
            strcpy(tableroInicial[9],"############################");
            break;
        case 1:
            printf("\nTABLERO 2");
            strcpy(tableroInicial[1],"#################################");
            strcpy(tableroInicial[2],"#P..............................#");
            strcpy(tableroInicial[3],"#.#####.#######################.#");
            strcpy(tableroInicial[4],"#.#.....#.......#..........##...#");
            strcpy(tableroInicial[5],"#.#.###.#.##.##.#.###.#######.#.#");
            strcpy(tableroInicial[6],"#...#...#....##.#####.##......#.#");
            strcpy(tableroInicial[7],"#####.###.#####.......#######.#.#");
            strcpy(tableroInicial[8],"#.....###.#..########.#...###.#.#");
            strcpy(tableroInicial[9],"#.####..#.##.......##.#.#.###.#.#");
            strcpy(tableroInicial[10],"#.##...##.##.#####..#...#.....#.#");
            strcpy(tableroInicial[11],"#.##.##.#.##.#...########.#####.#");
            strcpy(tableroInicial[12],"#.......#X##.#.#.......##.#...#.#");
            strcpy(tableroInicial[13],"#.#####..#......####...##...#...#");
            strcpy(tableroInicial[14],"#################################");
            break;
        case 2:
            printf("\nTABLERO 3");
            strcpy(tableroInicial[1],"######################################");
            strcpy(tableroInicial[2],"#X..................####.##.####.....#");
            strcpy(tableroInicial[3],"##.###.##.##.##.#.#.##...........###.#");
            strcpy(tableroInicial[4],"##.##...........###.#...####.#####...#");
            strcpy(tableroInicial[5],"##.#############..#.###.##.#....##.###");
            strcpy(tableroInicial[6],"###..............##.#...##.####.##...#");
            strcpy(tableroInicial[7],"#.#.#########.#####.#.####.#.##.##.#.#");
            strcpy(tableroInicial[8],"#..................P.................#");
            strcpy(tableroInicial[9],"#.##.###..#..##.###.##..##.###.##.##.#");
            strcpy(tableroInicial[10],"#.####.......##.#.#.........#.....##.#");
            strcpy(tableroInicial[11],"#.#####.##.#..#.#.#.#######.#####.##.#");
            strcpy(tableroInicial[12],"#....#.###.####.#.##.....#...........#");
            strcpy(tableroInicial[13],"####.#....#.....#.#.####.#######.#.###");
            strcpy(tableroInicial[14],"#....####....##.....####.........#...#");
            strcpy(tableroInicial[15],"######################################");
            
            break;
        case 3:
            printf("\nTABLERO 4");
            strcpy(tableroInicial[0], "################################################");
            strcpy(tableroInicial[1], "#P....#..#.....#.....#.....#.....#..#..........#");
            strcpy(tableroInicial[2], "#.###.#.##.####.#.###.#.###.#.#.#...####.#####.#");
            strcpy(tableroInicial[3], "#...#.......#...#...#.....#...#.#........#.....#");
            strcpy(tableroInicial[4], "###.########.###.#.###.########.########.#.#####");
            strcpy(tableroInicial[5], "#........#.......#...#......#....#.......#.....#");
            strcpy(tableroInicial[6], "#.#######.#.#####.##########.#####.#.###.#.#.###");
            strcpy(tableroInicial[7], "#.......#.#...#.#.....#..........#...#...#.#...#");
            strcpy(tableroInicial[8], "#####.#.#####.#.###.#.##########.#####.###.#.###");
            strcpy(tableroInicial[9], "##....#.#.#.....#...#.#.#..........#....#...#..#");
            strcpy(tableroInicial[10],"###.#.#.#.#######.#.#.###########.#.#.#######.##");
            strcpy(tableroInicial[11],"#...#.#...#.....#.#......#...#...#..#.#........#");
            strcpy(tableroInicial[12],"#.#.#####.#.#.#.#####.##..#.#.#.#.#..#########.#");
            strcpy(tableroInicial[13],"# #.....#.#.# #...#.....#.#...#.#.#.........#..#");
            strcpy(tableroInicial[14],"###.#.#.###.###.#.#.#.###.#####.#####.#.#.#.#..#");
            strcpy(tableroInicial[15],"#...#.#...#...#.#...#.#.......#.....#.#.#.#....#");
            strcpy(tableroInicial[16],"###.#.#####.#####.###.#########.#.#.#.#.########");
            strcpy(tableroInicial[17],"#...#.......#...#.#.........#.#.#.#.#...#......#");
            strcpy(tableroInicial[18],"#.#######.#.#.#.#.#####.###.#.###########.##.#.#");
            strcpy(tableroInicial[19],"#.......#.#.#...#.....#...#................#..X#");
			strcpy(tableroInicial[20],"################################################");
            break;
    }//fin switch
    
    //recorre todo el mapa 
    for (int y = 0; y < FILAS; y++) {
        for (int x = 0; x < COLUMNAS; x++) {
            //asigna lo que hay en esa posicion a la matriz del parametro
            tablero[y][x] = tableroInicial[y][x];
            if (tablero[y][x] == 'P') {
                //guarda las coordenadas de P
                *coordenadaX = x;
                *coordenadaY = y;
            }
            else if (tablero[y][x] == 'X') {
                //guarda las coordenadas de X
                *salidaX = x;
                *salidaY = y;
            }
        }//fin for COLUMNAS
    }//fin for FILAS
    
}//fin funcion inicializarTablero 




int main() {
    char tablero[FILAS][COLUMNAS];                    //almacena matriz del tablero
    int coordenadaX, coordenadaY, salidaX, salidaY;   //coordenas de P y X
    char tecla;                                       //almacena que tecla es la que se presiona

    do{
      	int aleatorio = 0 + rand() % (5 - 0 + 1);    //aleatorio para escoger tablero

        inicializarTablero(tablero, &coordenadaX, &coordenadaY, &salidaX, &salidaY, aleatorio);







        printf("\n¿Jugar de nuevo? (S/N): ");
        tecla = toupper(_getch()); 
    }while (tecla == 'S'); //ciclo verfica que se desea continuar

    return 0;
}//fin main

