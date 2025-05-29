section .text
global funcionLaberintoASM      ;etiqueta para llamar desde C
                                ;funciones externas de C
extern putchar                  ;imprime un caracter
extern printf                   ;imprime formato

;definicion de constantes
%define MAX_FILAS 21
%define MAX_COLUMNAS 50

funcionLaberintoASM:
    push rbp                    ;guarda el puntero de base en la pila
    mov rbp, rsp                ;copia puntero de pila a rbp, permite acceder a parametros y variables  
    push rbx                 
    push rdi                 
    push rsi                 
    push r12                 
    push r13                 
    push r14                 
    push r15                    ;guarda en la pila los registros
    
    ;copia los parametros en los registros
    mov rdi, rcx                ; tablero
    mov r12d, edx               ; coordenadaX
    mov r13d, r8d               ; coordenadaY
    
    ;copia las dimensiones
    mov r14d, [r9]              ; dim.filas
    mov r15d, [r9+4]            ; dim.columnas
    
    ;se inicializa el contador de filas
    xor ebx, ebx                ; y = 0

;bucle de filas
filas_loop:
    cmp ebx, r14d               ;compara EBX (contador) con R14D (nuemro total de filas)
    jge fin_filas               ;si y >= que R14D salen del bucle

    ;se inicializa el contador de columnas
    xor esi, esi                ; x = 0

;bucle de columnas
columnas_loop:
    cmp esi, r15d               ;compara ESI (contador) con R15D (nuemro total de columnas)
    jge fin_columnas            ;si x >= que R15D salen del bucle columans
     
    cmp esi, r12d               ;verifica si X es la posición X del jugador
    jne no_jugador              ;si no coincide salta a no_jugador 
    cmp ebx, r13d               ;verifica si Y es la posición Y del jugador
    jne no_jugador              ;si no coincide salta a no_jugador 
    

    mov rcx, 'P'                ;copia 'P' para luego imprimirla
    call putchar                ;imprime el caracter 
    
    jmp siguiente_columna       ;salta al final del bucle para continuar con la sig columna
  
;funcion que muestra el contenido que hay en la posicion
no_jugador:
    ;calcula la posición en el tablero [y][x]
    mov eax, ebx                ;copia EAX(contador de filas) a EAX
    ;calcula el desplazamiento al inicio de la fila actual en la matriz
    imul eax, MAX_COLUMNAS      ;multplica EAX (Y) por MAX_COLUMNAS
    ;contiene el indice de la matriz
    add eax, esi                ;suma ESI(cont. columnas) al resultado anterior             
 
                                ;[rdi + rax] accede al byte en la posicion
                                ;movz carga byte y lo extiende a 32 bits con ceros, se guarda en ECX 
    movzx ecx, byte [rdi + rax] ;accede al caracter del tablero

    cmp cl, 0                   ;compara el byte de ECX con 0 
    je siguiente_columna        ;si es igual, salta a siguiente_columna
    
   call putchar                 ;llama a putchar que imprime caracter

;funcion que salta a la siguiente columna    
siguiente_columna: 
    inc esi                     ;incrementa contador
    jmp columnas_loop           ;regresa al inicio del bucle de columnas

;funcion para poner un salto de linea al terminar 
fin_columnas:
    mov rcx, 0Ah                ;copia salto de liena en RCX
    call putchar                ;llama a putchar que imprime caracter

    inc ebx                     ;incrementa 
    jmp filas_loop              ;regresa al inicio del bucle de filas

fin_filas:
    mov rcx, posicion_fmt       ;copia en RCX la direccion de memoria de la cadena de formato posicion_fmt
    mov edx, r12d               ;copia el valor de R12D (coordenaX) al EDX
    mov r8d, r13d               ;copia el valor de R13D (coordenaY) al rd8
    call printf                 ;llama a la funcion para mostrar mensaje
    
    pop r15
    pop r14
    pop r13
    pop r12
    pop rsi
    pop rdi
    pop rbx                     ;se restauran registros
    pop rbp                     ;restaura puntero de base 
    ret                         ;retorna a C donde fue llamado
    
section .data
posicion_fmt db 0Ah, "Posicion actual: (%d, %d)", 0Ah, 0