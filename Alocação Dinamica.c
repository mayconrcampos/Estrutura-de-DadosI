#include <stdio.h>
#include <stdlib.h>

int main(){
	
	unsigned int *p;
	
	p = (unsigned int *) malloc(1);
	
	if(p == NULL){
		printf("Erro!\n");
	}
	else{
		*p = 300;
		printf("p: %d\n", *p);
		free(p);
	}
}





