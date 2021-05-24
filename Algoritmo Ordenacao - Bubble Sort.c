#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define tamanho 20

void geraVetor(int *vetor);
void bubbleSort(int *vetor);
void imprimeVetor(int *vetor);

int main(){
    
    int opt;
    int numeros[tamanho];

    do{
        printf("\n\n\n\n\n\n\n-------------------------------------------------------\n");
        printf("******* Ordenação de Vetores com Bubble Sort!**********\n");
        printf("-------------------------------------------------------\n");
        printf("1. Gerar Vetor\n");
        printf("0. Sair\n");
        printf("Opção 1 ou 0 pra sair.\n");
        scanf("%d", &opt);
        setbuf(stdin, NULL);
        system("clear");

        switch (opt){
        case 0:
            printf("Você saiu do programa.\n");
            break;
        case 1:
            printf("Gerando vetor de %d elementos:\n", tamanho);
            geraVetor(numeros);

            printf("Imprimindo Vetor desordenado.\n");
            imprimeVetor(numeros);

            printf("Ordenando Vetor com bubbleSort.\n");
            bubbleSort(numeros);

            printf("Imprimindo Vetor ordenado.\n");
            imprimeVetor(numeros);
            break; 
        default:
            printf("Opção Inválida!\n");
            break;
        }
    } while (opt != 0);
    
    return 0;
}

void geraVetor(int *vetor){
    srand(time(NULL));
    // Gerando números aleatórios e preenchendo o Vetor.
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand()%1000;
    }
}

void bubbleSort(int *vetor){
    int aux = 0;
    // Algoritmo de Ordenação de Vetor - Bubble Sort;
    for(int i = 0; i < tamanho; i++){
        for(int j = i + 1; j < tamanho; j++){
            if(vetor[i] > vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void imprimeVetor(int *vetor){
    // Imprimindo Lista Desordenada;
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vetor[i]);
    }
    printf("\n\n");
}