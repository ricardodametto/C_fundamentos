#include<stdio.h>
#include<stdlib.h>

typedef struct node{
     int valor;
     struct node *prox;//aponta para próximo node a ser inserido na lista

}Node;

//função inserir no inicio
void insere_no_inicio(Node **lista,int num){ //recebe como parametros o endereço da variavel lista no main e o numero a ser inserido no começo do novo Node
    Node *novo = malloc(sizeof(Node)); //novo aloca memoria para o novo node
   
    if(novo){ // se alocação de memoria acontecer...
         novo->valor = num; // campo valor,recebe o dado que se deseja inserir(parametro 'int num' dessa função)
         novo->prox = *lista;// e o campo prox recebe referencia *lista
         *lista = novo; //e o inicio da lista atual passa a ser o novo node
        }else{
           printf("Erro ao alocar memória!\n");
    }

}

//função inserir no fim
void insere_no_fim(Node **lista, int num){ //ponteiro aux receberá ao endereço de lista mantendo e preservando assim o endereço de lista 
    Node *aux,*novo = malloc(sizeof(Node));

    if(novo){
        novo->valor; //recebe o dado que se deseja inserir(parametro int num dessa função)
        novo->prox = NULL; //porque a inserção será no fim e apos nao haverá outro
        
        //será esse o primeiro Node a ser inserido na lista ou não?
        
        if(*lista == NULL) // se a lista estiver vazia..
            *lista = novo; //*lista recebe novo(que contém o espaço já alocado, e o dado tipo int que se deseja inserir no final da lista)
        else{              // senão...
            aux = *lista; // atribui o endereço de *lista a aux, para que aux percorra toda lista 
            while(aux->prox)// enquanto aux->prox(campo da struct) for diferente de NULL (assim como na linha 34)
            aux = aux->prox;
            aux->prox = novo; //penduramos novo ao aux->prox
        }    

    }else{
        printf("Erro ao alocar memória!!\n");
    }


}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
