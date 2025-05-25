#include<stdio.h>
#include<stdlib.h>


typedef struct{
        int codigo;
        char nome[30];
    }NODE;

int main(int argc, char const *argv[])
{
    NODE *p = (NODE*) malloc(sizeof(NODE));
    if(p == NULL){
        printf("Erro de alocação!!");
        exit(0);
    }else{
        printf("Insira o código: ");
        scanf("%d", &p->codigo);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Digite o nome: ");
        scanf(" %29[^\n]",p->nome);
        getchar();
        system("clear");

        printf("Codigo: %d - Nome: %s\n\n",p->codigo,p->nome);
    }
  free(p);
    return 0;
}
