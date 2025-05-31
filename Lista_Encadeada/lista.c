#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Cadastro{
    char estado;
    char codcarta [5];
    char nomecidade[50];
    int populacao;
    float area;
    long long int pib;
    int pontostur;
    struct Cadastro *proximo;//ponteiro para nossa struct principal

}Cadastro;

typedef struct{
    Cadastro *inicio;//ponteiro *inicio tipo 'Cadastro
    int tamanho; //idicará a quantidade de nós inseridos no nosso sistema
}Lista;


void insere_inicio(Lista *lista,Cadastro campos){
     Cadastro *novo = (Cadastro*)malloc(sizeof(Cadastro));//aloca espaço para novo nó a ser inserido na lista
     //inicializar os campos da struct Cadastro 
     novo->estado = campos.estado;
     strcpy(novo->codcarta, campos.codcarta);// uma array de char nao é um lvalue modificavel por isso usar strcpy
     strcpy(novo->nomecidade, campos.nomecidade);
     //lógica de inserção no incio da Lista, sempre insere A ESQUERDA DO ULTIMO NÓ INSERIDO
     novo->proximo = lista->inicio; // (Cadastro)*proximo do novo nó recebe conteúdo de (Lista)*incio 
     lista->inicio = novo; //após a linha acima, agora o *inicio da Lista rebece o endereço e conteúdo do nó a ser adicionado
     lista->tamanho++;
    

}

void insere_final(Lista *lista,Cadastro campos){
    Cadastro *percorreNo, *novo = (Cadastro*)malloc(sizeof(Cadastro));
    //inicializa os campos da struct
    novo->estado = campos.estado;
    strcpy(novo->codcarta, campos.codcarta);
    strcpy(novo->nomecidade, campos.nomecidade);
    //logica para inserção no final da Lista, seempre insere A DIRETIA DO ULTIMO NÓ INSERIDO
    novo->proximo = NULL;
    if(lista->inicio == NULL){ //CASO A LISTA ESTEJA VAZIA
          lista->inicio = novo;//inicio recebe contéudo e endereço do novo nó inserido
    }else{//caso a lista não esteja vazia ou NULL
         percorreNo->proximo = lista->inicio;
         while(percorreNo->proximo != NULL)
            percorreNo = percorreNo->proximo;
         percorreNo->proximo = novo;
         }
    lista->tamanho++;//incrementa a cada inserção para sinalizar total de nós na Lista
}


void imprimir_lista(Lista *lista){ //para imprimir a lista deve-se percorre-la a partir do inicio
    Cadastro *inicio = lista->inicio;//aqui eu referenciei *inicio que já existe na struct Lista (de tipo Cadastro)
    
    printf("Tamanho da lista: %d\n\n",lista->tamanho);
    while(inicio != NULL){
        printf("Estado: %c\n",inicio->estado);
        printf("Codigo carta: %s\n",inicio->codcarta);
        printf("Nome da cidade: %s\n",inicio->nomecidade);
        inicio = inicio->proximo;
        printf("\n\n");
    }
}



int main(int argc, char const *argv[])
{
    Lista lista;
    
    lista.inicio = NULL;//porque não há nós inseridos
    lista.tamanho = 0; //porque a quantidade de nós inseridos é 0
    int opcao;
    
    do
    {
        printf("1 - Inserir no Início\n2 - Inserir no Fim\n3 - Imprimir\n5 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)

        {
        case 1:
           Cadastro camposInicio;  
        
           printf("Digite o Estado(letra de A a H): ");
           scanf(" %c",&camposInicio.estado);
           while (getchar() != '\n');
           
           printf("Digite o codigo da Carta: ");
           scanf(" %4s",camposInicio.codcarta);
           while (getchar() != '\n');
           
           printf("Digite o nome da cidade: ");
           fgets(camposInicio.nomecidade,49,stdin);
           camposInicio.nomecidade[strcspn(camposInicio.nomecidade, "\n")] = '\0';          
           
           insere_inicio(&lista,camposInicio);
        break;
        
        case 2:
             Cadastro camposFim;  
        
           printf("Digite o Estado(letra de A a H): ");
           scanf(" %c",&camposFim.estado);
           while (getchar() != '\n');
           
           printf("Digite o codigo da Carta: ");
           scanf(" %4s",camposFim.codcarta);
           while (getchar() != '\n');
           
           printf("Digite o nome da cidade: ");
           fgets(camposFim.nomecidade,49,stdin);
           camposFim.nomecidade[strcspn(camposFim.nomecidade, "\n")] = '\0';          
           
           insere_final(&lista,camposFim);

        break;
        
        case 3:
            imprimir_lista(&lista);     
        break;
        
        case 5:
             printf("Finalizando...\n");
        break;     
            
        default:
            printf("Opção Inválida...\n");    
        break;
        } 
    }while(opcao != 5);

    return 0;
}
