#include<stdio.h>

int main(int argc, char const *argv[])
{
    int h = 100;
    int *ph;

    printf("Endereço variavel regular: %p\n",&h);
    printf("Endereço ponteiro: %p\n",ph);

    ph = &h; //inicializa o ponteiro
    printf("Endereço ponteiro inicializado: %p\n",ph);
    printf("Exibindo o contéudo de *ph após inicialização: %d\n",*ph);

    *ph = 200;
    printf("Endereço variavel regular apos valor modificado via ponteiro: %d\n",h);
    return 0;
}
