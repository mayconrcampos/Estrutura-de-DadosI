//Bibliotecas
#include <stdio.h>
//#include <stdlib.h>
#include <stdbool.h>

//N�mero m�ximo de v�rtices
#define MAXV 8

//Estrutura de um n� (v�rtice da lista de adjac�ncias).
typedef struct str_no {
	int id;
	struct str_no *proximo;
} str_no;

//Grafo
struct str_no grafo[MAXV];

//====================Prot�tipos de fun��o===========================
// Fun��o para impress�o de um vetor.
// int v[] � o vetor a imprimir;
// tam � o numero de elementos do vetor.
void imprimeVetor(int v[], int tam);

// Fun��o de impress�o do grafo, no formato de conjuntos G = {V, E}
void imprimeGrafoConjuntos(struct str_no g[]);

// Fun��o que imprime o grafo no formato da lista de adjac�ncias
void imprimeGrafoListas(struct str_no g[]);

// Fun��o para inicializar o grafo.
// � preciso inicializar: 
//		- ponteiros com NULL;
//		- r�tulos dos v�rtices com �ndices de 0 a MAXV-1.
// str_no g[] � o grafo a imprimir.
void inicializaGrafo(struct str_no g[]);

// Fun��o para inserir arestas (vertices ajacentes).
// str_no g[] � o grafo;
// int v1 � o vertice de onde sai a aresta;
// int v2 � o v�rtice em que a aresta incide.
void insereAresta(struct str_no g[], int v1, int v2);

// Fun��o que cria um exemplo de grafo.
// Popula as listas de adjac�ncias com insereAresta()
void criaGrafoExemplo();

// Busca em Profundidade
void buscaEmProfundidade(struct str_no g[], int inicio, int alvo);

// Busca em Largura
void buscaEmLargura(struct str_no g[], int inicio, int alvo);




//====================Implementa��o das fun��es======================
void imprimeVetor(int v[], int tam){
	int i;
	printf("\nVetor:\n[ ");
	for(i=0;i<tam;i++){
		printf("%d ", v[i]);
	}
	printf("]\n");
}

void imprimeGrafoConjuntos(struct str_no g[])
{	
	int i;
	struct str_no *ptr;
	
	printf("================\n Vertices = { ");
	for(i = 0; i<MAXV; i++){
		printf("%d, ", g[i].id);
	}
	printf("}\n");
	printf("================\n Arestas = { ");
	for(i = 0; i<MAXV; i++){
		for(ptr = g[i].proximo; ptr != NULL; ptr = ptr->proximo){
			printf("<%d, %d>; ", g[i].id, ptr->id);
		}
	}
	printf("}\n================\n");
}

void imprimeGrafoListas(struct str_no g[])
{	
	int i;
	struct str_no *ptr;
	

	printf("================\nLista de Adjacencias:\n");
	for(i = 0; i<MAXV; i++){
		printf(" [%d]", g[i].id);
		for(ptr = g[i].proximo; ptr != NULL; ptr = ptr->proximo){
			printf("-(%d)", ptr->id);
		}
		printf(".\n");
	}
	printf("\n================\n");
}

void inicializaGrafo(struct str_no g[])
{	
	int i;
	for(i=0; i<MAXV; i++)
	{
		g[i].id = i;
		g[i].proximo = NULL;
	}
}

void insereAresta(struct str_no g[], int v1, int v2)
{
	//V�rtice a ser inserido na lista de adjac�ncia de v2
	struct str_no *vertice1 = (str_no *) malloc(sizeof(str_no));
	//V�rtice a ser inserido na lista de adjac�ncia de v1
	struct str_no *vertice2 = (str_no *) malloc(sizeof(str_no));
	//N�o foi poss�vel alocar mem�ria, desistindo da inser��o.
	if (vertice1 == NULL) {
		printf("*** Falha ao alocar o vertice 1. \n");
		return;
	}
	//N�o foi poss�vel alocar mem�ria, desistindo da inser��o.
	if (vertice2 == NULL) {
		printf("*** Falha ao alocar o vertice 2. \n");
		return;
	}
	
	//Inicializando o v�rtice.
	vertice2->id = v2;
	vertice2->proximo = NULL;
 /* Posicionando o ponteiro para inser��o 
    do v�rtice v2 na lista de adjac�ncia de v1. */
	struct str_no *ptr ;
	for(ptr = &g[v1]; ptr->proximo != NULL; ptr = ptr->proximo)
	{
		
	}
	//Inserindo v�rtice v2 na lista de adjac�ncia v1.
	ptr->proximo = vertice2;

	//Inicializando o v�rtice.
	vertice1->id = v1;
	vertice1->proximo = NULL;
 /* Posicionando o ponteiro para inser��o 
    do v�rtice v1 na lista de adjac�ncia de v2. */
	for(ptr = &g[v2]; ptr->proximo != NULL; ptr = ptr->proximo);
	//Inserindo v�rtice v2 na lista de adjac�ncia v1.
	ptr->proximo = vertice1;
	
}

// A fun��o criaGrafoExemplo ir� criar o grafo abaixo (� uma �rvore bin�ria):
// (0)
//	|---(1)
//	|	 |--(3)
//	|	 |
//	|	 |--(4)
//	|
// 	|---(2)
//		 |--(5)
//		 |
//		 |--(6)
//			 |--(7)


void criaGrafoExemplo()
{
	//Aresta entre 0 e 1
	insereAresta(grafo, 0, 1);
	//Aresta entre 0 e 2
	insereAresta(grafo, 0, 2);
	//Aresta entre 1 e 3
	insereAresta(grafo, 1, 3);
	//Aresta entre 1 e 4
	insereAresta(grafo, 1, 4);
	//Aresta entre 2 e 5
	insereAresta(grafo, 2, 5);
	//Aresta entre 2 e 6
	insereAresta(grafo, 2, 6);
	//Aresta entre 6 e 7
	insereAresta(grafo, 6, 7);
}

void buscaEmProfundidade(struct str_no g[], int inicio, int alvo){
	
	int pilha[MAXV]; //pilha
	bool visitado[MAXV]; //n�s visitados
	int indice = 0; //�ndice do topo da pilha
	bool achou = false; //flag de controle d
	int corrente = inicio;
	struct str_no *ptr;
	int i;
	
	printf("=-=-=-= Busca em Profundidade =-=-=-=\n");
	
	//Marcando os n�s como 'n�o visitados'.
	for(i=0; i < MAXV; i++){
		visitado[i] = false;
	}
	
	while(true){
		//Se o n� corrente n�o foi visitado, marque-o como visitado.
		//Empilhe o n� corrente.
		if(!visitado[corrente]){
			printf("VISITANDO: %d. \n", corrente);
			if(corrente == alvo)
			{
				printf("Vertice alvo encontrado!\n\n\n");
				return;
			}
			visitado[corrente] = true;
			pilha[indice] = corrente;
			indice++;
		}
		
		//Buscando por n�s adjacentes, n�o visitados.
		achou = false;
		for(ptr = g[corrente].proximo; ptr != NULL; ptr = ptr->proximo){
			if(!visitado[ptr->id]){
				achou = true;
				break;
			}
		}
		
		if(achou){
			//Atalizando o n� corrente, com o v�rtice adjacente n�o visitado.
			corrente = ptr->id;
		}
		else{
			//N�o h� v�rtices adjacentes n�o visitados.
			//Tentando desempilhar o v�rtice do topo.
			indice--;
			if(indice==-1){
				//N�o h� mais v�rtices n�o visitados, encerrando a busca.
				printf("Encerrando a busca. \n");
				break;
			}
			corrente = pilha[indice-1];
			
		}
		
	}
		
	return;
}

void buscaEmLargura(struct str_no g[], int inicio, int alvo){
	
	int fila[MAXV];
	bool visitado[MAXV];
	int indice = 0;
	bool achou = false;
	int corrente = inicio;
	struct str_no *ptr;
	int i;
	
	printf("=-=-=-= Busca em Largura =-=-=-= \n");
	
	//Marcando os n�s como 'n�o visitados'.
	for(i=0; i < MAXV; i++)
		visitado[i] = false;
	
	//Partindo do primeiro v�rtice.
	printf("VISITANDO: %d. \n", corrente);
	visitado[corrente] = true;
	fila[indice] = corrente;
	indice++;
	
	while(true){
		//Visitar todos os n�s adjacentes ao v�rtice corrente
		for(ptr = g[corrente].proximo; ptr != NULL; ptr = ptr->proximo){
			//Caso o v�rtice ainda n�o tenha sido visitado:
			corrente = ptr->id;
			if(!visitado[corrente]){
				//Enfileirando e marcando o v�rtice como visitado.
				printf("VISITANDO: %d. \n", corrente);
				if(corrente == alvo)
				{
					printf("Vertice alvo encontrado!\n\n\n");
					return;
				}
				visitado[corrente] = true;
				fila[indice] = corrente;
				indice++;
			}
		}
		
		//Caso a fila n�o esteja vazia:
		if(indice!=0)
		{
			//Atualizando v�rtice corrente.
			corrente = fila[0];
			//Desenfileirando o primeiro v�rtice.
			for(i=1;i<indice+1;i++)
				fila[i-1]=fila[i];
			indice--;
		}
		else
		{
			//N�o h� mais v�rtices para visitar.
			printf("Encerrando busca.\n");
			break;
		}
	}
		
	return;
}

////==================Corpo Principal do Programa====================
int main()
{
	//� sempre precizo iniciazlizar o grafo.
	//Cada n� recebe seu r�tulo, e os ponteiros s�o "zerados"
	inicializaGrafo(grafo);
	
	//Criando um grafo de exemplo (Apenas para fins did�ticos).
	criaGrafoExemplo();
	
	//Imprimindo o conjunto V de v�rtices e o conjunto E de arestas 
	imprimeGrafoConjuntos(grafo);
	
	imprimeGrafoListas(grafo);
	
	buscaEmProfundidade(grafo, 0, 5);
	
	buscaEmLargura(grafo, 0, 5);
	
	return 0;
}































