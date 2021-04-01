#include <stdio.h>
#include <stdbool.h>

int main(){

    printf("int possui: %dbytes \n", sizeof(int));
    printf("float possui: %dbytes \n", sizeof(float));
    printf("double possui: %dbytes \n", sizeof(double));
    printf("bool possui: %dbytes \n", sizeof(bool));
    printf("char possui: %dbytes \n", sizeof(char));
    return 0;
}
