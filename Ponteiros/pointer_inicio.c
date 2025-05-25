#include<stdio.h>

int main(int argc, char const *argv[])
{
    int h = 100;
    int *ph;

    printf("Endereço variavel regular: %p\n",&h);
    printf("Endereço ponteiro: %p\n",ph);

    ph = &h; //inicializa o ponteiro
    printf("Endereço ponteiro inicializado: %p\n",ph);
    printf("Valor ponteiro inicializado pela variavel h: %d\n",*ph);

    *ph = 200;
    printf("Endereço variavel regular: %d\n",h);
    return 0;
}
