#include <stdio.h>


int main(int argc, char *argv[]){

 
     
     int A = 10;
     int *ptr = &A;
     
     *ptr = 15;
     
     printf("%d", A);
 

    return 0;
}