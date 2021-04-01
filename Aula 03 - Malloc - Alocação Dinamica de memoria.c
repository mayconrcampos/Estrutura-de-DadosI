#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr;
    ptr = (int *) malloc(4);

    if(ptr == NULL){
        printf("Erro!\n");
    }else{
        *ptr = 10;
        printf("Endereço de ptr: %x \n", ptr);
        printf("Valor de ptr: %d \n", *ptr);
        free(ptr);
        printf("Valor de ptr após liberado: Lixo: %d \n", *ptr);
    }

    return 0;
}


