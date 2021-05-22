#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheVetor(int *vet, int tamanho);
void shellSort(int *vet, int tamanho);
void mostraVetor(int *vet, int tamanho);

int main(){
    int vetor[10];
    int opc, tam;

    do{
        printf("---- Algoritmo de Ordenação - ShellSort ----\n\n");
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

            printf("Fazendo ordenação com ShellSort...\n\n\n");
            shellSort(vetor, tam);

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

void shellSort(int *vet, int tamanho){
    int i, j, valor, qtd = 0;
    int gap = 1;
    do{
        gap = 3 * gap + 1;
    } while (gap < tamanho);
    do{
        gap /= 3;
        for(i = gap; i < tamanho; i++){
            valor = vet[i];
            j = i - gap;
            while(j >= 0 && valor < vet[j]){
                vet[j + gap] = vet[j];
                j -= gap;
                qtd++;
            }
            vet[j + gap] = valor;
        }
    } while (gap > 1);
}

void mostraVetor(int *vet, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vet[i]);
    }printf("\n");
}
