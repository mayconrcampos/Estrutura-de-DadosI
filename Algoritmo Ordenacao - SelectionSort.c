#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tamanho 100


int main(){
    int vetor[tamanho];
    srand(time(NULL));
    int opt;

    do{
        printf("-------------------------\n");
        printf("**** SelectionSort ******\n");
        printf("-------------------------\n");
        printf("1. Gera Vetor e Imprime\n");
        printf("2. Ordena e Imprime\n");
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
            printf("Gerando Vetor com %d números aleatórios:\n", tamanho);
            for(int i = 0; i < tamanho; i++){
                vetor[i] = rand()%1000;
            }

            printf("Imprimindo Vetor desordenado:\n");
            for(int i = 0; i < tamanho; i++){
                printf("%d, ", vetor[i]);
            }printf("\n");
            break;
        case 2:
            printf("Imprimindo Vetor desordenado:\n");
            for(int i = 0; i < tamanho; i++){
                printf("%d, ", vetor[i]);
            }printf("\n\n\n\n");

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
            printf("Imprimindo Vetor Ordenado:\n");
            for(int i = 0; i < tamanho; i++){
                printf("%d, ", vetor[i]);
            }
            printf("\n");
            break;
        default:
            printf("Opção Inválida!\n");
            break;
        }
    } while (opt != 0);
     
}

