#include <stdio.h>
#include <stdlib.h>

void vetorPonteiro();

int main(){
    // Alocando memória de forma dinâmica.

    int *numero;

    numero = (int *) malloc(sizeof(int));

    if(numero != NULL){
        *numero = 100;
        printf("Conteúdo de Número: %d\n", *numero);
        printf("Endereço de Número: %d\n", &numero);
        printf("Endereço para qual Número aponta: %d\n", numero);
        free(numero);
        printf("Número: %d\n", *numero);
    }else{
        printf("Erro de Alocação!\n");
    }

    vetorPonteiro();


    return 0;
}

void vetorPonteiro(){
    int *p;
    int x[3] = {2, 5, 10};

    p = &x;

    printf("Endereço armazenado de p? %d\n", p);
    printf("Endereço do vetor x: %d\n", &x);
    printf("Endereço de x[0]: %d\n", &x[0]);
    printf("Valor de x[0]: %d\n", *p);

    p++;

    printf("Endereço armazenado de p? %d\n", p);
    printf("Endereço do vetor x: %d\n", &x);
    printf("Endereço de x[1]: %d\n", &x[1]);
    printf("Valor de x[1]: %d\n", *p);

    p++;

    printf("Endereço armazenado de p? %d\n", p);
    printf("Endereço do vetor x: %d\n", &x);
    printf("Endereço de x[2]: %d\n", &x[2]);
    printf("Valor de x[2]: %d\n", *p);

}