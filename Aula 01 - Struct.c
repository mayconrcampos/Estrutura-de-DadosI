#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[10];
    int idade;
    float altura;
}dados_do_usuario;


int main(){
    dados_do_usuario aluno;

    printf("Digite seu nome: ");
    gets(aluno.nome);
    fflush(stdin);

    
    printf("Digite sua idade: ");
    scanf("%d", &aluno.idade);

    printf("Digite sua altura: ");
    scanf("%f", &aluno.altura);

    printf("Dados do Aluno:\n");
    printf("NOME: %s\n", aluno.nome);
    printf("IDADE: %d\n", aluno.idade);
    printf("ALTURA: %f\n", aluno.altura);

    return 0;
}


