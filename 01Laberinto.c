
//MATERIA: LENGUAJE ENSAMBLADOR
//PROYECTO FINAL: LABERINTO
//MATERIA: LENGUAJE ENSAMBLADOR
//PROYECTO FINAL: LABERINTO
//INTEGRANTES : ACOSTA VILLALPANDO ALVARO ALEXIS
//              HERNANDEZ RODRIGUEZ ITALIA LUCERO
//              ROSALES SANTOS ANDREA ELIZABETH

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
#define TIEMPO_LIMITE_NIVEL_FINAL 60

//colores
#define ROJO "\x1B[31m"
#define VERDE "\x1B[32m"
#define AZUL "\x1B[34m"
#define AMARILLO "\x1B[33m"
#define RESET "\x1B[0m"

//guarda las dimensiones del laberinto
typedef struct {
    int filas;
    int columnas;
} Dimensiones;

//funcion en NAMS
extern void funcionLaberintoASM(char tablero[FILAS][COLUMNAS], int x, int y, Dimensiones *dimensiones);

//funcion permite imprimir mas lento
void delay(int milliseconds) {
    Sleep(milliseconds);
}

//funcion que inicaliza el tablero
void inicializarTablero(char tablero[FILAS][COLUMNAS], int *coordenadaX, int *coordenadaY, 
                       int *salidaX, int *salidaY, int opcion, Dimensiones *dimensiones){
    //limpia el tablero 
    memset(tablero, '#', sizeof(char) * FILAS * COLUMNAS);
    
    //se elige el tablero segun el aleatorio
    switch (opcion){
        case 1:
            dimensiones->filas = 10;                    //guarda las dimensiones del tablero
            dimensiones->columnas = 28;
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
        case 2:
            dimensiones->filas = 14;                    //guarda las dimensiones del tablero
            dimensiones->columnas = 35;
            strcpy(tablero[0], "#################################");
            strcpy(tablero[1], "#P..............................#");
            strcpy(tablero[2], "#.#####.#######################.#");
            strcpy(tablero[3], "#.#.....#.......#..........##...#");
            strcpy(tablero[4], "#.#.###.#.##.##.#.###.#######.#.#");
            strcpy(tablero[5], "#...#...#....##.#####.##......#.#");
            strcpy(tablero[6], "#####.###.#####.......#######.#.#");
            strcpy(tablero[7], "#.....###.#..########.#...###.#.#");
            strcpy(tablero[8], "#.####..#.##.......##.#.#.###.#.#");
            strcpy(tablero[9], "#.##...##.##.#####..#...#.....#.#");
            strcpy(tablero[10],"#.##.##.#.##.#...########.#####.#");
            strcpy(tablero[11],"#.......#X##.#.#.......##.#...#.#");
            strcpy(tablero[12],"#.#####..#......####...##...#...#");
            strcpy(tablero[13],"#################################");
            break;
        case 0:
            dimensiones->filas = 15;                    //guarda las dimensiones del tablero
            dimensiones->columnas = 38;
            strcpy(tablero[0],"######################################");
            strcpy(tablero[1],"#X........#.........####.##.####.....#");
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
            strcpy(tablero[13],"#.#.....#.#.# #...#.....#.#...#.#.#.........#..#");
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
        Beep(500, 75);
    }else{
        Beep(200, 75);
    }
    
}//fin funcion teclaMover

int main() {
    srand(time(NULL));
    char tablero[FILAS][COLUMNAS];                    //almacena matriz del tablero
    int coordenadaX, coordenadaY, salidaX, salidaY;   //coordenas de P y X
    char tecla;                                       //almacena que tecla es la que se presiona
    Dimensiones dimensionesActuales;                  //almacena la dimensiones del tablero
     //variables extras 
    time_t inicio_tiempo_nivel_final = 0;
    bool temporizador_activo = false;

    //configura consola para UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    //entrada
	printf(AZUL"\n======================================================================================================================"RESET);
	printf(AZUL"\n                                                  J U E G O    D E L                                                  "RESET);
	printf(AZUL"\n======================================================================================================================"RESET);
	printf("\n     ##        ##########  ########   #########  #########   ############  ###     ##  ############  ############     "RESET);
	printf("\n     ##        ##      ##  ##     ##  ##         ##      ##       ##       ####    ##       ##       ##        ##     "RESET);
	printf("\n     ##        ##      ##  ##     ##  ##         ##      ##       ##       ## ##   ##       ##       ##        ##     "RESET);
	printf("\n     ##        ##########  #########  #########  #########        ##       ##  ##  ##       ##       ##        ##     "RESET);
	printf("\n     ##        ##      ##  ##     ##  ##         ##      ##       ##       ##   ## ##       ##       ##        ##     "RESET);
	printf("\n     ##        ##      ##  ##     ##  ##         ##      ##       ##       ##    ####       ##       ##        ##     "RESET);
	printf("\n     ########  ##      ##  ########   #########  ##      ##   ###########  ##     ###       ##       ############     "RESET);
	printf(AZUL"\n======================================================================================================================");
	printf("\nINSTRUCCIONES: EL JUGADOR (P) DEBE ENCONTRAR LA SALIDA (X) DEL LABERINTO");
	printf("\nCONTROLES: W - ARRIBA, S - ABAJO, A - IZQUIERDA, D - DERECHA, R - REINICIAR, Q - SALIR");
	printf("\nPRESIONA CUALQUIER TECLA PARA COMENZAR!!!"RESET);
    Beep(523, 300);  
    Beep(659, 300);  
    Beep(784, 300);  
    Beep(1046, 500); 
    Beep(784, 300); 
    Beep(659, 300);  
    Beep(523, 500);
    delay(2000);
    _getch();

    //do si el jugador quiere seguir jugando
    do{
      	int opcion; //= 0 + rand() % (5 - 0 + 1);     aleatorio para escoger tablero

        //do, valida que la opcion exista en el menu
        do{
            //menu
            system("cls");
            printf(VERDE"\n                                   ###     ###  ##########  ###      ##  ##      ##                                   "RESET);
            printf(VERDE"\n                                   ## #   # ##  ##          ####     ##  ##      ##                                   "RESET);
            printf(VERDE"\n                                   ##  # #  ##  ##          ##  #    ##  ##      ##                                   "RESET);
            printf(VERDE"\n                                   ##   #   ##  ########    ##   #   ##  ##      ##                                   "RESET);
            printf(VERDE"\n                                   ##       ##  ##          ##    #  ##  ##      ##                                   "RESET);
            printf(VERDE"\n                                   ##       ##  ##          ##     ####  ##      ##                                   "RESET);
            printf(VERDE"\n                                   ##       ##  ##########  ##      ###  ##########                                   "RESET);
            printf("\n");
            printf("1. TABLERO REGALADO\n");
            printf("2. TABLERO FACIL\n");
            printf("3. TABLERO INTERMEDIO\n");
            printf("4. TABLERO DIFICIL\n");
            printf("Elige una opcion o Q para salir: "); 
            Beep(1046, 500); 
            Beep(784, 300); 
            Beep(659, 300);  
            Beep(523, 500);
            delay(2000);

            tecla = _getch();
            
            //if, condicional si quiere seguir jugando
            if (toupper(tecla) == 'Q') {
                system("cls");
                printf(VERDE"\n                         ######  ########    #######    #######   ##########   #######    #####                       ");
                printf("\n                        ##       ##     ##  ##     ##  ##     ##      ##      ##     ##  ##                           ");
                printf("\n                        ##       ##     ##  ##     ##  ##             ##      ##     ##  ##                           ");
                printf("\n                        ##       ########   #########  ##             ##      #########   ####                        ");
                printf("\n                        ##  ###  ##   ##    ##     ##  ##             ##      ##     ##      ##                       ");
                printf("\n                        ##   ##  ##    ##   ##     ##  ##     ##      ##      ##     ##      ##                       ");
                printf("\n                         #####   ##     ##  ##     ##   #######   ##########  ##     ##  #####                        ");

                printf("\n\n                  ######    ######   #######          ########  ##    ##   ######   #######   #######                  ");
                printf("\n                  ##   ##  ##    ##  ##    ##            ##     ##    ##  ##       ##     ##  ##    ##                  ");
                printf("\n                  ##   ##  ##    ##  ##    ##            ##     ##    ##  ##       ##     ##  ##    ##                  ");
                printf("\n                  ######   ##    ##  #######             ##     ##    ##  ##       #########  #######                   ");
                printf("\n                  ##       ##    ##  ##  ##              ##     ##    ##  ##  ###  ##     ##  ##  ##                    ");
                printf("\n                  ##       ##    ##  ##   ##          ## ##     ##    ##  ##   ##  ##     ##  ##   ##                   ");
                printf("\n                  ##        ######   ##    ##          ###       ######    #####   ##     ##  ##    ##                  "RESET);
                Beep(523, 300);  
                Beep(587, 300);  
                Beep(659, 300);  
                Beep(698, 300);  
                Beep(659, 300);  
                Beep(587, 300);  
                Beep(523, 500);
                delay(2000);

                system("pause");
                return 0; 
            }//fin if

            opcion = tecla - '0';                     // Converte el caracter a entero

            opcion--;                                 //resta uno para que coincida con 0-3
            
            //if, valida que sea diferente opcion para que regrese a elegir otro numero 
            if (opcion < 0 || opcion > 3) {
                //delay(1500);
                system("cls");
                printf(ROJO"\n                              ##########  ##########   #########    ########  ##########                           "RESET);
                printf(ROJO"\n                              ##          ##       ##  ##      ##  ##      ## ##       ##                          "RESET);
                printf(ROJO"\n                              ##          ##       ##  ##      ##  ##      ## ##       ##                          "RESET);
                printf(ROJO"\n                              ########    ##########   #########   ##      ## ##########                           "RESET);
                printf(ROJO"\n                              ##          ##     ##    ##    ##    ##      ## ##     ##                            "RESET);
                printf(ROJO"\n                              ##          ##      ##   ##     ##   ##      ## ##      ##                           "RESET);
                printf(ROJO"\n                              ##########  ##       ##  ##      ##   ########  ##       ##                          "RESET);   
                printf(ROJO"\n\n                              SELECCION DE TABLERO INVALIDA. ELIGE OTRA OPCION DEL 1 AL 4                        \n"RESET);
                Beep(1000, 500); 
                Beep(800, 500);  
                Beep(600, 500); 
                delay(500);
            }//fin if
        }while(opcion < 0 || opcion > 3); //fin do-while MENU

        //llama a la funcion para tener control de los tableros
        inicializarTablero(tablero, &coordenadaX, &coordenadaY, &salidaX, &salidaY, opcion, &dimensionesActuales);
        
        bool jugador = true;                        //variable bool, controla el estado del jugador

        //reinicia variables para cada juego
        temporizador_activo = false;
        inicio_tiempo_nivel_final = 0;
        //si selecciona el tablero 3, se activa el temporizador
        if (opcion == 3) {
            temporizador_activo = true;
            inicio_tiempo_nivel_final = time(NULL); //guarda el tiempo de inicio
            printf(AZUL"\n¡Temporizador activado! Tienes %d segundos para encontrar el camino a la salida.\n"RESET, TIEMPO_LIMITE_NIVEL_FINAL);
            delay(2000); 
        }

        //while, actualiza la pantalla en cada movimiento y verifica si alguna condicion se cumple
        while(jugador){
            system("cls");

            //imprimi cual tablero es
            switch (opcion){
                    case 0:
                        printf("\n======================================================================================================================");
                        printf("\n                                           T A B L E R O   R E G A L A D O                                            ");
                        printf("\n======================================================================================================================\n");
                        break;
                    case 1:
                        printf("\n======================================================================================================================");
                        printf("\n                                              T A B L E R O   F A C I L                                               ");
                        printf("\n======================================================================================================================\n");
                        break;
                    case 2:       
                        printf("\n======================================================================================================================");
                        printf("\n                                         T A B L E R O   I N T E R M E D I O                                          ");
                        printf("\n======================================================================================================================\n");
                        break;
                    case 3:
                        printf("\n======================================================================================================================");
                        printf("\n                                            T A B L E R O   D I F I C I L                                             ");
                        printf("\n======================================================================================================================\n");
                        break;

            }//fin switch

            //llama la funcion
            funcionLaberintoASM(tablero, coordenadaX, coordenadaY, &dimensionesActuales);

            //verifica si es victoria o derrota
            if (temporizador_activo) {
                double tiempo_transcurrido = difftime(time(NULL), inicio_tiempo_nivel_final);
                int tiempo_restante = (int)(TIEMPO_LIMITE_NIVEL_FINAL - tiempo_transcurrido);
                printf("***********************");
                printf("\n* Tiempo: %d segundos *", tiempo_restante);
                printf("\n***********************");
                //if, verifica que tiempo restante sea < 0
                if (tiempo_restante <= 0) {
                    system("cls");
                    funcionLaberintoASM(tablero, coordenadaX, coordenadaY, &dimensionesActuales); // muestra por ultima vez el laberinto
                    system("cls");
                    printf(ROJO"\n                             ########  ########  #######  ##     ##  #######    #######                               "); 
                    printf("\n                                ##        ##     ##       #### ####  ##    ##  ##     ##                              ");
                    printf("\n                                ##        ##     ##       ## ### ##  ##    ##  ##     ##                              ");
                    printf("\n                                ##        ##     ####     ##  #  ##  #######   ##     ##                              ");
                    printf("\n                                ##        ##     ##       ##     ##  ##        ##     ##                              ");
                    printf("\n                                ##        ##     ##       ##     ##  ##        ##     ##                              ");
                    printf("\n                                ##     #######   #######  ##     ##  ##         #######                               ");
                    printf("\n\n                       #######   #######   #######   ########   #######   ########    #######                         ");
                    printf("\n                      ##     ##  ##       ##     ##     ##     ##     ##  ##     ##  ##     ##                        ");
                    printf("\n                      ##     ##  ##       ##     ##     ##     ##     ##  ##     ##  ##     ##                        ");
                    printf("\n                      #########  ##       ##     ##     ##     #########  ##     ##  ##     ##                        ");
                    printf("\n                      ##     ##  ##  ###  ##     ##     ##     ##     ##  ##     ##  ##     ##                        ");
                    printf("\n                      ##     ##  ##   ##  ##     ##     ##     ##     ##  ##     ##  ##     ##                        ");
                    printf("\n                      ##     ##   #####    #######      ##     ##     ##  ########    #######                         "RESET);
                    printf("\n                                      No lograste escapar del laberinto a tiempo                                    \n");
                    Beep(300, 500); // Sonido de tiempo agotado
                    delay(2000);
                    jugador = false; // El jugador perdió por tiempo
                    break; // Salir del bucle del juego actual
                }
            }//fin if

            //verifica si las coordenadas de P coinciden con las coordenas X
            //si son iguales significa que se llego a la salida del laberinto
            //jugador cambia a false por la cual se manda a la pregunta del do-while 
            if (coordenadaX == salidaX && coordenadaY == salidaY){
                system("cls");

                printf(AMARILLO"\n       #######  #######  ##      ########  #######  #########  #######    #######   #######   #######   ######        ");
                printf("\n       ##       ##       ##         ##     ##           ##     ##    ##  ##     ##  ##    ##  ##       ##             ");
                printf("\n       ##       ##       ##         ##     ##           ##     ##    ##  ##     ##  ##    ##  ##       ##             ");
                printf("\n       ####     #####    ##         ##     ##           ##     ##    ##  #########  ##    ##  #####     #####         ");
                printf("\n       ##       ##       ##         ##     ##           ##     ##    ##  ##     ##  ##    ##  ##            ##        ");
                printf("\n       ##       ##       ##         ##     ##           ##     ##    ##  ##     ##  ##    ##  ##            ##        ");
                printf("\n       ##       #######  ######  ########  #######  #########  #######   ##     ##  #######   #######  ######         ");

                printf("\n\n                        #######   #######   ###    ##   #######    ######  #########  #######                         ");
                printf("\n                        ##       ##     ##  ###    ##  ##     ##  ##          ##      ##                              ");
                printf("\n                        ##       ##     ##  ## #   ##  ##     ##  ##          ##      ##                              ");
                printf("\n                        ##       #########  ##  #  ##  #########   #####      ##      #####                           ");
                printf("\n                        ##  ###  ##     ##  ##   # ##  ##     ##       ##     ##      ##                              ");
                printf("\n                        ##   ##  ##     ##  ##    ###  ##     ##       ##     ##      ##                              ");
                printf("\n                        #######  ##     ##  ##    ###  ##     ##  ######      ##      #######                         "RESET);

                Beep(523, 80);
                delay(30);      
                Beep(659, 80);  
                delay(30);    
                Beep(784, 80);  
                delay(30);      

                Beep(880, 80); 
                delay(30);   
                Beep(988, 80); 
                delay(30);     
                Beep(1047, 80); 
                delay(30);    

                Beep(1047, 1000);
                
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
                    system("cls");
                    printf(VERDE"\n                ######    #######  ########  ###     ##  ########  #######  ########   #######   ######               ");
                    printf("\n                ##   ##   ##          ##     ####    ##     ##     ##          ##     ##     ##  ##   ##              ");
                    printf("\n                ##   ##   ##          ##     ## ##   ##     ##     ##          ##     ##     ##  ##   ##              ");
                    printf("\n                ######    #####       ##     ##  ##  ##     ##     ##          ##     #########  ######               ");
                    printf("\n                ## ##     ##          ##     ##   ## ##     ##     ##          ##     ##     ##  ## ##                ");
                    printf("\n                ##  ##    ##          ##     ##    ####     ##     ##          ##     ##     ##  ##  ##               ");
                    printf("\n                ##   ##   #######  ########  ##     ###  ########  #######  ########  ##     ##  ##   ##              "RESET);

                    Beep(659, 150);
                    Beep(587, 150);  
                    Beep(523, 150);  
                    Beep(493, 150);  
                    Beep(440, 300);
                    delay(500);
                    inicializarTablero(tablero, &coordenadaX, &coordenadaY, &salidaX, &salidaY, opcion, &dimensionesActuales);
                    break;
                //tecla para salir
                case 'Q':
                    system("cls");
                    printf(AZUL"\n                         ######  ########    #######    #######   ##########   #######    #####                       ");
                    printf("\n                        ##       ##     ##  ##     ##  ##     ##      ##      ##     ##  ##                           ");
                    printf("\n                        ##       ##     ##  ##     ##  ##             ##      ##     ##  ##                           ");
                    printf("\n                        ##       ########   #########  ##             ##      #########   ####                        ");
                    printf("\n                        ##  ###  ##   ##    ##     ##  ##             ##      ##     ##      ##                       ");
                    printf("\n                        ##   ##  ##    ##   ##     ##  ##     ##      ##      ##     ##      ##                       ");
                    printf("\n                         #####   ##     ##  ##     ##   #######   ##########  ##     ##  #####                        ");

                    printf("\n\n                  ######    ######   #######          ########  ##    ##   ######   #######   #######                  ");
                    printf("\n                  ##   ##  ##    ##  ##    ##            ##     ##    ##  ##       ##     ##  ##    ##                  ");
                    printf("\n                  ##   ##  ##    ##  ##    ##            ##     ##    ##  ##       ##     ##  ##    ##                  ");
                    printf("\n                  ######   ##    ##  #######             ##     ##    ##  ##       #########  #######                   ");
                    printf("\n                  ##       ##    ##  ##  ##              ##     ##    ##  ##  ###  ##     ##  ##  ##                    ");
                    printf("\n                  ##       ##    ##  ##   ##          ## ##     ##    ##  ##   ##  ##     ##  ##   ##                   ");
                    printf("\n                  ##        ######   ##    ##          ###       ######    #####   ##     ##  ##    ##                  "RESET);
                    Beep(523, 300);  
                    Beep(587, 300);  
                    Beep(659, 300);  
                    Beep(698, 300);  
                    Beep(659, 300);  
                    Beep(587, 300);  
                    Beep(523, 500);
                    delay(2000);
	                printf("\n");

                    system("pause");
                    return 0;
                default:
                    system("cls");
                    printf(ROJO"\n                              ##########  ##########   #########    ########  ##########                           ");
                    printf("\n                              ##          ##       ##  ##      ##  ##      ## ##       ##                          ");
                    printf("\n                              ##          ##       ##  ##      ##  ##      ## ##       ##                          ");
                    printf("\n                              ########    ##########   #########   ##      ## ##########                           ");
                    printf("\n                              ##          ##     ##    ##    ##    ##      ## ##     ##                            ");
                    printf("\n                              ##          ##      ##   ##     ##   ##      ## ##      ##                           ");
                    printf("\n                              ##########  ##       ##  ##      ##   ########  ##       ##                          ");   
                    printf("\n\n                                             SELECCIONA OTRA TECLA                                               ");
	                printf("\n                        W - ARRIBA, S - ABAJO, A - IZQUIERDA, D - DERECHA, R - REINICIAR, Q - SALIR              \n"RESET);

                    Beep(1000, 500); 
                    Beep(800, 500);  
                    Beep(600, 500); 
                    delay(500);
                    break;
            }//fin switch
            delay(50);
        }//fin while

        printf("\n¿Jugar de nuevo? (S/N): ");
        tecla = toupper(_getch()); 

        while (tecla != 'S' && tecla != 'N') {
            printf("\nEntrada invalida. Por favor, presiona 'S' o 'N': ");
            tecla = toupper(_getch());
        }
    }while (tecla == 'S'); //ciclo verfica que se desea continuar
     system("cls");
    printf(AMARILLO"\n                         ######  ########    #######    #######   ##########   #######    #####                       ");
    printf("\n                        ##       ##     ##  ##     ##  ##     ##      ##      ##     ##  ##                           ");
    printf("\n                        ##       ##     ##  ##     ##  ##             ##      ##     ##  ##                           ");
    printf("\n                        ##       ########   #########  ##             ##      #########   ####                        ");
    printf("\n                        ##  ###  ##   ##    ##     ##  ##             ##      ##     ##      ##                       ");
    printf("\n                        ##   ##  ##    ##   ##     ##  ##     ##      ##      ##     ##      ##                       ");
    printf("\n                         #####   ##     ##  ##     ##   #######   ##########  ##     ##  #####                        ");

    printf("\n\n                  ######    ######   #######          ########  ##    ##   ######   #######   #######                  ");
    printf("\n                  ##   ##  ##    ##  ##    ##            ##     ##    ##  ##       ##     ##  ##    ##                  ");
    printf("\n                  ##   ##  ##    ##  ##    ##            ##     ##    ##  ##       ##     ##  ##    ##                  ");
    printf("\n                  ######   ##    ##  #######             ##     ##    ##  ##       #########  #######                   ");
    printf("\n                  ##       ##    ##  ##  ##              ##     ##    ##  ##  ###  ##     ##  ##  ##                    ");
    printf("\n                  ##       ##    ##  ##   ##          ## ##     ##    ##  ##   ##  ##     ##  ##   ##                   ");
    printf("\n                  ##        ######   ##    ##          ###       ######    #####   ##     ##  ##    ##                  "RESET);
    Beep(523, 300);  
    Beep(587, 300);  
    Beep(659, 300);  
    Beep(698, 300);  
    Beep(659, 300);  
    Beep(587, 300);  
    Beep(523, 500);
    delay(2000); 

    printf("\n");
    system("pause");
    return 0;
}//fin main