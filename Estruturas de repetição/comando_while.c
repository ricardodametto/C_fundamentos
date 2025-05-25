#include<stdio.h>

int main(int argc, char const *argv[])
{
    int i = 5;

    do
    {
        printf(" %d",i);
        i++;           //SE O VALOR DA VARIAVEL FOR MENOR DO QUE VALOR DENTRO DA CONDIÇÃO ENTÃO USE ++ INCREMENTO
    } while (i <= 10);//CONDIÇÃO INICIAL É OBRIGATÓRIAMENTE TRUE NO WHILE!!!
    
    return 0;
}
