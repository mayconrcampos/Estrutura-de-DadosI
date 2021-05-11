#include <stdio.h>

//void imprimir();

int x;
int *ptr_x;

int main(){
    x = 10;
    ptr_x = &x;
    imprimir();

    // Alterando valor da variável x;
    x += 10;
    imprimir();

    // Alterando conteúdo de ptr_x;
    *ptr_x += 10;
    imprimir();

    return 0;
}

void imprimir(){
    printf("Valor de x: %d \n", x);
    printf("Valor de &x: %p \n", &x);
    printf("Valor de ptr_x: %p \n", ptr_x);
    printf("Valor de *ptr_x: %d \n\n", *ptr_x);
}
