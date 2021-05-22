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
    int GAPS[3] = {3, 2, 1};
    int g, i, j, k, chave;
    for(g = 1; g < 4; g++){
        k = GAPS[g];
        i = k + 1;
        while(i < tamanho){
            chave = vet[i];
            j = i;
            while(j >= k && vet[j - k] > chave){
                vet[j] = vet[j - k];
                j = j - k;
            }
            vet[j] = chave;
            i++;
        }
    }
}

void mostraVetor(int *vet, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vet[i]);
    }printf("\n");
}
