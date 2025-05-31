#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int vet[3][3] = {{10,20,30},
                     {40,50,60,},
                     {70,80,90}};
    int i,j;

    for(i = 0; i < 3; i++){
      for(j = 0; j < 3; j++){
        //printf("Digite o elemento da linha [%d]: coluna[%d]\n",i,j);
        //scanf("%d",&vet[i][j]);
          printf(" %d", vet[i][j]);
      }
        printf("\n");
    }
     
     
     
     
     
return 0; 


}                      