#include <stdio.h>

void matriz();

int main(){
    int matriz[3][3];
    int num = 1;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
            matriz[i][j] = num++;
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}


