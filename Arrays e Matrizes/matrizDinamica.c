#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int **vet;//[3][4]
    int i,j;

    vet = malloc(3 * sizeof(int *));//aloca espaço para quantidade de linhas da matriz
    
    for(int i = 0;i < 3;i++){

      vet[i] = malloc(4 * sizeof(int));//espaço alocado para as colunas deve ser dentro fo laço
    }
    
    printf("Preencha os valores para a matriz:\n ");
    for(i = 0; i < 3; i++){
      for(j = 0; j < 4; j++){
        printf("matriz[%d][%d]: ",i,j);//a cada 4 iterações repete os campos alternando o numero de linha, da 0 até a 3
        scanf("%d",&vet[i][j]);
        
      }

    }
     
     printf(" \nMatriz digitada:\n");
     for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4;j++){
          printf("%d\t", vet[i][j]);
        }
          printf("\n");
     }
     
    free(vet); 
     
return 0; 


}                      