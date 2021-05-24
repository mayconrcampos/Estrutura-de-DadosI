#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * Algoritmo QuickSort implementado em C seguindo
 * exatamente a mesma lógica do pseudo-código
 * apresentado na aula 15 pelo prof. Pietro.
*/

void preencheVetor(int *vet, int tamanho);
void QuickSort(int *vet, int inicio, int fim);
int partition(int *vetor, int inicio, int fim);
void mostraVetor(int *vet, int tamanho);

int main(){
    int vetor[1000000];
    int opc, tam;

    do{
        printf("---- Algoritmo de Ordenação - QuickSort ----\n\n");
        printf("1. Gera e imprime Vetor\n");
        printf("0. Sair");
        scanf("%d", &opc);
        setbuf(stdin, NULL);
        system("clear");

        switch (opc){
        case 0:
            printf("Você saiu do programa!\n");
            break;
        case 1:
            printf("Digite o número de elementos do vetor.\n");
            scanf("%d", &tam);
            setbuf(stdin, NULL);

            printf("Gerando Vetor com %d elementos.....\n\n\n", tam);
            preencheVetor(vetor, tam);
            printf("Imprimindo vetor Desordenado de %d elementos.\n", tam);
            mostraVetor(vetor, tam);

            printf("Fazendo ordenação com QuickSort...\n\n\n");
            QuickSort(vetor, 0, tam - 1);

            printf("Imprimindo vetor Ordenado\n");
            mostraVetor(vetor, tam);
            break;        
        default:
            printf("Opção Inválida.\n");
            break;
        }
        
    } while (opc != 0);
    


    return 0;
}

void preencheVetor(int *vet, int tamanho){
    srand(time(NULL));
    for(int i = 0; i < tamanho; i++){
        vet[i] = rand()%1000;
    }
}

void QuickSort(int *vet, int inicio, int fim){
    int meio;
    if(inicio < fim){
       meio = partition(vet, inicio, fim);
       QuickSort(vet, inicio, meio - 1);
       QuickSort(vet, meio + 1, fim);
    }
}

int partition(int *vetor, int inicio, int fim){
    int pivo, i;
    int aux, aux2 = 0;
    pivo = vetor[fim];
    i = inicio - 1;
    for(int j = inicio; j < fim; j++){
        if(vetor[j] <= pivo){
            i++;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }
    aux2 = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = aux2;
    return i + 1;
}

void mostraVetor(int *vet, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vet[i]);
    }printf("\n");
}
