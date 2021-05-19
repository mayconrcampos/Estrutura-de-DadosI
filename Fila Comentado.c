#include <stdio.h>
#include <stdlib.h>

//Constante que define o tamanho máximo da estrutura de dados
#define tamanho 5

//Declara��o do tipo_fila: estrutura de dados
typedef struct tipo_fila{
	int dados[tamanho];
	int ini;
	int fim;
}tipo_fila;

//Criando uma vari�vel tipo_fila
tipo_fila fila1;
tipo_fila fila2;

//Fun��o que enfileira um novo elemento ao fim da fila
void enfileira(int elemento, tipo_fila *f){
	//Verificando se existe alguma posi��o dispon�vel para uma inser��o
	if(f->fim == tamanho){
		//Se a fila estiver cheia, n�o � poss�vel enfileirar
		printf("Fila cheia.\n");
		system("pause");
	}
	else
	{
		//Se a fila n�o estiver cheia:
		//	Adicione o novo elemento no fim
		//	Incremente o fim
		f->dados[f->fim] = elemento;
		f->fim++;
	}
}

//Fun��o que desenfileira e retorna o elemento do in�cio da fila
int desenfileira(tipo_fila *f){
	//Vari�vel que guarda um "backup" do elemento desenfileirado
	int elemento, i;
	
	//Verificando se existe algum elemento dispon�vel para uma remo��o
	if(f->fim == f->ini){
		//Se a fila estiver vazia, n�o ser� poss�vel desenfileirar
		printf("Fila vazia.\n");
		system("pause");
	}
	else
	{
		//Se a fila n�o estiver vazia:
		//Guarda um backcup do elemento a ser removido;
		elemento = f->dados[f->ini];
		//"Arrasta os elementos do "fim" em dire��o ao "in�cio"
		//Nesse passo, o elemento que estava no "in�cio" da fila ser� sobrescrito
		for(i=0; i<tamanho; i++)
			f->dados[i] = f->dados[i+1];
		//Apaga-se o elemento que estava no "fim" (conven��o: atribui-se zero ao apagar)
		f->dados[f->fim] = 0;
		//Decrementa-se o "fim".
		f->fim--;
		//Retorne o elemento que estava no "in�cio"
		return elemento;
	}
}

void imprimir(tipo_fila *f){
	int i;
	printf("\n\nImprimindo:");
	for(i=0;i<f->fim;i++){
		printf("%d ", f->dados[i]);
	}
}

int main(){
	fila1.fim = 0;
	fila1.ini = 0;
	
	fila2.fim = 0;
	fila2.ini = 0;
	
	//RA: 6 5 9 8 7
	
	enfileira(6, &fila1);
	enfileira(5, &fila1);
	enfileira(9, &fila1);
	enfileira(8, &fila1);
	enfileira(7, &fila1);
	
	imprimir(&fila1);
	
	desenfileira(&fila1);
	
	imprimir(&fila1);

}

