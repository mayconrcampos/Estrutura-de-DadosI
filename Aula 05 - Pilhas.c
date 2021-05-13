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
        printf("Pilha Vazia. \n");
    }else{
        pilha.dados[pilha.topo] = 0;
        pilha.topo--;
        elemento = pilha.dados[pilha.topo];
        printf("%d desempilhado.\n\n", pilha.dados[pilha.topo]);
        return elemento;
    }
}

void mostrar_pilha(){
    if(pilha.inicio == pilha.topo){
        printf("Pilha Vazia! Você precisa empilhar elementos.\n");
    }else{
        printf("\nMostrando Pilha: \n\n");
        for(int i = pilha.topo - 1; i >= pilha.inicio; i--){
            printf("=> %d \n", pilha.dados[i]);
        }
    }
    printf("\n\n\n");
}

int main(){
    pilha.inicio = 0;
    pilha.topo = 0;
    int opt, num;

    do{
        printf("Digite uma das opções:\n");
        printf("1. Empilhar\n");
        printf("2. Desempilhar\n");
        printf("3. Mostrar Pilha\n");
        printf("0. Sair\n");
        printf("Opção: 1 - 2 - 3 - 0 Sair\n");
        scanf("%d", &opt);
        system("clear");
        switch (opt){
        case 0:
            printf("Você Saiu do Programa!\n\n\n\n\n");
            break;
        case 1:
            printf("Opção 1. Empilhar!\n\n\n\n\n");
            printf("Digite um número para empilhar.\n");
            scanf("%d", &num);
            empilha(num);
            mostrar_pilha();
            break;
        case 2:
            printf("Opção 2. Desempilhar!\n\n\n\n\n");
            desempilha();
            mostrar_pilha();
            break;
        case 3:
            printf("Opção 3. Mostrar Pilha!\n\n\n\n\n");
            mostrar_pilha();
            break;
        default:
            printf("Opção Inválida!\n\n\n\n\n");
            break;
        }
        
    } while (opt != 0);
    
    return 0;
}


