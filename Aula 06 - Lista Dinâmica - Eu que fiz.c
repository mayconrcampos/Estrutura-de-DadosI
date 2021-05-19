#include <stdio.h>
#include <stdlib.h>


typedef struct noh {
    int dado;
    struct noh *proximo;
}noh;

// variaveis
typedef noh *ptr_noh;
ptr_noh fila;

//protótipos de função
void mostra_fila(ptr_noh fila);
void inserir(ptr_noh fila);
void desenfileirar(ptr_noh fila);


int main(){
    int opcao;
    fila = (ptr_noh) malloc(sizeof(noh));
    fila->dado = NULL;
    fila->proximo = NULL;

    do{
        printf("Escolha uma das opções:\n");
        printf("1. Inserir item\n");
        printf("2. Remover um item\n");
        printf("3. Mostrar Fila\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);
        system("clear");
        setbuf(stdin, NULL);

        switch (opcao){
            case 0:
            printf("Você saiu do Programa.\n");
            break;
            case 1:
                printf("Adicionando Item na Fila:\n");
                inserir(fila);
                mostra_fila(fila);
                break;
            case 2:
                printf("Removendo item:\n");
                desenfileirar(fila);
                mostra_fila(fila);
                break;
            case 3:
                mostra_fila(fila);
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 0);
    

    
    return 0;
}

void mostra_fila(ptr_noh fila){
    while(1){
        if(fila->dado == NULL && fila->proximo == NULL){
            printf("Fila Vazia! Insira Números.\n");
            break;
        }else{
            if(fila->dado == 0){
                fila = fila->proximo;
                continue;
            }else{
                printf("%d <- ", fila->dado);
                if(fila->proximo == NULL){
                    printf("Final da Fila\n");
                    break;
                }
                fila = fila->proximo;
            } 
        }
    }
    
}

void inserir(ptr_noh fila){
    int num;
    while(fila->proximo != NULL){
        fila = fila->proximo;
    }
    fila->proximo = (ptr_noh) malloc(sizeof(noh));
    fila = fila->proximo;
    setbuf(stdin, NULL);
    scanf("%d", &num);
    system("clear");
    fila->dado = num;
    fila->proximo = NULL;
}

void desenfileirar(ptr_noh fila){
    while(1){
        if(fila->dado == 0 || fila->dado == NULL){
            fila = fila->proximo;
            continue;
        }else{
            fila->dado = 0;
            fila->proximo = 0;
            //free(fila->dado);
            break;
        }
    }
}