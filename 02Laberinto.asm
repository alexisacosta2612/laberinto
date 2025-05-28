section .text
 global funcionLaberintoASM     ;etiqueta para llamar desde C
                                ;funciones externas de C
 extern putchar                 ;imprime un caracter

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
    
    inc esi                     ;incrementa contador
    jmp columnas_loop           ;regresa al inicio del bucle de columnas

;funcion para poner un salto de linea al terminar 
fin_columnas:
    mov rcx, 0Ah                ;copia salto de liena en RCX
    call putchar                ;llama a putchar que imprime caracter

    inc ebx                     ;incrementa 
    jmp filas_loop              ;regresa al inicio del bucle de filas

fin_filas:
    pop r15

    pop r14
    pop r13
    pop r12
    pop rsi
    pop rdi
    pop rbx                     ;se restauran registros
    pop rbp                     ;restaura puntero de base 
    ret                         ;retorna a C donde fue llamado
