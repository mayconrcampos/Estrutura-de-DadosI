#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dado;
    struct elemento *proximo;
}elemento;

typedef elemento *no;
no noh;

void insere(int numero, no noh);
void mostrar(no noh);

int main(){
    
    noh = (no) malloc(sizeof(elemento));
    noh->dado = 0;
    noh->proximo = NULL;
    int opc, num;

    do{
        printf("1. Inserir Numero.\n");
        printf("2. Imprimir.\n");
        printf("3. Remove primeiro item.\n");
        scanf("%d", &opc);
        setbuf(stdin, NULL);
        system("clear");

        switch (opc){
        case 0:
            printf("Saiu.\n");
            break;
        case 1:
            printf("Digite um número:\n");
            scanf("%d", &num);
            insere(num, noh);
        case 2:
            printf("Imprimindo números:\n");
            mostrar(noh);
            break;
        default:
            printf("Opção Inválida.\n");
            break;
        }

    }while (opc != 0);
    
    return 0;

}

void insere(int numero, no noh){
    while(noh->proximo != NULL){
        noh = noh->proximo;
    }
    noh->proximo = (no) malloc(sizeof(elemento));
    noh = noh->proximo;
    noh->dado = numero;
    noh->proximo = NULL;
}

void mostrar(no noh){
    while (noh->proximo != NULL){
        if(noh->dado != 0){
            printf("%d, ", noh->dado);
            
        }noh = noh->proximo;
    }
    printf("%d, \n\n", noh->dado);   
}

