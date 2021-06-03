#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int dado;
    struct NO* prox;
}NO;

typedef struct PILHA{
    NO* topo;
}PILHA;

typedef struct FILA{
    NO* inicio;
    NO* fim;
}FILA;

FILA *fila;
PILHA *pilha;


void empilha(int dado){
    NO* ptr = (NO*) malloc(sizeof(NO));
    ptr->dado = dado;
    ptr->prox = pilha->topo;
    pilha->topo = ptr;
}

int desempilha(){
    NO* ptr = pilha->topo;
    int dado;
    if(ptr != NULL){
        pilha->topo = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }else{
        printf("Erro\n");
        return -1;
    }
}

void mostrar_pilha(){
    NO *ptr = pilha->topo;
    if(ptr == NULL){
        printf("Pilha Vazia\n");
        return;
    }else{
        printf("===== Conteúdo de Pilha =====\n");
        printf("Topo -> ");
        while (ptr != NULL){
            printf("%d, ", ptr->dado);
            ptr = ptr->prox;
        }
        printf("\n");
        
    }
}

void enfileira(int dado){
    NO* ptr = (NO *) malloc(sizeof(NO));
    ptr->dado = dado;
    ptr->prox = NULL;
    if(fila->inicio == NULL){
        fila->inicio = ptr;
    }else{
        fila->fim->prox = ptr;
    }fila->fim = ptr;
}

int desenfileira(){
    NO* ptr = fila->inicio;
    int dado;
    if(ptr != NULL){
        fila->inicio = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }else{
        printf("Erro\n");
        return -1;
    }
}

void mostrar_fila(){
    NO* ptr = fila->inicio;
    if(ptr == NULL){
        printf("Fila Vazia\n");
    }else{
        printf("===== Conteúdo da Fila =====\n");
        printf("Início -> ");
        while (ptr != NULL){
            printf("%d, ", ptr->dado);
            ptr = ptr->prox;
        }printf("\n");
        
    }
}

int main(){
    fila = (FILA *) malloc(sizeof(FILA));
    pilha = (PILHA *) malloc(sizeof(PILHA));

    pilha->topo = NULL;
    fila->inicio = NULL;
    fila->fim = NULL;

    int opt, numero, dado;

    do{
        printf("Alocação dinâmica de memória\n");
        printf("1. Empilhar\n");
        printf("2. Desempilhar\n");
        printf("3. Enfileirar\n");
        printf("4. Desenfileirar\n");
        printf("5. Mostrar Pilha\n");
        printf("6. Mostrar Fila\n");
        printf("7. Mostrar Pilha e Fila\n");
        printf("0. Sair\n");
        scanf("%d", &opt);
        setbuf(stdin, NULL);
        system("clear");

        switch (opt){
            case 0:
                printf("Programa Encerrado!\n");
                break;
            case 1:
                printf("Empilhando\n");
                printf("Digite um número para empilhar\n");
                scanf("%d", &numero);
                empilha(numero);
                setbuf(stdin, NULL);
                break;
            case 2:
                printf("Desempilhando\n");
                dado = desempilha();
                if(dado != -1){
                    printf("%d desempilhado\n", dado);
                }
                break;
            case 3:
                printf("Enfileirando\n");
                printf("Digite um número para empilhar\n");
                scanf("%d", &numero);
                enfileira(numero);
                setbuf(stdin, NULL);
                break;
            case 4:
                printf("Desenfileirando\n");
                dado = desenfileira();
                if(dado != -1){
                    printf("%d desenfileirado\n", dado);
                }
                break;
            case 5:
                printf("Mostrando Pilha\n");
                mostrar_pilha();
                break;
            case 6:
                printf("Mostrando Fila\n");
                mostrar_fila();
                break;
            case 7:
                printf("Mostrando Pilha e Fila\n");
                system("clear");
                mostrar_pilha();
                printf("====================================\n");
                mostrar_fila();
                break;
        
            default:
                printf("Opção inválida!\n");
                break;
        }

        
    } while (opt != 0);
    

    return 0;
}