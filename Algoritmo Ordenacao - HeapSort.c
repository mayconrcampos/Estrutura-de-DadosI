#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * Algoritmo heapSort implementado em C seguindo
 * exatamente a mesma lógica do pseudo-código
 * apresentado na aula 15 pelo prof. Pietro.
 * 
 * Na primeira tentativa ele ordenada todos os números exceto a primeira posição do vetor desordenado, que ia para a ultima posição do vetor ordenado, não importanto o seu valor.
*/

void preencheVetor(int *vet, int tamanho);
void heapSort(int *vet, int fim);
void constroiHeap(int *vetor, int fim);
void heapIfica(int * vetor, int fim, int i);
void mostraVetor(int *vet, int tamanho);

int main(){
    int vetor[1000000];
    int opc, tam;

    do{
        printf("---- Algoritmo de Ordenação - heapSort ----\n\n");
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

            printf("Fazendo ordenação com heapSort...\n\n\n");
            heapSort(vetor, tam-1);

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

void heapSort(int *vet, int fim){
    int n, i, aux;
    n = fim;
    constroiHeap(vet, fim);
    for(i = n; n > 0; i--){
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        n--;
        heapIfica(vet, n, 0);
    }
}

void constroiHeap(int *vetor, int fim){
    for(int i = fim / 2; i >= 0; i--){
        heapIfica(vetor, fim, i);
    }
}

void heapIfica(int * vetor, int fim, int i){
    int e, d, aux, maior;
    e = 2 * i + 1;
    d = 2 * i + 2;
    if(e <= fim && vetor[e] > vetor[i]){
        maior = e;
    }else{
        maior = i;
    }
    if(d <= fim && vetor[d] > vetor[maior]){
        maior = d;
    }
    if(maior != i){
        aux = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = aux;
        heapIfica(vetor, fim, maior);
    }
}

void mostraVetor(int *vet, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vet[i]);
    }printf("\n");
}
