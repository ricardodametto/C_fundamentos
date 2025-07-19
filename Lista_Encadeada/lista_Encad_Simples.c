#include<stdio.h>
#include<stdlib.h>

typedef struct NO{
    int valor;
    struct NO *proximo;
}NO;

NO *alocaNO(){
   NO *novoNo = (NO*)calloc(1,sizeof(NO));
    if(novoNo == NULL){
        printf("Erro ao alocar memória para o Nó!");
        exit(EXIT_FAILURE);
    }
    return novoNo;
}


void insereInicio(NO **lista, int novovalor){
    NO *novoNo = alocaNO();
    novoNo->valor = novovalor; //o novo No recebe um valor
    novoNo->proximo = *lista; // o novo No recebe o endereço atual da Lista
    *lista  = novoNo; // e por fim, a Lista recebe o novo No tendo atualizada sua referencia
}

void insereFinal(NO **lista, int valor){
    NO *novoNo = alocaNO();
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    if(*lista == NULL){
        *lista = novoNo;
    }else{
        NO *atual = *lista;
        while(atual->proximo != NULL){
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
}

void liberaNo(NO *lista){
    NO *atual = lista;
    while(atual != NULL){
        NO *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}


void imprimeLista(NO *lista){
    NO *atual = lista;
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Imprime os endereços e valores dos nós
void imprimeEnderecos(NO *lista) {
    NO *atual = lista;
    int i = 0;
    while (atual != NULL) {
        printf("Nó %d: valor = %d, endereço = %p, próximo = %p\n",
               i, atual->valor, (void *)atual, (void *)atual->proximo);
        atual = atual->proximo;
        i++;
    }
}

int main(int argc, char const *argv[])
{
    NO *lista = NULL;
    
    
    insereInicio(&lista, 10);
    insereInicio(&lista, 20);
    //insereFinal(&lista, 55);
    //insereInicio(&lista, 30);
    
    imprimeLista(lista);
    
    printf("%p\n",lista->proximo);
    
    imprimeEnderecos(lista);

    liberaNo(lista);
    
    return 0;
}
