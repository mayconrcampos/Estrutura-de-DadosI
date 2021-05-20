#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tamanho 10


int main(){
    int vetor[tamanho];
    srand(time(NULL));

    printf("Gerando Vetor com %d números aleatórios:\n", tamanho);
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand()%100;
    }

    printf("Imprimindo Vetor desordenado:\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vetor[i]);
    }printf("\n");

    // Algoritmo de Ordenação SelectionSort
    int min, aux;
    int i, j;
    for(i = 0; i < tamanho-1; i++) {
        min = i;
        for(j = i + 1; j <= tamanho; j++){
            if(vetor[j] < vetor[min]){
                min = j;
            }
        }
        if(i != min){
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }

    printf("Imprimindo Vetor Ordenado:\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vetor[i]);
    }
    printf("\n");
}

