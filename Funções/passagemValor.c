#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <string.h>

int max(int a, int b);

int min(int a, int b);

float aumentoPercentual(int valor, float percentual);

float descontoPercentual(int valor, float eprcentual);

void swap(int a, int b);


int main(int argc, char const *argv[]){
setlocale(LC_ALL, "Portuguese");
   int a = 50, b = 30;
    float valor = 300;
    int percent = 10;


        printf("max(a,b) = %d\n", max(a,b));
        printf("min(a,b) = %d\n\n", min(a,b));

        printf("aumentoPercentual Valor com acréscimo de 10% = %.2f\n", aumentoPercentual(valor,percent));


return 0;
}

int max(int a, int b){//passgem de argumentos por valor,consiste em uma cópia do valor original das variaveis previamente declaradas
   if(a > b)
     return a;
   return b;
}

int min(int a, int b){
   if(a > b)
      return b;
   return a;
}

float aumentoPercentual(int valor, float percentual){
    return (float)(valor+(valor * percentual/100));
}
