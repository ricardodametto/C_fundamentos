#include<stdio.h>

int main(int argc, char const *argv[])
{
    int x = 10;
    int *px;
    
    printf("O valor de x é : %d\n",x);//imprime o endereço original do ponteiro
    printf("O endereço de memória de x é : %p\n",&x);//imprime o endereço de x, passar a variavel com o &
    printf("O endereço do original de *px é : %p\n",px);//imprime o endereço de *px;

    px = &x; //o pointeiro recebe o conteudo da variavel x pela passagem por referencia
    
    printf("Veja o endereço de x passado por refêrencia a *px: %p",px ,"agora *px recebe endereço de x!!\n\n");//para imprimir o endereço de x passado por referencia a *px
    printf("\nVeja o valor de x passado por referência a *px : %d\n\n", *px); //para imprimir o valor passado da variavel ao ponteiro
    
    x = 25;//mudamos o valor de x, everificaremos se *px tambem mudará
    printf("Valor de x alterado para: %d\n",x);
    printf("Valor do ponteiro após mudança do valor de x: %d\n\n", *px);//imprime em *px novo valor de x '25'

    *px = 30;//alteramos o valor diretamente no próprio ponteiro
    printf("Agora alteramos o valor de *px diretamente '*px=30' = %d\n", *px);
    printf("Vejamos se valor de x foi atualizado x = %d\n", x);
    
    printf("Vejamos se os endereços continuam os mesmos: x = %p *px = %p\n\n",&x,px);
    return 0;
}
