#include <stdio.h>
#include <stdlib.h>

//Funçãoo de Busca Sequencial
int buscaSequencial(int vec[], int arg, int tam){
	int i = 0, achou = -1;
	while ((i < tam) && (achou == -1)){
		if (vec[i]==arg){
			achou = i;
		}
		i++;
	}
	return(achou);
}

//Função de Busca Binária
int buscaBinaria(int vec[], int arg, int tam){
	int menor, maior, meio;
	menor = 0;
	maior = tam-1;
	while (menor <= maior){
		meio = (menor + maior)/2;
		if (arg == vec[meio]){
			return(meio);
		}
		if(arg < vec[meio]){
			maior = meio - 1;
		}
		else {
			menor = meio + 1;
		}
	}
	return(-1);
}

//Função de busca por interpolação
int buscaInterpol(int vec[], int arg, int tam){
	int menor, maior, meio, achou;
	menor = 0;
	maior = tam-1;
	achou = -1;
	while((menor <= maior) && (achou == -1)){
		meio = menor + (maior - menor) *
		((arg - vec[menor])/vec[maior] - vec[menor]);
		if (arg == vec[meio]){
			achou = meio;
		}
		if(arg < vec[meio]){
			maior = meio - 1;
		}
		else {
			menor = meio + 1;
		}
	}
	return(achou);
}

//Função de árvore binária de busca
int buscaArvoreBinaria(int vec[], int arg, int tam)
{
	int no, achou, fim;
	fim = 0;
	no = 0;
	achou = -1;
	while((achou == -1) && (fim <= tam)){
		if (arg == vec[no]){
			achou = no;
		}
		if (arg < vec[no]){
			no = (2 * no) + 1;
		}
		else {
			no = (2 * no) + 2;
		}
		fim++;
	}
	return(achou);
}

int main(){
	return 0;
	
}





























