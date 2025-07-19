//será criado um cadastro simples de cartas do jogo supertrunfo usando a estrutura de dados lista encadeada
#include<stdio.h>
#include<stdlib.h>

typedef struct{ //struct principal que conterá os campos para leitura de toda informção necssária
    char estado;
    char codigo[5];
    char cidade[50];
    float area;
    int populacao;
    float pib;
    int pontostur;

}Cartas;

typedef struct No{  //struct de infra estrutura do Nó(cada carta inserida no sistema será um nó), essa struct será o Nó em si
    Cartas dados; //variavel tipo struct Cartas comporá e incorporará todos os campos da struct principal
    struct No *next;
}No;

//função para criar o primeiro ou novo novo Nó (ou nova carta)
No* criarNo(Cartas c){
    No *novoNo = (No*)calloc(1,sizeof(No));//aloca memoria dinamicamente para o novoNo
    if(novoNo == NULL){
        printf("Erro ao alocar memoria");
        exit(1);
    }
        novoNo->dados = c;  //caso a alocação aconteça, o ponteiro novoNo recebe endereço de c, 
        novoNo->next = NULL;//e aponta o proximo para NULL porque obviamente ele será o último
        return novoNo;
}

//função para inserir no inicio da Lista
void inserirInicio(No **head_ref, Cartas c){
     No *novoNo = criarNo(c); //chamada da função criarNo dentro de inseririnicio de modo que criarNo não precisará ser chamda no Main!!
     novoNo->next = *head_ref;
     *head_ref = novoNo;
}

//função preencheCampos
Cartas* preencherCampos(){

    Cartas *c =(Cartas*)calloc(1,sizeof(Cartas));
    if(c != NULL){
        printf("Memoria alocada com sucesso!!\n\n");
    }

    printf("\nCadastro de Cartas jogo Super Trunfo\n");

    printf("Digite o ESTADO(Letra de A a H): ");
    scanf(" %c",&c->estado);
    while (getchar() != '\n');
    printf("Digite o código da carta(A01 até H09): ");
    scanf(" %4s[^\n]",c->codigo);
    while (getchar() != '\n');
    printf("Digite o nome da cidade: ");
    scanf(" %49[^\n]",c->cidade);
    printf("Digite a area total da cidade: ");
    scanf("%f",&c->area);
    printf("Digite o total populacional: ");
    scanf("%d",&c->populacao);
    printf("Digite o PIB anual da cidade: ");
    scanf("%f",&c->pib);
    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d",&c->pontostur);
    
    return c;
}

void liberarLista(No **head_ref) {
    No *atual = *head_ref;
    No *prox;

    while(atual != NULL) {
        prox = atual->next;
        free(atual);
        atual = prox;
    }
    *head_ref = NULL;
}


//função imprime lista
void imprimeLista(No *no){
    printf("\nExibe Lista de Cartas cadastradas\n");
    int i = 1;
    while(no != NULL){
         printf("\nCARTA #%d\n",i++);
         printf("Estado: %c\n",no->dados.estado);
         printf("Código da carta: %4s\n",no->dados.codigo);
         printf("Nome da cidade: %s\n",no->dados.cidade);
         printf("Área total em km2: %f km2\n",no->dados.area);
         printf("PIB anual: R$ %.2f bilhões\n",no->dados.pib);
         printf("total de pontos turísticos: %d\n",no->dados.pontostur);
     
        no = no->next;
    }
}


int main(int argc, char const *argv[])
{
    No *lista = NULL;
    int opcao;

    do
    {
        printf("1 - Inserir no Início\n2 - Imprimir\n3 - Sair\n");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao)

        {
        case 1:
           Cartas *nova = preencherCampos(); 
           inserirInicio(&lista, *nova);
           printf("\nCadastro realizado com sucesso!!\n");
           free(nova);//ipontantissimo!!! a cada malloc colocar o free!!
           break;
        
        case 2:
             imprimeLista(lista);
             if(lista == NULL){
                printf("Lista está vazia, não existe nenhum nó!!\n");
             }
             printf("\n\n");
             break;
        case 3:
            printf("Finalizando...\n");     
            liberarLista(&lista);//libera memoria da lista encadeada
            break;
        
        default:
            printf("Opção Inválida...\n");    
            break;
        } 
    }while(opcao != 3);
    
    
    return 0;
    
}
