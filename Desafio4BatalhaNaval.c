#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define TAM 10

void Tabuleiro (char matrizJog1[10][10], char matrizJog2[10][10]) {
    //Inicializando o tabuleiro com '_'
    for(int i = 0; i < TAM; i++) {

        for(int j = 0; j < TAM; j++) {

            matrizJog1[i][j] = '_';
            matrizJog2[i][j] = '_';
        }
    }

    int jog1_l, jog1_c, jog2_l, jog2_c;
    int cont = 0, cont2 = 0;
    srand(time(NULL));
    //Laco para gerar as embarcacoes de forma aleatoria dos dois jogadores
    while(cont2 < 3) {
        //Gerando as posicoes aleatorias
        jog1_l = rand()%10;
        jog1_c = rand()%10; 
        jog2_l = rand()%10;
        jog2_c = rand()%10;
        //Caso as posicoes de linha e coluna forem diferentes dos dois jogadores
        if(jog1_l != jog2_l && jog1_c != jog2_c) {
            //Se o espaco a ser preenchido pela embarcacao estiver vazio
            if(matrizJog1[jog1_l][jog1_c] == '_' && matrizJog2[jog2_l][jog2_c] == '_') {
                //Como sao 3 embarcacoes simples por jogadores, o laco roda ate 3
                if(cont < 3) {
                //Posiciona as embarcacoes simples dos dois jogadores, e adiciona 1 a variavel contadora no fim
                matrizJog1[jog1_l][jog1_c] = 'P';
                matrizJog2[jog2_l][jog2_c] = 'V';
                cont++;

                }
            }
            //Primeiro vai-se colocar as embarcacoes simples, e apos isso, ou seja, quando a variavel contadora for 3, os numeros aleatorios vao entrar nesse laco
            //Nao foi colocado ao mesmo tempo, pois esta sendo criado apenas 1 numero aleatorio de linha e coluna por jogador, logo, ia sobrescrever as embarcacoes
            if(cont == 3) {
                //Se o espaco a ser preenchido pela embarcacao estiver vazio
                if(matrizJog1[jog1_l][jog1_c] == '_' && matrizJog2[jog2_l][jog2_c] == '_') {
                    //Como a embarcacao dupla ocupa duas casas, a coluna tem que ser no maximo 8, pois se for 9, nao da para colocar a sua direita.
                    //Adicionamos a posicao da embarcacao, e a posicao seguinte, para sinalizar que e uma embarcacao dupla, variavel contadora e somada
                    if(jog1_c <= 8 && jog2_c <= 8) {
                    matrizJog1[jog1_l][jog1_c] = 'P';
                    matrizJog1[jog1_l][jog1_c+1] = 'p';
                    matrizJog2[jog2_l][jog2_c] = 'V';
                    matrizJog2[jog2_l][jog2_c+1] = 'v';
                    cont2++;
                    }
                }         
            }  
        } 
    }
}

void printMatriz (char matrizTab1[10][10], char matrizTab2[10][10]) {
    
    char resp;
    int tempVisu;

    printf("Deseja visualizar a matriz para auxiliar no teste do codigo? S/N: ");
    scanf("%c", &resp);
 
    //Convertendo a resposta para maisculo
    resp = toupper(resp);
    //Caso a resposta seja Sim, pergunta quantos segundos quer visualizar, e printa a matriz. Se for N, ele apenas pula essa parte e continua o código
    if(resp == 'S') {

        printf("Por quantos segundos deseja visualizar a matriz? ");
        scanf("%d", &tempVisu);
        
        for(int i = 0; i < TAM; i++) {

            for(int j = 0; j < TAM; j++) {

                printf("%c ", matrizTab1[i][j]);

            }
            printf("\n");
        }
    
        printf("\n\n");
        for(int i = 0; i < TAM; i++) {

            for(int j = 0; j < TAM; j++) {

                printf("%c ", matrizTab2[i][j]);

            }
            printf("\n");
        }
        Sleep(5000);
        system("cls");
    }
    
}

void Verificador(char matrizTab[10][10], char matrizTab2[10][10]) {

    int j1_l, j2_l, j1_c, j2_c;
    int i = 0;
    int contj1 = 0, contj2 = 0;
    
    //Laco que so vai parar quando algum jogador vencer
    while(i == 0) {
        //Pegando o input do do jogador 1
        printf("Jogador 1, escolha as coordenadas de onde deseja 'atacar': ");
        scanf("%d %d", &j1_l, &j1_c);
        //Caso a posicao que ele deseja for uma embarcacao simples, ou seja, a posicao sinalizada por 'V' e a seguinte nao for 'v'
        if (matrizTab[j1_l][j1_c] == 'V' && matrizTab[j1_l][j1_c+1] != 'v') {
            
            printf("Voce acertou uma embarcacao simples!\n");
            //Zerando a embarcacao, retornando aquela posicao da matriz o '_', que equivale a espaco vazio
            matrizTab[j1_l][j1_c] = '_';
            //Adicionando 1 a variavel de contagem de acertos do jogador 1, que entrara nos 3 casos possiveis de acerto.
            contj1++;
        //Caso seja uma embarcacao dupla, ou seja, posicao inicial 'V' e a proxima posicao 'v'  
        }else if (matrizTab[j1_l][j1_c] == 'V' && matrizTab[j1_l][j1_c+1] == 'v') {

            printf("Voce acertou uma embarcacao dupla!\n"); 
            matrizTab[j1_l][j1_c] = '_';
            matrizTab[j1_l][j1_c+1] = '_';  
            contj1++;
           
        //Caso a posicao seja 'v', quer dizer que e uma embarcacao dupla, logo, zeramos ela, e sua posicao de coluna anterior
        }else if (matrizTab[j1_l][j1_c] == 'v') {

            printf("Voce acertou uma embarcacao dupla!\n");
            matrizTab[j1_l][j1_c] = '_';
            matrizTab[j1_l][j1_c-1] = '_';     
            contj1++;
        //Caso a embarcacao seja do proprio jogador
        }else if (matrizTab[j1_l][j1_c] == 'P' || matrizTab[j1_l][j1_c] == 'p') {

            printf("Nao e possivel acertar sua propria embarcacao!\n");
        //Caso nao acerte nenhuma embarcacao, e printada a informacao na tela
        }else {

            printf("Nenhuma embarcacao acertada!\n");

        }
        //Pegando input do jogador 2, e toda logica do jogador 1 se repete!
        printf("Jogador 2, escolha as coordenadas de onde deseja 'atacar': ");
        scanf("%d %d", &j2_l, &j2_c);

        if (matrizTab2[j2_l][j2_c] == 'P' && matrizTab2[j2_l][j2_c+1] != 'p') {
            
            printf("Voce acertou uma embarcacao simples!\n");
            matrizTab2[j2_l][j2_c] = '_';
            contj2++;

        }else if (matrizTab2[j2_l][j2_c] == 'P' && matrizTab2[j2_l][j2_c+1] == 'p') {

            printf("Voce acertou uma embarcacao dupla!\n"); 
            matrizTab2[j2_l][j2_c] = '_';
            matrizTab2[j2_l][j2_c+1] = '_';  
            contj2++;
           
        }else if (matrizTab2[j2_l][j2_c] == 'p') {

            printf("Voce acertou uma embarcacao dupla!\n");
            matrizTab2[j2_l][j2_c] = '_';
            matrizTab2[j2_l][j2_c-1] = '_';     
            contj2++;

        }else if (matrizTab2[j2_l][j2_c] == 'V' || matrizTab2[j2_l][j2_c] == 'v') {

            printf("Nao e possivel acertar sua propria embarcacao!\n");
            
        }else {

            printf("Nenhuma embarcacao acertada!\n");

        }

        if (contj1 == 6) {

            printf("Jogador 1 venceu!\n");
            break;

        }else if(contj2 == 6) {

            printf("Jogador 2 venceu!\n");
            break;
        }
    }
}

int main () {

    char matriz1[10][10];
    char matriz2[10][10];
    printf("//////////////////////////     BATALHA    //////////////////////////\n");
    printf("//////////////////////////      NAVAL    ////////////////////////////\n\n");
    Tabuleiro(matriz1, matriz2);
    printMatriz(matriz1, matriz2);
    Verificador(matriz2, matriz1);
    printMatriz(matriz1, matriz2);

    return 0;
}
