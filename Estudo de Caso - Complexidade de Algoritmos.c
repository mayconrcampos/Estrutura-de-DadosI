#include <stdio.h>
#include <stdlib.h>

/*
    ALGORITMO DE BUSCA SEQUENCIAL EM VETORES.
*/

int busca(int vet[], int tam, int arg){
    int i;
    for(i = 0; i < tam; i++){
        if(arg == vet[i]){
            printf("arg: %d vet[i]: %d\n", arg, vet[i]);
            return i;
        }
        return -1;
    }
}

int main(){
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanho = sizeof(vetor) / sizeof(int);


    printf("%d \n\n", busca(vetor, tamanho, 2));

    return 0;
}

