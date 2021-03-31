#include <stdio.h>

int *ptr;
int x;

int main(){
    x = 10;
    ptr = &x;
    printf("ptr Endereço: %x \nx valor: %d \n", ptr, x);

    // Muda-se o valor de X
    x = 20;
    
    // Muda-se o conteúdo do ponteiro que aponta pra X.
    *ptr = 30;
    printf("ptr valor: %d \nptr endereço: %x \nx valor: %d \n\n", *ptr, &ptr, x);

    // No fim, alterou o valor de X utilizando o ponteiro com o operador de conteúdo.

    return 0;
}


