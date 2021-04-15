#include <stdio.h>
#include <stdlib.h>

/* Implementação de uma PILHA */

#define tamanho 5

typedef struct{
    int dados[tamanho];
    int inicio;
    int topo;
} tipo_pilha;

tipo_pilha pilha;

void empilha(int elemento){
    if(pilha.topo == tamanho){
        printf("Fila cheia.\n");
    }else{
        pilha.dados[pilha.topo] = elemento;
        pilha.topo++;
    }
}

int desempilha(){
    int elemento;
    if(pilha.topo == pilha.inicio){
        printf("Fila Vazia. \n");
    }else{
        pilha.dados[pilha.topo - 1] = 0;
        pilha.topo--;
        elemento = pilha.dados[pilha.topo];
        return elemento;
    }
}

int main(){
    pilha.inicio = 0;
    pilha.topo = 0;

    empilha(5);
    empilha(7);


    printf("Empilhou dois elementos\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d \n", pilha.dados[i]);
    }

    desempilha();
    desempilha();
    empilha(45);
    empilha(98);
    empilha(150);


    printf("desempilhou 2 elementos, empilhou 3. \n");
    for(int i = 0; i < tamanho; i++){
        printf("%d \n", pilha.dados[i]);
    }

    return 0;
}


