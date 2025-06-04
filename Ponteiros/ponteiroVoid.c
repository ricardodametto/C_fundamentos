#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <string.h>


int main(int argc, char const *argv[]){
setlocale(LC_ALL, "Portuguese");

int vet[6] = {0,10,20,30,40,50};

void *p; //ponteiros tipo void podem apontar para qualquer tipo primitivo
p = vet;//&vet[0];//forma correta de pegar valor da posição desejada p = vet; pega o endereço do primeiro elemento vet[0]

printf("Endereço de vet[0] %p\n",p); //com ponteiro tipo void só é possivel imprir o endereço da posição 0
printf("Endereço de vet[4] %p\n",&vet[0]);//para imprimir os demais endereços do vetor tem que ser dessa forma

//duas formas de imprimir o valor
printf("Valor de vet[5] %d\n",vet[5]);
printf("Valor de vet[5] %d\n", *((int *)p+5));//para obter o valor da variavel que o ponteiro aponta, se ele é void, usa-se o casting




return 0;
}
