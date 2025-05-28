 section .text
 global funcionLaberintoASM   ;etiqueta para llamar desde C
                              ;funciones externas de C

 funcionLaberintoASM:
     push rbp                 ;guarda el puntero de base en la pila
     mov rbp, rsp             ;copia puntero de pila a rbp, permite acceder a parametros y variables  
    push rbx                 
    push rdi                 
    push rsi                 
    push r12                 
    push r13                 
    push r14                 
    push r15                 ;guarda en la pila los registros
    
    ;copia los parametros en los registros
    mov rdi, rcx             ; tablero
    mov r12d, edx            ; coordenadaX
    mov r13d, r8d            ; coordenadaY
    
    pop r15
    pop r14
    pop r13
    pop r12
    pop rsi
    pop rdi
    pop rbx                  ;se restauran registros
     pop rbp                  ;restaura puntero de base 
     ret                      ;retorna a C donde fue llamado
