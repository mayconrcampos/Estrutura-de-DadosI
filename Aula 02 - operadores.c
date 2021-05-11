#include <stdio.h>

int main(){
    int *ptr;
    int x = 10;

    // Utilização do operador de Endereço (&);
    ptr = &x;
    printf("Operador &: %x \n", ptr);

    // Utilização do operador de Conteúdo (*);
    x = *ptr;
    printf("Operador *: %d \n\n", x);
    return 0;
}


