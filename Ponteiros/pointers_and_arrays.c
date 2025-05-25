#include<stdio.h>

int main(int argc, char const *argv[])
{
    int x[5] = {10,20,30,40,50};

    printf("Valor do elemento na posição 0 = %d\n",*(x+0));//mesma expressão acima podendo usar *
    printf("Endereço de memória do elemento na posição 0 = %p\n\n",x+0);//exibe endereço de memória do elemento na posição 0 podendo usar &x[0]
    
    printf("MUDANDO O VALOR DO ELEMENTO NA POSIÇÃO 0 DE 10 PARA 55\n\n");
    x[0] = 55;
    //*(x+0) = 55;
    printf("Elemento 3 alterado = %d\n",*(x+0));//podendo usar x[0]
    
    printf("\nVamos mudar o valor 40 do elemento da posição 3 ? Digite um valor: \n");
    scanf("%d",x+3);
    
    for(int i = 0; i < 5; i++){
      printf("Posição/Elemento: [%d][%d]\n",i,*(x+i)); //equivale a x[i]
      printf("Posição/Endereço: [%d] &[%p] = %p\n",i,x+i);//equivale a &x[i] especificadores %p para endereço de memoria
      printf("-----------------------------------------\n\n");
    }
    
    printf("Endereço do Array x &[%p]\n\n",x+5);//podendo usar &x[5]
    printf("MUDANDO OS VALORES DAS POIÇOES DO ARRAY\n");
    return 0;
}
