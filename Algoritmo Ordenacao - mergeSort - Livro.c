#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Este algoritmo funciona perfeitamente bem.

void geraVetor(int *vet, int tamanho);
int mergeSort(int *vetor, int tam, int qtd);
void merge(int *vetor, int tam);
void imprimeVetor(int *vetor, int tamanho);

int main(){
    int opc;
    int tam;
    int vetor[100000];

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
            mergeSort(vetor, tam, 1);

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
        vet[i] = rand()%10000;
    }
}

int mergeSort(int *vetor, int tam, int qtd){
    int meio;
    if(tam > 1){
        meio = tam / 2;
        qtd = mergeSort(vetor, meio, qtd);
        qtd = mergeSort(vetor + meio, tam - meio, qtd);
        merge(vetor, tam);
    }
    return (qtd + 1);
}

void merge(int *vetor, int tam){
    int i, j, k;
    int meio;
    int *tmp;

    tmp = (int*) malloc(tam * sizeof(int));
    if(tmp == NULL){
        exit (1);
    }
    meio = tam / 2;
    i = 0;
    j = meio;
    k = 0;

    while (i < meio && j < tam){
        if(vetor[i] < vetor[j]){
            tmp[k] = vetor[i];
            ++i;
        }else{
            tmp[k] = vetor[j];
            ++j;
        }++k;
    }

    if(i == meio){
        while (j < tam){
            tmp[k] = vetor[j];
            ++j;
            ++k;
        }
        
    }else{
        while(i < meio){
            tmp[k] = vetor[i];
            ++i;
            ++k;
        }
    }

    for(i = 0; i < tam; i++){
        vetor[i] = tmp[i];
    }
    free(tmp);
    
    
}

void imprimeVetor(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vetor[i]);
    }printf("\n");
}

