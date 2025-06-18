#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    //int **vet;//[3][4] essa declaração quer dizer o seguinte: existe uma gateway aqui dentro da stack que fará um 'rotemento' para uma região do Heap
    //int linhas = 3;
    //int colunas = 4;

    //a planta do pŕedio **vet: precisa de andares(linhas) e apartamentos por andares(colunas)
    int **vet = malloc(10 * sizeof(int *));//aloca espaço para quantidade de linhas da matriz
    if(vet == NULL){
      printf("Erro ao alocar espaço no Heap!!");
      return 1;
    }else{
      printf("Párabens! memória alocada no Heap com sucesso!\n");
    }
    //na etapa acima temos memoria alocada para 10 linhas, agora vamo alocar espaço para 10 colunas para cada uma das 10 linhas
    for(int i = 0;i < 10;i++){

      vet[i] = malloc(10 * sizeof(int));//espaço alocado para as colunas deve ser dentro fo laço
    }
    
    printf("Preencha os valores para a matriz:\n");
    for(int i = 0; i < 10; i++){
      for(int j= 0; j < 10; j++){
        printf("matriz[%d][%d]: ",i,j);//a cada 4 iterações repete os campos alternando o numero de linha, da 0 até a 3
        scanf("%d",&vet[i][j]);
        
      }

    }
     
     printf(" \nMatriz digitada:\n");
     for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10;j++){
          printf("%d ", vet[i][j]);
        }
          printf("\n");
     }
     
    free(vet); 
     
return 0; 


}                      