#include <stdio.h>

int main(){
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float b[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int *ptr_a = &a;
    float *ptr_b = &b;

    // endereços sequenciais de A;
    printf("Endereço A[0]: %x \n", ptr_a);
    printf("Endereço a[1]: %x \n", ptr_a + 1);
    printf("Endereço a[2]: %x \n", ptr_a + 2);
    printf("Endereço a[3]: %x \n", ptr_a + 3);
    printf("Endereço a[4]: %x \n", ptr_a + 4);

    // recuperando valores de A;
    printf("Valor de a[0]: %d \n", *ptr_a);
    printf("Valor de a[1]: %d \n", *ptr_a + 1);
    printf("Valor de a[2]: %d \n", *ptr_a + 2);
    printf("Valor de a[3]: %d \n", *ptr_a + 3);
    printf("Valor de a[4]: %d \n", *ptr_a + 4);

    // endereços sequenciais de B;
    printf("Endereço B[0][0]: %x \n", ptr_b);
    printf("Endereço B[0][1]: %x \n", ptr_b + 1);
    printf("Endereço B[0][2]: %x \n", ptr_b + 2);
    printf("Endereço B[1][0]: %x \n", ptr_b + 3);

    // recuperando valores de B;
    printf("Valor de B[0][0]: %f \n", *ptr_b);
    printf("Valor de B[0][1]: %f \n", *ptr_b + 1);
    printf("Valor de B[0][2]: %f \n", *ptr_b + 2);
    printf("Valor de B[1][0]: %f \n", *ptr_b + 3);

    return 0;
}
