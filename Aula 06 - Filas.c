#include <stdio.h>
#include <stdlib.h>

#define tamanho 5

typedef struct {
    int dados[tamanho];
    int ini;
    int fim;
}tipo_fila;

tipo_fila fila;

void enfileira(int elemento){
    if(fila.fim == tamanho){
        printf("Fila cheia.\n");
    }else{
        fila.dados[fila.fim] = elemento;
        fila.fim++;
    }
}

void desenfileira(){
    if(fila.fim == 0){
        printf("Fila vazia.\n");
    }else{
        for(int i = 0; i < fila.fim; i++){
            fila.dados[i] = fila.dados[i + 1];

        }fila.fim--;
    }
}

void mostra_fila(){
    printf("Mostrando FILA: \n\n");
    if(fila.fim == 0){
        printf("Fila Vazia!\n");
    }else{
        printf("Início da Fila: => ");
        for(int i = 0; i < fila.fim; i++){
        printf(" %d ", fila.dados[i]);
        }
        printf("<= Fim da fila.\n\n\n\n\n");
    }
    printf("\n\n\n");
}

int main(){
    int elem, escolha;
    do{
        printf("Deseja enfileirar ou desenfileirar? 0 pra sair: \n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Visualiza FILA.\n");
        printf("0. Sair\n");
        scanf("%d", &escolha);
        system("clear");

        switch (escolha){
        case 0:
            printf("Você saiu do Programa.\n");
            break;

        case 1:
            printf("Digite um número inteiro para enfileirar: \n");
            scanf("%d", &elem);
            enfileira(elem);
            mostra_fila();
            break;
        
        case 2:
            printf("Você desenfileirou o número %d .\n", fila.dados[0]);
            desenfileira();
            mostra_fila();
            break;
        
        case 3:
            mostra_fila();
            break;
        
        default:
            printf("Opção Inválida.\n");
            break;
        }

    } while (escolha != 0);
    
    return 0;
}
