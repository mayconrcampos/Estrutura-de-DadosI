#include <stdio.h>
#include <stdlib.h>

/*
    ALGORITMO DE BUSCA SEQUENCIAL EM VETORES.
*/

int busca(int vet[], int tam, int arg){
    for(int i = 0; i < tam; i++){
        if(arg == vet[i]){
            printf("Número: %d | Encontrado no Índice: %d \n", arg, i);
            return i;
        }
        
    }
    printf("Número %d não existe no vetor.\n", arg);
    return -1;
}

int main(){
    int num = 0;
    int continua;
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    do
    {
        printf("Digite um número pra buscar: ");
        scanf("%d", &num);
        busca(vetor, 10, num);

        printf("\nQuer continuar?\n1. SIM\n0. Sair\n");
        scanf("%d", &continua);

    } while (continua != 0);
    printf("Você saiu do Programa.\n\n");
    
    return 0;
}
