#include <stdio.h>
#include <stdlib.h>

//Exemplo de vetor, inicializdo, com alocação dinamica ou estatica, efunções de entrada de usuario
//e imprimir resultado





//função imprime vetor
void imprimeVetor(int *vetor, int tamanho){//ponteiro para int passado por referencia, para que possam ser digitados outros valores além dos inicializados
    printf("Elementos do vetor:");         //uso de ponteiro na passagem por referencia permite alterar valores do vetor mesmo este inicalizado no main
    for(int i = 0; i < tamanho; i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");
    printf("Tamanho do vetor = %d posições.\n\n",tamanho);
}

//função entrada de dados
void entradausuario(int *vetor, int tamanho){
    printf(":----Digite um numero inteiro para compor o vetor----:\n\n");
    for(int i = 0;i < tamanho; i++){
        printf("Digite o valor da posição %d: ",i,vetor[i]);
        scanf("%d",&vetor[i]);
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
    //int vetor[5] = {10,20,30,40,50};//como a função entrada de usuario tem como parametro um ponteiro entao os valore podem ser modificados
    int tamanho = 5;
    int *vetor;
    vetor = (int*)malloc(tamanho * sizeof(int));//aloca o espaço de um int para cada elemento
    if(vetor == NULL){
        printf("Erro na alocação de memória!\n");
        return 1;
    }
    entradausuario(vetor,5);//nao é necessario clocar o &vetor porque todo vetor já é um ponteiro implicito para o seu primeiro elemento
    imprimeVetor(vetor,5);
    free(vetor);
    
    return 0;
}
