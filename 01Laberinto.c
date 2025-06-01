
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
            printf("\nTABLERO 1\n");
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
            printf("\nTABLERO 2\n");
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
            printf("\nTABLERO 3\n");
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
            printf("\nTABLERO 4\n");
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

//funcion que verifica si el moviento tecleado cumple con las condiciones
bool teclaValida(char tablero[FILAS][COLUMNAS], int x, int y, Dimensiones dim){
    //verifica que P no pase del limite de columnas o filas
    if (x < 0 || x >= dim.columnas || y < 0 || y >= dim.filas)
        return false;

    //retorna true si la posicion contine '.' o 'X'
    return (tablero[y][x] == '.' || tablero[y][x] == 'X');
}//fin funcion teclaValida

//funcion que mueve al jugador, guarda coordenadas y mantiene el control de la direccion
void teclaMover(char tablero[FILAS][COLUMNAS], int *coordenadaX, int *coordenadaY, 
               char direccion, Dimensiones dim){
    int nuevoX = *coordenadaX;                      //inicializa coordenadas
    int nuevoY = *coordenadaY;                      //inicializa coordenadas

    //cambia la coordenada segun la tecla
    switch (direccion) {
        case 'W': nuevoY--; break;
        case 'S': nuevoY++; break;
        case 'A': nuevoX--; break;
        case 'D': nuevoX++; break;
    }

    //se valida el nuevon movimiento
    if(teclaValida(tablero, nuevoX, nuevoY, dim)){
        *coordenadaX = nuevoX;
        *coordenadaY = nuevoY;
    }
}//fin funcion teclaMover

int main() {
    srand(time(NULL));
    char tablero[FILAS][COLUMNAS];                    //almacena matriz del tablero
    int coordenadaX, coordenadaY, salidaX, salidaY;   //coordenas de P y X
    char tecla;                                       //almacena que tecla es la que se presiona
    Dimensiones dimensionesActuales;                  //almacena la dimensiones del tablero

    //configura consola para UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    //do si el jugador quiere seguir jugando
    do{
      	int aleatorio = 0 + rand() % (5 - 0 + 1);     //aleatorio para escoger tablero

        //llama a la funcion para tener control de los tableros
        inicializarTablero(tablero, &coordenadaX, &coordenadaY, &salidaX, &salidaY, aleatorio, &dimensionesActuales);
        
        bool jugador = true;                        //variable bool, controla el estado del jugador

        //while, actualiza la pantalla en cada movimiento y verifica si alguna condicion se cumple
        while(jugador){
            system("cls");
            printf("\nJUEGO LABERINTO");
            printf("\nINSTRUCCIONES: EL JUGADOR (P) DEBE ENCONTRAR LA SALIDA (X) DEL LABERINTO");
	        printf("\nCONTROLES: W - ARRIBA, S - ABAJO, A - IZQUIERDA, D - DERECHA, R - REINICIAR, Q - SALIR");
	        printf("\n");

            mostrarLaberinto(tablero, coordenadaX, coordenadaY, &dimensionesActuales);            
            
            //verifica si las coordenadas de P coinciden con las coordenas X
            //si son iguales significa que se llego a la salida del laberinto
            //jugador cambia a false por la cual se manda a la pregunta del do-while 
            if (coordenadaX == salidaX && coordenadaY == salidaY){
                system("cls");
                printf("\nFELICIDADES GANASTE");
                jugador = false;
                break;
            }//fin if

            //recibe la tecla tecleada
            tecla = _getch();
            tecla = toupper(tecla);

            //segun la tecla se ejerce lo pedido
            switch (tecla){
                //teclas para mover P
                case 'W': case 'A': case 'S': case 'D':
                    teclaMover(tablero, &coordenadaX, &coordenadaY, tecla, dimensionesActuales);
                    break;
                //tecla para reiniciar 
                case 'R':
                    jugador = false;
                    break;
                //tecla para salir
                case 'Q':
                    system("cls");
                    printf("\nGRACIAS POR JUGAR");
                    return 0;
                default:
                    printf("\nTecla no valida. Usa WASD para moverte.");
                    break;
            }//fin switch
        }//fin while

        printf("\n¿Jugar de nuevo? (S/N): ");
        tecla = toupper(_getch()); 

        while (tecla != 'S' && tecla != 'N') {
            printf("\nEntrada invalida. Por favor, presiona 'S' o 'N': ");
            tecla = toupper(_getch());
        }
    }while (tecla == 'S'); //ciclo verfica que se desea continuar

    return 0;
}//fin main