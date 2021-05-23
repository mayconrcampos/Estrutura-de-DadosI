#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//#define tam 20;

// Funciona mais ou menos

void geraVetor(int *vet, int tamanho);
void mergeSort(int *vetor, int inicio, int fim);
void merge(int *vetor, int inicio, int meio, int fim);
void imprimeVetor(int *vetor, int tamanho);

int main(){
    int opc;
    int tam;
    int vetor[100];

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
            printf("Digite o número de elementos do vetor: \n");
            scanf("%d", &tam);
            setbuf(stdin, NULL);

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
        meio = floor((inicio + fim) / 2);
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void merge(int *vetor, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i , j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int *) malloc(tamanho * sizeof(int));
    if(temp != NULL){
        for(i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                if(vetor[p1] < vetor[p2]){
                    temp[i] = vetor[p1++];
                }else{
                    temp[i] = vetor[p2++];
                }
                if(p1 > meio) fim1 = 1;
                if(p2 > fim) fim2 = 1;
            }else{
                if(!fim1){
                    temp[i] = vetor[p1++];
                }else{
                    temp[i] = vetor[p2++];
                }
            }
        }
        for(j = 0, k = inicio; j < tamanho; j++, k++){
            vetor[k] = temp[j];
        }
    }
    free(temp);
}

void imprimeVetor(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vetor[i]);
    }printf("\n");
}

