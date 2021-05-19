#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int dado;
    struct NO *proximo;
}NO;

typedef struct FILA {
    NO *inicio;
    NO *fim;
}FILA;

void enfileira(int dado, FILA *fila){
    //int numero;
    NO *ptr = (NO*) malloc(sizeof(NO));
    if(ptr == NULL){
        printf("Erro de alocação.\n");
        return;
    }else{
        ptr->dado = dado;
        ptr->proximo = NULL;
        if(fila->inicio == NULL){
            fila->inicio = ptr;
        }else{
            fila->fim->proximo = ptr;
        }
        fila->fim = ptr;
    }
}

void desenfileirar(FILA *fila){
    NO *ptr = fila->inicio;
    int dado;
    if(ptr != NULL){
        fila->inicio = ptr->proximo;
        ptr->proximo = NULL;
        dado = ptr->dado;
        free(ptr);
        if(fila->inicio == NULL){
            fila->fim = NULL;
        }
    }else{
        printf("Fila Vazia!\n");
        return;
    }
}

void imprimeFila(FILA *fila){
    NO *ptr = fila->inicio;
    if(ptr != NULL){
        while(ptr != NULL){
            printf("%d<-", ptr->dado);
            ptr = ptr->proximo;
        }
        printf("Final da Fila\n");
    }else{
        printf("Fila Vazia!\n");
    }
}

int main(){
    FILA *fila1 = (FILA*) malloc(sizeof(FILA));
    int opt, numero;
    if(fila1 == NULL){
        printf("Erro de alocação.\n");
    }else{
        do{
            printf("1. Enfileirar\n");
            printf("2. Desenfileirar.\n");
            printf("0. Sair.\n");
            printf("Opção: 1-2 ou 0 pra sair.\n");
            scanf("%d", &opt);
            system("clear");
            setbuf(stdin, NULL);

            switch (opt){
            case 0:
                printf("Você saiu do programa.\n");
                break;
            case 1:
                printf("Digite um número para enfileirar:\n");
                scanf("%d", &numero);
                enfileira(numero, fila1);
                imprimeFila(fila1);
                break;
            case 2:
                printf("Desenfileirando: \n");
                desenfileirar(fila1);
                imprimeFila(fila1);
                       
            default:
                printf("Opção inválida!\n");
                break;
            }

        } while (opt != 0);
        
    }



    return 0;
}
