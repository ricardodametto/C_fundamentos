#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>

typedef struct{
    int orientacao;
    int linhanavio;
    int colunanavio;
    int tamanhonavio;
}Navio;

typedef struct{
    int tamanho;
    int linhas;
    int colunas;
    int **matriz;
    char cabecalho[11];
    Navio *navios;//esse ponteiro fará a integração com a struct Navio, precisamos conectar as duas structs
    int qtdnavios;
}Tabuleiro;


//cria e inicializa o tabuleiro
Tabuleiro *IniciaTab(int linhas, int colunas,int qtdnavios){
    Tabuleiro *tab = malloc(sizeof (Tabuleiro)); //aloca espaço para um objeto tab do tamanho da struct Tabuleiro
    tab->linhas = linhas;
    tab->colunas = colunas;
    tab->qtdnavios = qtdnavios;
    //qtdnavios = 2;
    tab->navios = malloc(qtdnavios * sizeof(Navio));
        if(tab->navios == NULL){
            printf("Erro ao alocar array para cadastrar navios!");
            exit(EXIT_FAILURE);
        }

    tab->matriz = malloc(linhas * sizeof(int *));//aloca espaço para as linhas
    if(tab->matriz == NULL){
        printf("Erro ao alocar memoria para as linhas da matriz!");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < tab->linhas; i++){
        tab->matriz[i] = malloc(colunas * sizeof(int));//aloca espaço para as colunas
       if(tab->matriz[i] == NULL){ //se der erro durante alocação das colunas elimina da memoria as anterioires
            perror("Erro ao alocar memória para as colunas da matriz!\n");
                for(int j = 0; j < i; j++){
                    //free(tab->matriz[j]);
                }
            free(tab->matriz[i]);
            free(tab);
        }
        for(int j=0; j < colunas; j++){
            tab->matriz[i][j] = 0;
        }
    }
    char letras[11] = {' ','A','B','C','D','E','F','G','H','I','J'};
    for(int i=0; i < tab->colunas+1; i++){
        tab->cabecalho[i] = letras[i];
       
    }
   return tab;
}

void InsereNavio(Tabuleiro *tab){
    printf("Seja bem vindo a batalha soldado dos mares!!");
    
    printf("\n");
    
    for(int i = 0; i < tab->qtdnavios; i++){
        int valido = 0;
        int tentativas = 0;
        while (!valido){
            if (tentativas > 0) {
                system("clear");  // Limpa a tela só nas repetições (erros)
                printf("Tente novamente a inserção do navio %d:\n\n", i + 1);
            }
            printf("Insira o navio %d\n",i+1);
        
            printf("Digite o tamanho do navio : ");
            scanf("%d",&tab->navios[i].tamanhonavio);
        
            printf("Digite a coordenada Linha: ");
            scanf("%d",&tab->navios[i].linhanavio);
            
            char coluna_letra;//dando ao usuario inserir a coordenada coluna escolhendo a letra ao inves do numero
            printf("Digite a coordenada Coluna (A - %c): ", 'A' + tab->colunas -1);
            scanf(" %c" ,&coluna_letra);
            
            coluna_letra = toupper(coluna_letra);
            tab->navios[i].colunanavio = coluna_letra -'A';

            printf("Digite a orientação '0 - Horizontal | 1 - Vertical': ");
            scanf("%d",&tab->navios[i].orientacao);
            printf("\n\n");

            int lin = tab->navios[i].linhanavio;
            int col = tab->navios[i].colunanavio;
            int tam = tab->navios[i].tamanhonavio;
            int ori = tab->navios[i].orientacao;

            if(lin < 0 || lin > tab->linhas || col < 0 || col > tab->colunas){
                printf("O navio está fora dos limites do tabuleiro, tente poutra vez!\n");
                continue;
            }
            if(ori != 0 && ori != 1){
                printf("Orientação inválida, indique a opção correta ' 0 - Horizontal | 1 - Vertical\n");
                continue;
                system("clear");
            }
            if(ori == 0 && tam+col > tab->colunas){
                printf("Navio não cabe no limite horizontal do tabuleiro, posicione corretamente!!\n");
                continue;
            }
            if(ori == 1 && tam+lin > tab->linhas){
                printf("Navio não cabe nos limites verticais do tabuleiro, posicione corretamente!!\n");
                continue;
            }
            int pode_colocar = 1; //verifica sobreposição dos navios
            if (ori == 0) {
                for (int c = col; c < col + tam; c++) {
                    if (tab->matriz[lin][c] != 0) {
                        pode_colocar = 0;
                        break;
                    }
                }
            } else {
                for (int l = lin; l < lin + tam; l++) {
                    if (tab->matriz[l][col] != 0) {
                        pode_colocar = 0;
                        break;
                    }
                }
            }
            if (!pode_colocar) {
                printf("Já existe um navio nessa posição! Tente outra.\n\n");
                continue;
            }
             
            if (ori == 0) {
                for (int c = col; c < col + tam; c++) {
                    tab->matriz[lin][c] = i + 1;  // marca com id do navio
                }
            } else {
                for (int l = lin; l < lin + tam; l++) {
                    tab->matriz[l][col] = i + 1;
                }
            }

            valido = 1; // saiu do loop, navio inserido
            printf("Navio %d inserido com sucesso!\n\n", i + 1);
            
        }
        
    }
}

void ImprimeTab(Tabuleiro *tab){
    for(int i = 0; i < tab->colunas+1; i++){
        printf("%c  ",tab->cabecalho[i]);
    }
    printf("\n");

    for(int i = 0; i < tab->linhas; i ++){
        printf("%d  ",i);
            for(int j = 0; j < tab->colunas; j++){
                printf("%d  ",tab->matriz[i][j]);
            }
        printf("\n");
        }
}

void LiberaTab(Tabuleiro *tab){
    if(tab == NULL) return;

    for(int i = 0; i < tab->linhas; i++){
        free(tab->matriz[i]);
    }
    free(tab->matriz);
    free(tab->navios);
    free(tab);
}
 



int main(int argc, char const *argv[]){
    setlocale(LC_ALL, "Portuguese");
    Tabuleiro *tab = IniciaTab(10,10,2);
    
    ImprimeTab(tab);
    
    InsereNavio(tab);
    
    ImprimeTab(tab);
    
    LiberaTab(tab);

    return 0;
 }
