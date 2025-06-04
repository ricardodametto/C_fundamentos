#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char const *argv[])
{
    int i,tam,*vet; //malloc retorna ponteiro!!!
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&tam);
    srand(time(NULL));//gera numeros randomicos a partir da data e hora do computador
    
    vet = malloc(tam * sizeof(int));//tam digitado pelo usuario * 4bytes (tamanho padrao)
    if(vet){
           printf("Memoria Alocada com sucesso!\n\n");
        for(i=0; i < tam; i++)
           *(vet+i) = rand() % 100; //numero sorteado terá resto da sua divisão = 100, ou seja será de 0 99
        
        for(i = 0; i < tam; i++)
            printf(" %d", *(vet +i));
            printf("\n");

    }else{
        printf("Erro ao alocar memória!!");
    }
    
    
    
    return 0;
}
