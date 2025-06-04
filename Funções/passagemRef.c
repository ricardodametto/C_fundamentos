#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <string.h>

void max1(int *pa, int *pb, int *result);
int *rmax2(int *pa, int *pb);

void min1(int *pa, int *pb,int *result);
int *rmin2(int *pa, int *pb);

void rAumentoPercentual(float *valor, int percentual, float *result);

void rDescontoPercentual(float *valor, int percentual, float *result);

void rswap(int *a, int *b);


int main(int argc, char const *argv[]){
setlocale(LC_ALL, "Portuguese");
    int a = 50, b = 30;
    float valor = 300;
    int percent = 10;
    int resultMax, resultMin;
    float resultadoAumento , resultadoDesconto;

    printf("valor de a=%d - valor de b=%d - Antes d Swap:\n",a,b);
    printf("Endereços de memóra de a=%p  -  b=%p\n\n ",&a,&b);


       max1(&a,&b,&resultMax);//max1 e max 2 não retornam valor(void) por isso precisam ser invocadas antes do escopo do printf
       min1(&a,&b,&resultMin);
       //rmax2(&a,&b);
       //rmin2(&a,&b);

       printf("max1(&a, &b, &resultMax) = %d\n",resultMax);
       printf("min1(&a, &b, &resultMin) = %d\n\n",resultMin);

       printf("rmax2(&a, &b) = %d\n",*rmax2(&a,&b));//como *rmax e *rmin retornam valor(int) então elas podem ser invocadas dentro do printf
       printf("rmin2(&a, &b) = %d\n\n",*rmin2(&a,&b));

       rAumentoPercentual(&valor,percent,&resultadoAumento);
       rDescontoPercentual(&valor,percent,&resultadoDesconto);

       printf("Valor com aumento de 10 : %.2f\n",resultadoAumento);
       printf("Valor com desconto de 10 : %.2f\n\n",resultadoDesconto);

       printf("valor de a=%d - valor de b=%d - Antes do Swap:\n",a,b);
       rswap(&a,&b);
       printf("Valor de a=%d - valor de b=%d - Após o Swap:\n",a,b);
       printf("Endereços de memóra de a=%p  -  b=%p - Após o Swap após não se altera\n\n ",&a,&b);
return 0;
}

void max1(int *pa, int *pb, int *result){//passgem de argumentos por valor,consiste em uma cópia do valor original das variaveis previamente declaradas
   if(*pa > *pb)
     *result = *pa;
   else
     *result = *pb;

}

void min1(int *pa, int *pb, int *result){//aqui result nao é declarado como ponteiro no escopo da função mas sim é um parametro
   if(*pa > *pb)
    *result = *pb;
   else
    *result = *pa;

}

int *rmax2(int *pa, int *pb){
    int *result = NULL; //aqui eu declaro um ponteiro no escopo da função e não é parametro
    if(*pa > *pb)
        result = pa;
    else
        result = pb;
    return result;
}

int *rmin2(int *pa, int *pb){
    int *result = NULL;
    if(*pa > *pb)
        result = pb;
    else
        result = pa;
    return result;
}

void rAumentoPercentual(float *pvalor, int percentual, float *result){
    *result =  (float)(*pvalor+(*pvalor * percentual/100));
}


void rDescontoPercentual(float *pvalor, int percentual, float *result){
    *result =  (float)(*pvalor-(*pvalor * percentual/100));
}

void rswap(int *a, int *b){ //no escopo main os valores de a = 50 de b = 30
    int temp;//criação da variavel de escopo local temp armazenada na stack da memoria
    temp = *a;//temp = 50, porque recebu de a
    *a = *b; //*a agora é = 30
    *b = temp;//*b agora é = 50
}
