#include<stdio.h>

int main(int argc, char const *argv[])
{
    int n1 = 10, n2 = 20, n3 = 60;
    int *pn1=&n1, *pn2=&n2, *pn3=&n3;

    printf("Aprendendo sobre ponteiros\n");
    printf("\n\n");
    
    printf("Exibindo valores de n1=%d, n2=%d, n3=%d\n\n",n1,n2,n3);
    printf("Exibindo endereços das variaveis n1=%p, n2=%p, n3=%p\n",&n1,&n2,&n3);
    printf("Exibindo endereços dos ponteiros *pn1=%p, *pn2=%p, *pn3=%p\n\n",&n1,&n2,&n3);

    *pn1 += 20;
    *pn2 *= 20;
    printf("Valor de *pn1 += 20= %d, endereço n1 ou *pn1=%p\n",*pn1,&n1);
    printf("Valor de *pn2 *= 20= %d, endereço n2 ou *pn2=%p\n\n",*pn2,&n2);
    
    pn1 = pn2;
    printf("Valor de pn1 = pn2 = %d\n",*pn2);
    *pn1 = 30;
    printf("Valor de *pn1 = 30 = %d\n",*pn1);
    return 0;
}
