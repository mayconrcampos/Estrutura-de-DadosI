#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define tamanho 10000

int main(){
    int numeros[tamanho];
    int aux = 0;
    int numero = 0;
    int opt;
    srand(time(NULL));

    do{
        printf("\n\n\n\n\n\n\n\n\nOrdenação de Vetores com Bubble Sort!\n");
        printf("1. Gerar Vetor\n");
        printf("0. Sair\n");
        printf("Opção 1 ou 0 pra sair.\n");
        scanf("%d", &opt);
        setbuf(stdin, NULL);
        system("clear");

        switch (opt){
        case 0:
            printf("Você saiu do programa.\n");
            break;
        case 1:
            // Gerando números aleatórios e preenchendo o Vetor.
            for(int i = 0; i < tamanho; i++){
                numeros[i] = rand()%1000;
            }

            // Imprimindo Lista Desordenada;
            printf("Imprimindo Vetor Desordenado.\n");
            for(int i = 0; i < tamanho; i++){
                printf("%d, ", numeros[i]);
            }
            printf("\n\n");


            // Algoritmo de Ordenação de Vetor - Bubble Sort;
            printf("Ordenando Vetor . . . . .\n\n");
            for(int i = 0; i < tamanho; i++){
                for(int j = i + 1; j <= tamanho; j++){
                    if(numeros[i] > numeros[j]){
                        aux = numeros[i];
                        numeros[i] = numeros[j];
                        numeros[j] = aux;
                    }
                }
            }printf("Vetor Ordenado!\n\n\n\n");

            // Imprimindo vetor Ordenado;
            printf("Imprimindo Vetor Ordenado.\n");
            for (int i = 0; i < tamanho; i++){
                printf("%d, ", numeros[i]);
            }
            printf("\n");
            break;
                   
        default:
            printf("Opção Inválida!\n");
            break;
        }
    } while (opt != 0);
    
    return 0;
}