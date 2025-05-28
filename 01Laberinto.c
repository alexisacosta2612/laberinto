
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
#include <string.h>

//define limites del tablero
#define FILAS 21 //->
#define COLUMNAS 50

//guarda las dimensiones del laberinto
typedef struct {
    int filas;
    int columnas;
} Dimensiones;

//funcion en NAMS
extern void funcionLaberintoASM(char tablero[FILAS][COLUMNAS], int x, int y, Dimensiones *dimensiones);

//funcion que imprime el laberinto
void mostrarLaberinto(char tablero[FILAS][COLUMNAS], int coordenadaX, int coordenadaY, Dimensiones *dim) {
    //system("cls");
    /*
    for (int y = 0; y < dim.filas; y++) {
        printf("\n");
        for (int x = 0; x < dim.columnas; x++) {
            //verifica si x & y es igual a las coordenadas de P
            //si es imprime P sino lo que hay en esa casilla
            if (x == coordenadaX && y == coordenadaY) {
                printf("P");
            } else {
                printf("%c", tablero[y][x]);
            }
        }//fin for COLUMNAS
    }//fin for FILAS
    */
    funcionLaberintoASM(tablero, coordenadaX, coordenadaY, dim);
}//fin funcion mortrarLaberinto

//funcion que inicaliza el tablero
void inicializarTablero(char tablero[FILAS][COLUMNAS], int *coordenadaX, int *coordenadaY, 
                       int *salidaX, int *salidaY, int aleatorio, Dimensiones *dimensiones){
    //limpia el tablero 
    memset(tablero, '#', sizeof(char) * FILAS * COLUMNAS);
    
    //se elige el tablero segun el aleatorio
    switch (aleatorio){
        case 0:
            dimensiones->filas = 10;                    //guarda las dimensiones del tablero
            dimensiones->columnas = 28;
            printf("\nTABLERO 1");
            strcpy(tablero[0],"############################");
            strcpy(tablero[1],"#P.........#...............#");
            strcpy(tablero[2],"##########.#.#############.#");
            strcpy(tablero[3],"#..........#.##.##.###.#####");
            strcpy(tablero[4],"#.########.................#");
            strcpy(tablero[5],"#........#.###############.#");
            strcpy(tablero[6],"#.######.#.#...............#");
            strcpy(tablero[7],"#.#......#.#.###############");
            strcpy(tablero[8],"#..........#..............X#");
            strcpy(tablero[9],"############################");
            break;
        case 1:
            dimensiones->filas = 14;                    //guarda las dimensiones del tablero
            dimensiones->columnas = 35;
            printf("\nTABLERO 2");
            strcpy(tablero[0],"#################################");
            strcpy(tablero[1],"#P..............................#");
            strcpy(tablero[2],"#.#####.#######################.#");
            strcpy(tablero[3],"#.#.....#.......#..........##...#");
            strcpy(tablero[4],"#.#.###.#.##.##.#.###.#######.#.#");
            strcpy(tablero[5],"#...#...#....##.#####.##......#.#");
            strcpy(tablero[6],"#####.###.#####.......#######.#.#");
            strcpy(tablero[7],"#.....###.#..########.#...###.#.#");
            strcpy(tablero[8],"#.####..#.##.......##.#.#.###.#.#");
            strcpy(tablero[9],"#.##...##.##.#####..#...#.....#.#");
            strcpy(tablero[10],"#.##.##.#.##.#...########.#####.#");
            strcpy(tablero[11],"#.......#X##.#.#.......##.#...#.#");
            strcpy(tablero[12],"#.#####..#......####...##...#...#");
            strcpy(tablero[13],"#################################");
            break;
        case 2:
            dimensiones->filas = 15;                    //guarda las dimensiones del tablero
            dimensiones->columnas = 38;
            printf("\nTABLERO 3");
            strcpy(tablero[0],"######################################");
            strcpy(tablero[1],"#X..................####.##.####.....#");
            strcpy(tablero[2],"##.###.##.##.##.#.#.##...........###.#");
            strcpy(tablero[3],"##.##...........###.#...####.#####...#");
            strcpy(tablero[4],"##.#############..#.###.##.#....##.###");
            strcpy(tablero[5],"###..............##.#...##.####.##...#");
            strcpy(tablero[6],"#.#.#########.#####.#.####.#.##.##.#.#");
            strcpy(tablero[7],"#..................P.................#");
            strcpy(tablero[8],"#.##.###..#..##.###.##..##.###.##.##.#");
            strcpy(tablero[9],"#.####.......##.#.#.........#.....##.#");
            strcpy(tablero[10],"#.#####.##.#..#.#.#.#######.#####.##.#");
            strcpy(tablero[11],"#....#.###.####.#.##.....#...........#");
            strcpy(tablero[12],"####.#....#.....#.#.####.#######.#.###");
            strcpy(tablero[13],"#....####....##.....####.........#...#");
            strcpy(tablero[14],"######################################");           
            break;
        case 3:
            dimensiones->filas = 21;                    //guarda las dimensiones del tablero
            dimensiones->columnas = 48;
            printf("\nTABLERO 4");
            strcpy(tablero[0], "################################################");
            strcpy(tablero[1], "#P....#..#.....#.....#.....#.....#..#..........#");
            strcpy(tablero[2], "#.###.#.##.####.#.###.#.###.#.#.#...####.#####.#");
            strcpy(tablero[3], "#...#.......#...#...#.....#...#.#........#.....#");
            strcpy(tablero[4], "###.########.###.#.###.########.########.#.#####");
            strcpy(tablero[5], "#........#.......#...#......#....#.......#.....#");
            strcpy(tablero[6], "#.#######.#.#####.##########.#####.#.###.#.#.###");
            strcpy(tablero[7], "#.......#.#...#.#.....#..........#...#...#.#...#");
            strcpy(tablero[8], "#####.#.#####.#.###.#.##########.#####.###.#.###");
            strcpy(tablero[9], "##....#.#.#.....#...#.#.#..........#....#...#..#");
            strcpy(tablero[10],"###.#.#.#.#######.#.#.###########.#.#.#######.##");
            strcpy(tablero[11],"#...#.#...#.....#.#......#...#...#..#.#........#");
            strcpy(tablero[12],"#.#.#####.#.#.#.#####.##..#.#.#.#.#..#########.#");
            strcpy(tablero[13],"# #.....#.#.# #...#.....#.#...#.#.#.........#..#");
            strcpy(tablero[14],"###.#.#.###.###.#.#.#.###.#####.#####.#.#.#.#..#");
            strcpy(tablero[15],"#...#.#...#...#.#...#.#.......#.....#.#.#.#....#");
            strcpy(tablero[16],"###.#.#####.#####.###.#########.#.#.#.#.########");
            strcpy(tablero[17],"#...#.......#...#.#.........#.#.#.#.#...#......#");
            strcpy(tablero[18],"#.#######.#.#.#.#.#####.###.#.###########.##.#.#");
            strcpy(tablero[19],"#.......#.#.#...#.....#...#................#..X#");
			strcpy(tablero[20],"################################################");
            break;
    }//fin switch
    
    //recorre todo el mapa 
    for (int y = 0; y < dimensiones->filas; y++) {
        for (int x = 0; x < dimensiones->columnas; x++) {
            if (tablero[y][x] == 'P') {
                //guarda las coordenadas de P
                *coordenadaX = x;
                *coordenadaY = y;
                //cuando P se mueve deja un punto en su lugar 
                tablero[y][x] = '.';
            }else if (tablero[y][x] == 'X') {
                //guarda las coordenadas de X
                *salidaX = x;
                *salidaY = y;
            }//fin if-else
        }//fin for COLUMNAS
    }//fin for FILAS
}//fin funcion inicializarTablero 

int main() {
    srand(time(NULL));
    char tablero[FILAS][COLUMNAS];                    //almacena matriz del tablero
    int coordenadaX, coordenadaY, salidaX, salidaY;   //coordenas de P y X
    char tecla;                                       //almacena que tecla es la que se presiona
    Dimensiones dimensionesActuales;                  //almacena la dimensiones del tablero

    do{
      	int aleatorio = 0 + rand() % (5 - 0 + 1);     //aleatorio para escoger tablero

        inicializarTablero(tablero, &coordenadaX, &coordenadaY, &salidaX, &salidaY, aleatorio, &dimensionesActuales);
        
        mostrarLaberinto(tablero, coordenadaX, coordenadaY, &dimensionesActuales);            






        printf("\n¿Jugar de nuevo? (S/N): ");
        tecla = toupper(_getch()); 
    }while (tecla == 'S'); //ciclo verfica que se desea continuar

    return 0;
}//fin main

