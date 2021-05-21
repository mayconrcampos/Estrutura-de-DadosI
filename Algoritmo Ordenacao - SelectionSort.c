#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#define tamanho 10

void imprimeVetor(int *vetor, int tamanho);
void preencheVetor(int *vetor, int tamanho);
void selectionSort(int *vetor, int tamanho);

int main(){
    int vetor[10];
    int opt, tamanho;

    do{
        printf("-------------------------\n");
        printf("**** SelectionSort ******\n");
        printf("-------------------------\n");
        printf("1. Gera Vetor e Imprime\n");
        printf("0. Sair\n");
        printf("Opção: 1-2 ou 0 pra sair\n");
        scanf("%d", &opt);
        setbuf(stdin, NULL);
        system("clear");

        switch (opt){
        case 0:
            printf("Você saiu do Programa.\n");
            break;
        case 1:
            printf("Digite o tamanho do vetor: \n");
            scanf("%d", &tamanho);
            setbuf(stdin, NULL);
            printf("****************************************************************\n");
            printf("********* Gerando Vetor com %d números aleatórios **************\n", tamanho);
            preencheVetor(vetor, tamanho);
            printf("****************************************************************\n\n\n\n\n");
            printf("*********************************************************\n");
            printf("************   Imprimindo Vetor Desordenado  ************\n");
            printf("*********************************************************\n");
            imprimeVetor(vetor, tamanho);

            printf("************************************************************************\n");
            printf("**********  Ordenando e imprimindo Vetor com SelectionSort() ***********\n");
            printf("************************************************************************\n");
            selectionSort(vetor, tamanho);

            imprimeVetor(vetor, tamanho);
            break;
        default:
            printf("Opção Inválida!\n\n\n\n\n");
            break;
        }
    } while (opt != 0);
     
}

void imprimeVetor(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vetor[i]);
    }printf("\n\n");
}

void preencheVetor(int *vetor, int tamanho){
    srand(time(NULL));
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand()%1000;
    }
}

void selectionSort(int *vetor, int tamanho){
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
}