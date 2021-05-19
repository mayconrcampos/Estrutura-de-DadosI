#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int dado;
    struct NO *proximo;
}NO;

typedef struct FILA {
    NO *inicio;
    NO *fim;
}FILA;

void enfileira(int dado, FILA *fila){
    int numero;
    NO *ptr = (NO*) malloc(sizeof(NO));
    if(ptr == NULL){
        printf("Erro de alocação.\n");
        return;
    }else{
        ptr->dado = dado;
        ptr->proximo = NULL;
        if(fila->inicio == NULL){
            fila->inicio = ptr;
        }else{
            fila->fim->proximo = ptr;
        }
        fila->fim = ptr;
    }
}

void desenfileirar(FILA *fila){
    
}
