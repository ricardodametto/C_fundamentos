#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<locale.h>

typedef struct Tabuleiro{
    int linhas;
    int colunas;
    int **matriz;
    char cabecalho[11];
}Tabuleiro;

typedef struct Navio{
    int tamanho;
    int coordL; //coordenada linha
    int coordC; //coordenada coluna
    int position;// vertical, horizontal, diagonal
    Tabuleiro *tab;
}Navio;



void IniciaTab(Tabuleiro *tab, int linhas, int colunas){
    tab->linhas = linhas;
    tab->colunas = colunas;
    tab->matriz = (int **)malloc(tab->linhas * sizeof(int *));
    if(tab->matriz == NULL){
        printf("ERRO AO ALOCAR MEMÓRIA PARA AS LINHAS!\n");
        exit(EXIT_FAILURE);
    }
    for(int i =0; i < tab->linhas; i++){
        tab->matriz[i] = (int *)malloc(tab->colunas * sizeof(int));
        if(tab->matriz[i] == NULL){
            printf("ERRO AO ALOCAR MEMÓRIA PARA AS COLUNAS!\n");
            exit(EXIT_FAILURE);
        }
    for(int j=0; j < tab->colunas; j++){
        tab->matriz[i][j] = 0;
        }
    }
    char letras[11] = {' ','A','B','C','D','E','F','G','H','I','J'};
    for(int i=0; i < 11 + 1; i++){
        tab->cabecalho[i] = letras[i];
    }
}


void LiberaTab(Tabuleiro * tab){
    for(int i=0; i < tab->linhas; i++){
        free(tab->matriz[i]);
    }
    free(tab->matriz);
}

void ImprimeTab(Tabuleiro *tab){
    for(int i=0; i < tab->colunas + 1; i++){
        printf("%c  ",tab->cabecalho[i]);
    }
    printf("\n");
    for(int i =0; i < tab->linhas; i++){
        printf("%d  ", i);
        for(int j=0; j < tab->colunas; j++){
            printf("%d  ",tab->matriz[i][j]);
        
        }
        printf("\n");
    }
}
    



int main(int argc, char const *argv[])
{
    Tabuleiro *tabuleiro;
    IniciaTab(tabuleiro,10,10);
    ImprimeTab(tabuleiro);
    LiberaTab(tabuleiro);
    return 0;
}

