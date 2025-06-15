#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <string.h>

#define NAVIOS 2 //numeros de navios para inserir
#define TAMANHO 3 

typedef struct{
    int linha;
    int coluna;
    int tamanho;
    int orientacao;

}Navio;


//função para printar o tabuleiro juntammente com a entrada de dados do usuario
void printaTab(char letras[11], int tab[10][10]){
        
    printf("      ---BATALHA NAVAL---\n\n");
    for(int i =0; i < 11;i++){
        printf("%-3c",letras[i]);
    }   
    
    printf("\n");

//passo 2: imprimir a identificação das linhas de 0 a 9
    for(int i =0; i < 10;i++){
        printf("%2d ", i - 0); //primeiro imprime a numeração identificadora das linhas
            for(int j =0; j < 10;j++){ //agora com esse segundo 'for' inicializamos com zero em cada elemento a matriz que será o tabuleiro
            //tab[10][10] = tab[i][j] = 0;
            printf("%-2d ",tab[i][j]);
    }
    printf("\n");
    }

}



int main(int argc, char const *argv[]){
setlocale(LC_ALL, "Portuguese");

int tab[10][10];
char letras[11] ={' ','A','B','C','D','E','F','G','H','I','J'};
Navio *navio[NAVIOS];//ponteiro de array tipo struct Navio para cadastro de 2 itens

//inicializa com zeros o tabuleiro, essa inicialização dispensa inicializar os tabuleiros em outros pontos do código
for(int i = 0; i < 10; i++){
    for(int j =0; j < 10; j++)
        tab[i][j] = 0;
}

//alocar memória para *navio tipo struct Navio, todo ponteiro precisa de alocação dinamica senão ocorre esse erro: 
//(0xC0000005) é um erro de acesso inválido à memória (também conhecido como Segmentation Fault ou Access Violation).
for(int n = 0; n < NAVIOS; n++){ 
    navio[n] = (Navio *)malloc (2 * sizeof(Navio));
        if(navio[n] == NULL){
            printf("Erro ao alocar memória");
            return 1;
        }
}
//chamada da função printaTab para imprimir na tela o tabuleiro como um mapa de visualização antes do jogador inserir o navio
printaTab(letras,tab);

printf("\n\n");

for(int i = 0; i < NAVIOS; i++){
    printf("Escolha uma linha para inserir como ponto inicial: ");
    scanf("%d",&navio[i]->linha);
    //while ((getchar()) != '\n');
    printf("Escolha uma coluna para inserir como ponto inicial: ");
    scanf("%d",&navio[i]->coluna);
   // while ((getchar()) != '\n');
    printf("Qual tamanho do navio?: ");
    scanf("%d",&navio[i]->tamanho);
    //while ((getchar()) != '\n');
    printf("Escolha a orientação: 0 - horizontal/ 1 - vertical : ");
    scanf("%d",&navio[i]->orientacao);
    //while ((getchar()) != '\n');
    
    printf("\n");

//Validações
//valida a posição dentro do tabuleiro, respeita os limites da matriz 10 10
if(navio[i]->linha > 9 || navio[i]->linha < 0 || navio[i]->coluna > 9 || navio[i]->coluna < 0){
    printf("Posição Iválida!! Fora dos limites do tabuleiro!!ESSE NAVIO NÃO SERÁ INSERIDO!\n\n");
    getchar();
    return 0;
}//não permite inserção de navio maior que 3
if(navio[i]->tamanho != 3){
    printf("Tamanho do navio inválido!!Digite tamanho 3!!\n\n");
    getchar();
    return 0; 
}
//valida se a inserção do Navio caberá no limite horizontal do tabuleiro
for(int y =0; y < navio[i]->tamanho; y++){
if(navio[i]->orientacao == 0 && navio[i]->coluna + y > 9){
        printf("Navio número %d extrapolou o limite horizontal do tabuleiro!!\n\n",y);
        getchar();
        return -1;
    }
}
//valida se o Navio caberá no limite vertical do tabuleiro
for(int x = 0; x < navio[i]->tamanho; x++){
if(navio[i]->orientacao == 1 && navio[i]->linha + x > 9){
        printf("Navio número %d extrapolou o limite vertical do tabuleiro!!\n\n",x);
        getchar();
        return -1;
    }  
}
//valida se já existe um navio nas coordenadas escolhidas anteriormente
/*for(int y = 0; y < navio[i]->tamanho; y++){
    if(navio[i]->orientacao == 0){
        if(tab[navio[i]->linha][navio[i]->coluna + y] != 0){ //caminha entre as colunas da mesma linha = horizontal
            printf("Já existe o navio inserido nessa coordenada!!");
            getchar();
            return 0;
        }else if(navio[i]->orientacao == 1){
            if(tab[navio[i]->linha + y][navio[i]->coluna]!=0){ //caminha entre as linhas da mesma coluna = vertical
                printf("Já existe o navio %d nessa coordenada!!");
                getchar();
                return 0 ;
        }   
    } 
 }

}*/

for(int y = 0; y < navio[i]->tamanho; y++){
    if(navio[i]->orientacao == 0 || navio[i]->orientacao == 1){
        if(tab[navio[i]->linha][navio[i]->coluna + y] !=0 && tab[navio[i]->linha + y][navio[i]->coluna] != 0){
            printf("O navio número %d já está nessa coordenada!!",y+1);
            getchar();
            return -1;
        }
    }
}




//insere o navio no mar!!
for(int k = 0; k < navio[i]->tamanho; k++){
    if(navio[i]->orientacao == 0){
        tab[navio[i]->linha][navio[i]->coluna + k] = navio[i]->tamanho;
        }else if(navio[i]->orientacao == 1){
            tab[navio[i]->linha + k][navio[i]->coluna] = navio[i]->tamanho;
        }
    }
}

system("clear");

for(int n = 0; n < NAVIOS; n++){  //libera memoria após exibir resultado
    free(navio[n]);
    //printf("Memória liberada com sucesso!!\n");
}


//FORMATAÇÃO DO TABULEIRO IMPRESSO COM NAVIOS INSERIDOS
//passo 1: imprimir cada letra de forma alinhada sobre a cada elemento da linha 0 da matriz representando as colunas do tabuleiro
/*printf("\n");
for(int i =0; i < 11;i++){
    printf("%-3c",letras[i]);
}
printf("\n");

//passo 2: imprimir a numeração identificadora de cada linha da matriz de 0 a 9
//passo 3: inicializar o tab preenchido com zeros
for(int i =0; i < 10;i++){
    printf("%2d ", i - 0);//primeiro imprime a numeração identificadora das linhas
    for(int j =0; j < 10;j++){ //agora com esse segundo 'for' inicializamos com zero em cada elemento a matriz que será o tabuleiro
        //tab[10][10] = tab[i][j] = 0;
        printf("%-2d ",tab[i][j]);
    }
printf("\n");
}*/

printaTab(letras,tab);

return 0;


}
