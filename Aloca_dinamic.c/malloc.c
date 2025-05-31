#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int *a,**ppa;

    a = malloc(4*sizeof(int)); //aloca espaço de 4 bytes referente ao tamanho de 'int'
    if(a){
        printf("Memoria alocada com sucesso!!\n\n");
        printf("valor de a: %d\n",*a);
        printf("endereço de *a: %p\n",a);
        *a = 100;
        *ppa = a;
        printf("valor de *ppa: %d\n",**ppa);
        printf("endereço de *ppa: %p\n",*ppa);
        
    
    
    }else{
        printf("Erro ao alocar memoria");
    }
    return 0;
}
