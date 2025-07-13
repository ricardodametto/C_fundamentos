#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<locale.h>

typedef struct Tabuleiro{
    int linhas;
    int colunas;
    int **matriz;
    char cabecalho[11];
}Tabuleiro;

typedef struct Navio{
    int tamanho;
    int coordL; //coordenada linha
    int coordC; //coordenada coluna
    int position;// vertical, horizontal, diagonal
}Navio;

Tabuleiro *AlocaTab(){ //aloca memória no heap para a struct
    Tabuleiro *tabuleiro = (Tabuleiro*)calloc(1,sizeof(Tabuleiro));
    if(tabuleiro == NULL){
        printf("ERRO AO ALOCAR MEMORIA PARA A STRUCT TABULEIRO!");
        exit(EXIT_FAILURE);
    }
    return tabuleiro;
}

void IniciaTab(Tabuleiro *tab, int linhas, int colunas){
    tab->linhas = linhas;
    tab->colunas = colunas;
    tab->matriz = (int **)calloc(tab->linhas, sizeof(int *));
    if(tab->matriz == NULL){
        printf("ERRO AO ALOCAR MEMÓRIA PARA AS LINHAS!\n");
        exit(EXIT_FAILURE);
    }
    for(int i =0; i < tab->linhas; i++){ //uso do calloc, não necessita de um for adicional para alocar espaço para cada coluna como no uso do malloc
        tab->matriz[i] = (int *)calloc(tab->colunas , sizeof(int));
        if(tab->matriz[i] == NULL){
            printf("ERRO AO ALOCAR MEMÓRIA PARA AS COLUNAS!\n");
            exit(EXIT_FAILURE);
        }
    /*for(int j=0; j < tab->colunas; j++){//não é necessário calloc já aloca e inicializa as colunas com zeros
        tab->matriz[i][j] = 0;
        }*/
    }
    char letras[11] = {' ','A','B','C','D','E','F','G','H','I','J'};
    for(int i=0; i < 11 + 1; i++){
        tab->cabecalho[i] = letras[i];
    }
    tab->cabecalho[11] = '\0';
}


void LiberaTab(Tabuleiro * tab){
    for(int i=0; i < tab->linhas; i++){
        free(tab->matriz[i]);
    }
    free(tab->matriz);
    free(tab);
}


void ImprimeTab(Tabuleiro *tab){
    for(int i=0; i < tab->colunas + 1; i++){
        printf("%c  ",tab->cabecalho[i]);
    }
    printf("\n");
    for(int i =0; i < tab->linhas; i++){
        printf("%d  ", i);
        for(int j=0; j < tab->colunas; j++){
            printf("%d  ",tab->matriz[i][j]);
        
        }
        printf("\n");
    }
}
    
void InsereNavio(Navio *n, Tabuleiro *t){
   int ok = 0;
   while (!ok) //laço para controlar as verificações, só sai do bloco se variavel ok não for 0;
   {
    printf("\n");
    printf("Digite a coordenada linha do Navio: ");
    scanf("%d",&n->coordL);
    printf("Digite a coordenada coluna do Navio: ");
    scanf("%d",&n->coordC);
    printf("Digite o tamanho do Navio 'de 2 a 3': ");
    scanf("%d",&n->tamanho);
    printf("Digite a posição do navio '0 Horizontal| 1 Vertical| 2 Diagonal': ");
    scanf("%d",&n->position);
    printf("\n\n");

    ok = 1;
    //validação para inserir coordenadas respeitando o tamanho da matriz 10x10
    if(n->coordL <  0 || n->coordL > 9 || n->coordC < 0 || n->coordC > 9){
        printf("ERRO:Coordenadas digitadas ultrapassam os limites do tabuleiro!!\n\n");
        ok = 0;
        continue;
    }
    //validação para digitar navios somente tamanhos 2 e/ou 3
    if(n->tamanho != 2 && n->tamanho != 3){
        printf("ERRO:Tamanho inválido, Tamanhos de 2 a 3 para cada navio, tente outra vez!\n\n");
        ok = 0;
        continue;
    }
    //valida as posições dos navios dentro dos limites do tabuleiro
    if(n->position == 0){
        if(/*n->coordC + n->tamanho < 0 ||*/ n->coordC + n->tamanho -1 > 9){
            printf("ERRO:Navio ultrapassa o limite horizontal do mar!!\n\n");
            ok = 0;
            continue;
        }
    }
    else if(n->position == 1){
        if(/*n->coordL + n->tamanho < 0 ||*/ n->coordL + n->tamanho -1 > 9){
            printf("ERRO:Navio ultrapassa o limite vertical do mar!!\n\n");
            ok =0;
            continue;
        }
   }else if(n->position == 2 ){
        if((n->coordL + (n->tamanho - 1) > 9) || (n->coordC + (n->tamanho - 1) > 9)){
        printf("ERRO:Navio ultrapassa o limite diagonal(esq p/ direita) do mar!!\n\n");
        ok = 0;
        continue;
        }
    }else if(n->position == 3){
        if((n->coordL + (n->tamanho -1 )> 9 || n->coordC - (n->tamanho -1) < 0)){
        printf("ERRO:Navio ultrapassa o limite diagonal(direita p esquerda) do mar!!\n\n");
        ok = 0;
        continue;
        }
    }    
            //Valida choque ou colisões indicando sobreposição dos navios
for(int i = 0; i < n->tamanho; i++){
    int linhas = n->coordL;
    int colunas = n->coordC;

    if(n->position == 0) colunas += i; //verifica posição horizontal
    else if (n->position == 1) linhas += i;//verica posição vertical
    else if(n->position == 2){  //verifica posição diagonal  'esquerda p direita de cima p/ baixo'
        linhas += i;
        colunas += i; 
    }else if(n->position == 3){ //verifica posição diagonal inversa 'direita p esquerda de cima p/ baixo'
        linhas += i;
        colunas -= i;
    }
    if(t->matriz[linhas][colunas] != 0){
        printf("Navios sobrepostos!! Posição[%d][%d] ocupadas!!\n\n", linhas,colunas);
        ok = 0;
        break;
    }

    } 
}
//Insere o navio no tabuleiro
for(int i =0; i < n->tamanho; i++){
        if(n->position == 0){ //insere na posição horizontal
            t->matriz[n->coordL][n->coordC + i] = 3;
        }else if(n->position == 1){ //insere na posição vertical
            t->matriz[n->coordL + i][n->coordC] = 3;
        }else if(n->position == 2){ //insere na posição diagonal
            t->matriz[n->coordL + i ][n->coordC + i] = 3;
        }else if(n->position == 3){ //insere na posição diagonal direta para esquerda0
            t->matriz[n->coordL + i][n->coordC - i] = 3;
        }
    }
}
    



int main(int argc, char const *argv[])
{
    Tabuleiro *tabuleiro = AlocaTab(); //recebe a função de alocação dinamica de memoria para o tabuleiro
    
    IniciaTab(tabuleiro,10,10);
    
    Navio navio[2] = {'0'};
    ImprimeTab(tabuleiro);
    
    for(int i =0; i < 2; i++){ 
        printf("\nNavio %d \n ", i+1);
        printf("\n");
        InsereNavio(&navio[i],tabuleiro);
    }
    
    ImprimeTab(tabuleiro);
    LiberaTab(tabuleiro);
    return 0;
}

