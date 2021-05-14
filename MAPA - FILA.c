#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 5

typedef struct cadastro{
    char RA[11];
    char arquivo[15];
    char ext[3];
    char matricula[15];
}cadastro;

typedef struct fila{
    cadastro dados[tamanho];
    int ini;
    int fim;
}fila;

fila fila_cadastro;

void enfileira(){
    if(fila_cadastro.fim == tamanho){
        printf("Fila Cheia!\n\n\n\n");
    }else{
        printf("Digite o RA: \n");
        scanf("%s", fila_cadastro.dados[fila_cadastro.fim].RA);
        __fpurge(stdin);
        //setbuf(stdin,NULL);

        printf("Digite o nome do Arquivo: \n");
        fgets(fila_cadastro.dados[fila_cadastro.fim].arquivo, 16, stdin);
        __fpurge(stdin);
        //setbuf(stdin,NULL);

        printf("Digite a Extensão do Arquivo: \n");
        fgets(fila_cadastro.dados[fila_cadastro.fim].ext, 4, stdin);
        __fpurge(stdin);
        //setbuf(stdin,NULL);

        printf("Digite a Matrícula: \n");
        fgets(fila_cadastro.dados[fila_cadastro.fim].matricula, 16, stdin);
        __fpurge(stdin);
        //setbuf(stdin,NULL);

        fila_cadastro.fim++;

    }
}

void mostrar_fila(){
    if(fila_cadastro.ini == fila_cadastro.fim){
        printf("Fila Vazia!! Insira Elementos.\n\n\n\n");
    }else{
        printf("Imprimindo FILA.\n");
        printf("---------------------------\n");
        for(int i = 0; i < fila_cadastro.fim; i++){
            printf("Posição: 0%d\n\n", i + 1);
            printf("RA: %s\n", fila_cadastro.dados[i].RA);
            printf("Arquivo: %s\n", fila_cadastro.dados[i].arquivo);
            printf("Extensão: %s\n", fila_cadastro.dados[i].ext);
            printf("Matrícula: %s\n", fila_cadastro.dados[i].matricula);
            printf("---------------------------\n");
        }
    }
}



int main(){
    int opt;
    mostrar_fila();

    do{
        
        printf("----------MENU-----------\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Esvaziar Fila\n");
        printf("0. Sair\n");
        printf("Opção: 1-2-3-0\n");
        scanf("%d", &opt);
        system("clear");
        //setbuf(stdin,NULL);
        __fpurge(stdin);

        switch (opt){
            case 0:
                printf("0. Você saiu do Programa.\n\n");
                break;
            case 1:
                printf("1. Inserir Elemento.\n\n");
                enfileira();
                mostrar_fila();
                break;
            case 2:
                printf("2. Remover Elemento.\n\n");
                break;
            case 3:
                printf("3. Esvaziar Fila.\n\n");
                break;
            default:
                printf("Opção Inválida!\n\n\n\n");
                break;
        }

    } while (opt != 0);
    
    return 0;
}

