#include <stdio.h>

int main(){
    // Declaração de uma variável
    int valor = 30;
    // Declaração de um ponteiro
    int *ptr;
    // Atribuindo endereço a um ponteiro
    ptr = &valor;

    printf("Utilizando ponteiros\n");
    printf("Valor da variável: %d\n", valor);
    printf("Endereço da variável: %x\n", &valor);
    printf("Valor do ponteiro: %x \n", ptr);

    return 0;
}
