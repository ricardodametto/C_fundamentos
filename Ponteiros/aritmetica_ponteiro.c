#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(int argc, char const *argv[]){
setlocale(LC_ALL, "Portuguese");

int a[10] = {10,20,30,40,50,60,70,80,90,100};//10 elementos de 0 a 9 posições
int *pa;
int i = 0;
//int *pbase = a;//nessa declaração pbase aponta primeiro elemento de 'a' na posição 0 que tem valor 10, como se fosse a[0]

pa = a;
//printf("valor de a[0] =%d / endereço de &a[0] =%p\n\n",*pa,pa);

//1 forma
//itera pelo array percorrendo da posição 0 até a 9 toalizando um array de 10 posições
//por isso i < 10, porque a posição 10 seria o decimo primeiro elemento, extrapolando assim os limite fixo do array
//depois '*pa' recebe '*pbase',que aponta para primero elemento de 'a' na posição 0 que tem valor 10 somando 1 a partir posição 0 até 9
  /*for(i = 0; i < 10; i++){
    pa = pbase + i;
       printf("&a[%d] = %p / a[%d] = %d\n",i, pa,i,*pa);//exibe posição, endereço da posição e valor de cada posição de todo array
}*/

//2 forma
//dessa segunda forma nao temos o ponteiro pbase, pa já está recebendo de 'a' a posição 0 com seu respectivo valor 10 (pa = a)
   for(i = 0; i < 10; i++){
    //pa = pbase + i;
       printf("&a[%d] = %p / a[%d] = %d\n",i, pa + i,i,*(pa+i));

}

}