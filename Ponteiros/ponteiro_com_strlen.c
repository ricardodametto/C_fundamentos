#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <string.h>
//size_t strlen(char *);

int main(int argc, char const *argv[]){
setlocale(LC_ALL, "Portuguese");
char *s = "ABCDEFGHIJ";//A linguagem tambem alocou o decimo primeiro elemento para essa string que é '\0'


size_t strlen(char *s){//aqui *s não é a mesma que a declarada na linha 9 porque agora trata-se de uma variavel de escopo local
                       //porque agora está declarada dentro função, nesse caso está armazenada n stack da memoria
char *p = s; //p recebe primeiro elemento de s na posição 0 que tem valor 'A'
  while(*p != '\0')
     p++;
  return (size_t)(p - s);//retorna o numero de caracteres avançados

}
  printf("Tamanho da string '%s' = %d\n",s,(int)strlen(s));




return 0;
}
