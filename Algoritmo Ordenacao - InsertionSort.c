#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void preencheVetor(int *vet, int comp){
    srand(time(NULL));
    for(int i = 0; i < comp; i++){
        vet[i] = rand()%1000;
    }
}

void insertionSort(int *vet, int comp){
    int j, chave;
    for(int i = 2; i < comp; i++){
        chave = vet[i];
        j = i - 1;
        while(j > -1 && vet[j] > chave){
            vet[j + 1] = vet[j];
            j--;
        }vet[j + 1] = chave;
    }
}

void imprimeVetor(int *vet, int comp){
    for(int i = 0; i < comp; i++){
        printf("%d, ", vet[i]);
    }printf("\n\n");
}

int main(){
    int vetor[10];
    int opt, comprimento;

    do{
        printf("1. Preencher e Imprimir Vetor\n");
        printf("0. Sair\n");
        printf("Opção: 1 ou 0 pra sair\n");
        scanf("%d", &opt);
        system("clear");
        setbuf(stdin, NULL);

        switch (opt){
        case 0:
            printf("Você saiu do programa.\n");
            break;
        case 1:
            printf("Digite o tamanho do Vetor:\n");
            scanf("%d", &comprimento);
            system("clear");
            setbuf(stdin, NULL);

            printf("Gerando Vetor de números aleatórios com %d elementos.\n", comprimento);
            preencheVetor(vetor, comprimento);

            printf("Imprimindo Vetor Desordenado.\n\n");
            imprimeVetor(vetor, comprimento);

            printf("Ordenando Vetor com InsertionSort()...\n\n");
            insertionSort(vetor, comprimento);

            printf("Imprimindo Vetor Ordenado.\n");
            imprimeVetor(vetor, comprimento);
            break;
        
        default:
        printf("Opção inválida!\n\n\n");
            break;
        }
    } while (opt != 0);
    
    return 0;
}