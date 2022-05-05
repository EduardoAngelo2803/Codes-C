#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define taml 7
#define tamc 10
int inicializador()
{
    srand(time(NULL));
    int dado1jog1 = 0, dado2jog1 = 0, dado1jog2 = 0, dado2jog2 = 0;
    //Gerando numeros aleatorios no dado;
    dado1jog1 = rand() % 6 + 1;
    dado2jog1 = rand() % 6 + 1;
    dado1jog2 = rand() % 6 + 1;
    dado2jog2 = rand() % 6 + 1;
    //Condicional para verificar se os dados do jogador 1 sao maiores que do jogador 2
    if (dado1jog1 + dado2jog1 > dado1jog2 + dado2jog2)
    {

        return 5;
    }
    else
    {

        return 10;
    }
}

void MatrizIndicativa(char tabuleiro[7][10])
{
    //Inicializando o tabuleiro
    for (int i = 0; i < taml; i++)
    {
        
        for (int j = 0; j < tamc; j++)
        {
            //Como o tabuleiro eh todo preenchido na linha 0     
            if (i == 0)
            {
                //C de comeco, e F de fim
                tabuleiro[i][0] = 'C';
                tabuleiro[i][1] = 'B';
                tabuleiro[i][2] = 'V';
                tabuleiro[i][3] = 'v';
                tabuleiro[i][4] = 'B';
                tabuleiro[i][5] = 'A';
                tabuleiro[i][6] = 'B';
                tabuleiro[i][7] = 'a';
                tabuleiro[i][8] = 'B';
                tabuleiro[i][9] = 'V';
            }
            //Na linha 6 ele tambem eh todo preenchido
            if (i == 6)
            {

                tabuleiro[i][0] = 'V';
                tabuleiro[i][1] = 'A';
                tabuleiro[i][2] = 'B';
                tabuleiro[i][3] = 'v';
                tabuleiro[i][4] = 'V';
                tabuleiro[i][5] = 'B';
                tabuleiro[i][6] = 'a';
                tabuleiro[i][7] = 'B';
                tabuleiro[i][8] = 'v';
                tabuleiro[i][9] = 'V';
            }
            //Na coluna 9, o tabuleiro tambem eh todo preenchido na vertical
            if (i != 0 && i != 6 && j == 9)
            {

                tabuleiro[1][j] = 'v';
                tabuleiro[2][j] = 'P';
                tabuleiro[3][j] = 'A';
                tabuleiro[4][j] = 'B';
                tabuleiro[5][j] = 'B';
            }
            //Caso a coluna seja 0
            if (j == 0)
            {
                //Caso a linha seja 3, 4 e 5. Ja que a 1 e 2 nao existe, e a 0 ja foi preenchida
                if (i != 1 && i != 2)
                {
                    //F de fim
                    tabuleiro[3][j] = 'F';
                    tabuleiro[4][j] = 'v';
                    tabuleiro[5][j] = 'a';
                }
                //Resto do tabuleiro eh vazio
                else if (i == 1 || i == 2)
                {

                    tabuleiro[i][j] = ' ';
                }
            }
            else if (i != 0 && i != 6 && j != 9 && j != 0)
            {

                tabuleiro[i][j] = ' ';
            }
        }
    }
}

void PrintarTabuleiro(char tabuleiro[7][10])
{
    printf("\n");
    for (int i = 0; i < taml; i++)
    {
        for (int j = 0; j < tamc; j++)
        {

            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

char VerPosIgual (int l, int c) {

    char matriz[taml][tamc];
    MatrizIndicativa(matriz);
    char aux;
    for(int i = 0; i < taml; i++) {

        for(int j = 0; j < tamc; j++) {

            if(l == i && c == j) {

                aux = matriz[i][j];

            }

        }
    }
    return aux;
}

void Verificador(char tabuleiro[7][10], char jog1, char jog2)
{
    srand(time(NULL));
    //Chamando a matriz que inicializa o tabueiro
    MatrizIndicativa(tabuleiro);
    int j1 = 10, j2 = 10;
    int cont = 0;
    int contA = 0, contB = 0;
    char aux = ' ', aux2 = ' ';
    int dado = 0;
    int somadado1 = 0, somadado2 = 0;
    int l = 0, c = 0, l2 = 0, c2 = 0;
    int j = 0, m = 0, i = 0;
    //Laco externo para pegar as jogadas dos dois jogadores
    while(m == 0) {
        //Laco do primeiro jogador

        if(aux == 'a' && contA == 0) {

            j = 1;
            contA = 1;

        }
        while (j == 0) {

            printf("\nVez do jogador %c, jogando dado..\n", jog1);
            //Dando um tempo de 2 segundos para jogar o dado
            sleep(2);
            //Apagando o tabuleiro
            system("clear");
            dado = rand() % 6 + 1;
            somadado1 += dado;
        
            printf("Numero do dado: %d\n", dado);

            if(l > 0 || c > 0) {
                
                if(l == l2 && c == c2) {

                    tabuleiro[l2][c2] = jog2;
                }else {

                    tabuleiro[l][c] = aux;
                }
               
            }

            if (somadado1 < 9)
            {
                l = 0;
                c = somadado1;
                aux = tabuleiro[l][c];
                tabuleiro[l][c] = jog1;

            }else if(somadado1 >= 9 && somadado1 < 15) {
               
                l = somadado1 - 9;
                c = 9;
                aux = tabuleiro[l][c];
                tabuleiro[l][c] = jog1;
            
            }else if (somadado1 >= 15 && somadado1 < 24) {

                l = 6;
                c = 9 - (somadado1 - 15);
                aux = tabuleiro[l][c];
                tabuleiro[l][c] = jog1;

            }else if(somadado1 >= 24) {

                l = 6 - (somadado1 - 24);
                c = 0;
                aux = tabuleiro[l][c];
                tabuleiro[l][c] = jog1;
            }
            //Caso chegue na ultima casa, ou passe dela
            if (c == 0 && l <= 3)
            {
                printf("Jogador %c venceu!\n", jog1);
                printf("Com %d pontos de vida restantes!\n", j1);
                aux = VerPosIgual(l, c);
                tabuleiro[l][c] = aux;
                tabuleiro[3][0] = jog1;
                
                tabuleiro[l2][c2] = jog2;
                 if(l2 == 0 && c2 == 0) {

                    tabuleiro[0][0] = jog2;
                }
                PrintarTabuleiro(tabuleiro);
                m = 1;
                break;
            }
             
            if(l == l2 && c == c2){

                aux = VerPosIgual(l, c);
                printf("Os dois jogadores estao na mesma posicao! indicado com o numero '3' no tabuleiro!\n");
                tabuleiro[l][c] = '3';
                tabuleiro[0][0] = 'C';
                PrintarTabuleiro(tabuleiro);
                tabuleiro[l][c] = aux;
                
                break;
                
            }
            if((l != 0 || c!= 0) && (l2 != 0 || c2 != 0)) {
            
                tabuleiro[0][0] = 'C';

            }

            
            if (aux == 'P')
            {
               
                PrintarTabuleiro(tabuleiro);
                printf("Casa preta, Volte pro inicio!\n");
                tabuleiro[l][c] = 'P';
                l = 0;
                c = 0;
                tabuleiro[l][c] = jog1;          
                j = 1;
                somadado1 = 0;
            }
            else if (aux == 'B')
            {        
                PrintarTabuleiro(tabuleiro);
                printf("Casa branca, nada acontece...!\n");            
                j = 1;
            }
            else if (aux == 'V')
            {
                PrintarTabuleiro(tabuleiro);
                printf("Casa vermelha, perdeu 3 pontos de vida! vida restante: %d\n", j1 - 3);
                if(j1 <= 0) {

                    printf("Jogador %c perdeu, pois sua vida foi zerada!\n", j1);
                    m = 1;
                    break;
        
                }
                j1 = j1 - 3;
                j = 1;
            }
            else if (aux == 'v')
            {
                PrintarTabuleiro(tabuleiro);
                 if(j1 < 10) {

                printf("Casa verde, voce esta com sorte! +1 ponto de vida! vida restante: %d\n", j1 + 1);

                }else if(j1 >= 10) {

                    printf("Casa verde, voce esta com sorte! +1 ponto de vida! Como a vida maxima de 10 ja foi atingida, jogador %c permanece com 10 pts de vida!\n", jog1);
                    j1 = 10;
                }
           
                j = 1;
            }
            else if (aux == 'a')
            {
                
                PrintarTabuleiro(tabuleiro);
                printf("Casa amarela, Voce vai passar 1 rodada sem jogar!\n");             
                j = 1;
                contA = 0;
            }
            else if (aux == 'A')
            {

                PrintarTabuleiro(tabuleiro);
                printf("Casa azul, voce pode jogar novamente!\n");       
                
          
            }      

            if(aux == 'A') {

                tabuleiro[l2][c2] = jog2;

            }
        }

        if(m == 1) {

            break;
        }

        j = 0;

        if(aux2 == 'a' && contB == 0) {

            i = 1;
            contB = 1;
        }

        while(i == 0) {

            printf("\nVez do jogador %c, jogando dado..\n", jog2);
            sleep(2);
            system("clear");
            dado = rand() % 6 + 1;
            somadado2 += dado;
    
            printf("Numero do dado: %d\n", dado);

            if(l2 > 0 || c2 > 0) {

                if(l == l2 && c == c2) {

                    tabuleiro[l][c] = jog1;
                }else {

                    tabuleiro[l2][c2] = aux2;
                }
            }
            if (somadado2 < 9)
            {
                l2 = 0;
                c2 = somadado2;
                aux2 = tabuleiro[l2][c2];
                tabuleiro[l2][c2] = jog2;

            }else if(somadado2 >= 9 && somadado2 < 15) {
               
                l2 = somadado2 - 9;
                c2 = 9;
                aux2 = tabuleiro[l2][c2];
                tabuleiro[l2][c2] = jog2;
            
            }else if (somadado2 >= 15 && somadado2 < 24) {

                l2 = 6;
                c2 = 9 - (somadado2 - 15);
                aux2 = tabuleiro[l2][c2];
                tabuleiro[l2][c2] = jog2;

            }else if(somadado2 >= 24) {

                l2 = 6 - (somadado2-24);
                c2 = 0;
                aux2 = tabuleiro[l2][c2];
                tabuleiro[l2][c2] = jog2;
            }

            if (c2 == 0 && l2 <= 3)
            {
                printf("Jogador %c venceu!\n", jog2);
                printf("Com %d pontos de vida restantes!\n", j2);
                aux2 = VerPosIgual(l2, c2);
                tabuleiro[l2][c2] = aux2;
                tabuleiro[3][0] = jog2;               
                tabuleiro[l][c] = jog1;

                 if(l == 0 && c == 0) {

                    tabuleiro[0][0] = jog1;
                }
                PrintarTabuleiro(tabuleiro);
                m = 1;
                break;
            }

            if((l2 != 0 || c2!= 0) && (l != 0 || c != 0)) {
            
                tabuleiro[0][0] = 'C';

            }

             if(l == l2 && c == c2){

                aux2 = VerPosIgual(l, c);
                printf("Os dois jogadores estao na mesma posicao! indicado com o numero '3' no tabuleiro!\n");
                tabuleiro[l2][c2] = '3';
                tabuleiro[0][0] = 'C';
                PrintarTabuleiro(tabuleiro);
                tabuleiro[l2][c2] = jog2;
                
                break;
                
            }
            if (aux2 == 'P')
            {
               
                PrintarTabuleiro(tabuleiro);
                printf("Casa preta, Volte pro inicio!\n");
                tabuleiro[l2][c2] = 'P';
                c2 = 0;
                l2 = 0;
                tabuleiro[l2][c2] = jog2;
                i = 1;
                somadado2 = 0;
            }
            else if (aux2 == 'B')
            {
                
                PrintarTabuleiro(tabuleiro);
                printf("Casa branca, nada acontece...!\n");
            
                i = 1;
            }
            else if (aux2 == 'V')
            {
               
                PrintarTabuleiro(tabuleiro);
                printf("Casa vermelha, perdeu 3 pontos de vida! vida restante: %d\n", j2 - 3);
              
                j2 = j2 - 3;
                i = 1;

                if(j2 <= 0) {

                    printf("Jogador %c perdeu, pois a vida foi zerada!\n", jog2);
                    m = 1;
                    break;
                }
            }
            else if (aux2 == 'v')
            {
            
                PrintarTabuleiro(tabuleiro);

                if(j2 < 10) {

                printf("Casa verde, voce esta com sorte! +1 ponto de vida! vida restante: %d\n", j2 + 1);

                }else if(j2 >= 10) {

                    printf("Casa verde, voce esta com sorte! +1 ponto de vida! Como a vida maxima de 10 jq foi atingida, jogador %c permanece com 10 pts de vida!\n", jog2);
                    j2 = 10;
                }
           
                j2 = j2 + 1;
                i = 1;
            }
            else if (aux2 == 'a')
            {
                PrintarTabuleiro(tabuleiro);
                printf("Casa amarela, Voce vai passar 1 rodada sem jogar!\n");
                i = 1;
                contB = 0;
            }
            else if (aux2 == 'A')
            {
                
                PrintarTabuleiro(tabuleiro);
                printf("Casa azul, voce pode jogar novamente!\n");
              
            
            }

            if(aux2 == 'A') {

                tabuleiro[l][c] = jog1;

            }
        }
             
        cont++;

        i = 0;

        
    }
}

void InicializadorJogo(char tabuleiro[7][10], char jog1, char jog2)
{

    int i;

    i = inicializador();

    if (i == 5)
    {
        printf("Jogador 1 comeca jogando...\n");
        Verificador(tabuleiro, jog1, jog2);
    }
    else if (i == 10)
    {
        printf("Jogador 2 comeca jogando...\n");
        Verificador(tabuleiro, jog2, jog1);
    }
}

int main() {

    int opc = 0;
    char m[taml][tamc];
    char jog1 = '1';
    char jog2 = '2';
    int r = 0;
    char resp;
    printf("////////////////////////// BEM-VINDO ///////////////////////\n");
    printf("///////////////////// AO THE MAZE RUNNER ///////////////////\n");
    printf("\n\n");

    printf("     \                           /\n");
    printf("      \                         /\n");
    printf("       \                       /\n");
    printf("        ]                     [    ,'|\n");
    printf("        ]                     [   /  |\n");
    printf("        ]               [ ,'   |\n");
    printf("        ]  ]\             /[  [ |:   |\n");
    printf("        ]  ] \           / [  [ |:   |\n");
    printf("        ]  ]  ]         [  [  [ |:   |\n");
    printf("        ]  ]  ]     [  [  [ |:   |\n");
    printf("        ]  ]  ] ]\  /[ [  [  [ |:   |\n");
    printf("        ]  ]  ] ] (@) [ [  [  [ :===='\n");
    printf("        ]  ]  ]].nHn.[_[  [  [\n");
    printf("        ]  ]  ]  HHHHH. [  [  [\n");
    printf("        ]  ] /   `HH(""N  \ [  [\n");
    printf("        ]]/     HHH  ""  \[[\n");
    printf("        ]         NNN         [\n");
    printf("        ]         N/""         [\n");
    printf("        ]         N H         [\n");
    printf("       /          N            \\n");
    printf("      /           q,            \\n");
    printf("     /                           \\n");

    while(r == 0) {

        printf("\n|||||||||| Bem-vindo ao menu ||||||||||\n\n");
        printf("1 - Instruçes (Comece por aqui)\n");
        printf("2 - Visualizar tabuleiro com cores indicativas\n");
        printf("3 - Jogar\n");

        scanf("%d", &opc);

        printf("\n");
    
    
        switch (opc)
        {

        case 1:

            printf("Celula 'V' -2 pontos de vida, celula 'v' +1 ponto de vida, celula 'a' o jogador perde a vez, celula 'A' permite jogar novamente, celula 'P' faz voltar pro inicio tabuleiro e celula 'B' nao acontece nada\nO tabuleiro indicativo pode ser visualizado na opcao 2 do menu\n");
            break;

        case 2:

            MatrizIndicativa(m);
            PrintarTabuleiro(m);
            break;

        case 3:

            InicializadorJogo(m, jog1, jog2);
            break;
        }

        printf("\nDeseja continuar jogando? S/N: ");
        scanf(" %c", &resp);
        resp = toupper(resp);
        
        if(resp == 'N') {

            r = 1;
        }
    }

    printf("Ate mais, obrigado por jogar! \n");

    return 0;
}