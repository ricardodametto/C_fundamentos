#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

const int linhas =10;
const int colunas = 10;


int main(int argc, char const *argv[])
{
    char **matriz = (char **)malloc(linhas * sizeof(char *));
        if(matriz == NULL){
            printf("Erro ao alocar as linhas!");
            return 1;
        }
        for(int i = 0; i < linhas; i++){ //aloca espaço para as linhas
            matriz[i] = (char *)malloc(colunas * sizeof(char));
            if(matriz[i] == NULL){
                printf("Erro ao alocar as colunas!");
                return 1;
            }
        }
//inicializa o tabuleiro
        for(int i = 0; i < linhas; i++){ //aloca espaço para as colunas
            for(int j = 0 ; j < colunas; j++){
                matriz[i][j] = '~';
            }
        }
//imprime o tabuleiro
    printf("Imprimindo o tabuleiro\n\n");  
        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                printf("%c ",matriz[i][j]);   
            }
            printf("\n");
        }                
        
// Liberando memória alocada
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);


}

