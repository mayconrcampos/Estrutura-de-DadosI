#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//#define tam 20;

// Não funciona.

void geraVetor(int *vet, int tamanho);
void mergeSort(int *vetor, int inicio, int fim);
void merge(int *vetor, int inicio, int meio, int fim);
void imprimeVetor(int *vetor, int tamanho);

int main(){
    int opc;
    int tam = 10;
    int vetor[10];

    do{
        printf("1. Gerar e imprimir vetor.\n");
        printf("0. Sair\n");
        printf("Opção: 1 ou 0 pra sair.\n");
        scanf("%d", &opc);
        setbuf(stdin, NULL);
        system("clear");

        switch (opc){
        case 0:
            printf("Você saiu do programa.\n");
            break;
        case 1:
            //printf("Digite o número de elementos do vetor: \n");
            //scanf("%d", &tam);
            //setbuf(stdin, NULL);

            printf("Gerando Vetor com %d elementos.\n", tam);
            geraVetor(vetor, tam);

            printf("Imprimindo Vetor Desordenado.\n");
            imprimeVetor(vetor, tam);
            

            printf("Ordenando Vetor com mergeSort\n");
            mergeSort(vetor, 0, tam);

            printf("Imprimindo Vetor Ordenado com mergeSort\n");
            imprimeVetor(vetor, tam);

            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opc != 0);
    
    return 0;
}

void geraVetor(int *vet, int tamanho){
    srand(time(NULL));
    for(int i = 0; i < tamanho; i++){
        vet[i] = rand()%1000;
    }
}

void mergeSort(int *vetor, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio + fim)/2);
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void merge(int *vetor, int inicio, int meio, int fim){
    int geral, dir, esq, i;
    int *temp;
    temp = (int*) malloc(fim * sizeof(int));
    
    esq = inicio;
    dir = meio + 1;
    if(temp != NULL){
        for(i = 0; i < meio; i++){
            if(vetor[esq] < vetor[dir]){
                temp[i] = vetor[esq++];
            }else{
                temp[i] = vetor[dir++];
            }
        }
    }
    for(i = 0, geral = inicio; i < fim; i++, geral++){
        vetor[geral] = temp[i];
    }
    free(temp);
    
}

void imprimeVetor(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vetor[i]);
    }printf("\n");
}

