#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

//Professor, desculpe por ter feito sem função, comecei fazendo um esboço no replit e acabou fluindo, então preferi continuar o código na main mesmo
int main () {

  srand(time(NULL));
  int num = 0;
  int num2 = 0;
  int matrizNumeros[4][4];
  int mostrador[16];
  int l, c;
  char resp;
  int tempVisu;
  //Inicializar o vetor que vai guardar as posicoes 
  for(int h = 0; h < 16; h++) {

    mostrador[h] = 0;
    
  }
  //Inicialziar a matriz 
  for(int i = 0; i < 4; i++) {

    for(int j = 0; j < 4; j++) {

      matrizNumeros[i][j] = 0;

    }
  }
  //Colcocar duplas aleatórias de 1 até 8, na matriz
  do {

    l = rand()%4;
    c = rand()%4;

    if(matrizNumeros[l][c] == 0) {

        matrizNumeros[l][c] = num+1;
        num2++;

        if(num2 >= 2) {

            num++;
            num2 = 0;
        }
    }

  } while(num < 8);

  //Perguntando ao usuário/admin se deseja visualizar a matriz para testes, ou para facilitar a jogatina
  printf("Deseja visualizar a matriz para auxiliar no teste do codigo? S/N: ");
  scanf("%c", &resp);
 
  //Convertendo a resposta para maisculo
  resp = toupper(resp);
  //Caso a resposta seja Sim, pergunta quantos segundos quer visualizar, e printa a matriz. Se for N, ele apenas pula essa parte e continua o código
  if(resp == 'S') {

    printf("Por quantos segundos deseja visualizar a matriz? ");
    scanf("%d", &tempVisu);

    for(int i = 0; i < 4; i++) {

      for(int j = 0; j < 4; j++) {

        printf("%d ", matrizNumeros[i][j]);

      }
      printf("\n");
    }

    //Funcao criada para ajudar no teste do jogo, mostrando por 5 segundos a matriz, depois apagando
    Sleep(tempVisu*1000);
    system("cls");
  
  }

  int contjog1 = 0, jogadas = 0, contjog2 = 0;
  int j1_l2, j1_c2, j1_l1, j1_c1, j2_l1, j2_c1, j2_l2, j2_c2;
  int contVetor = 0;

  //Laco que vai rodar até todas as cartas foram desviradas
  while(contjog1 < 9) {

    //Jogador 1
    printf("J1, 1 coordenadas: ");
    scanf("%d %d", &j1_l1, &j1_c1);

    printf("J1, 2 coordenadas: ");
    scanf("%d %d", &j1_l2, &j1_c2);
    //Entra na condicional se os numeros das coordenadas da 1 e 2 carta forem iguais
    if(matrizNumeros[j1_l1][j1_c1] == matrizNumeros[j1_l2][j1_c2]) {
      //Laco que percorre a matriz
      for(int i = 0; i < 4; i++) {

        for(int j = 0; j < 4; j++) {
          //Caso o i (linha) e o j (coluna) da 2 carta forem iguais as coordenadas (linha e coluna) que o jogador digitou
          if(i == j1_l2 && j == j1_c2) {
            //Se for igual, adiciona o numero pertencente a coordenada digitada pelo usuario ao vetor, que ira armazenar todos os numeros da matriz
            mostrador[contVetor] = matrizNumeros[i][j];
            printf("%d ", mostrador[contVetor]);
            
            //Caso a linha ou a coluna seja diferente
          }else if(i != j1_l1 || j != j1_c1) {
            //Caso a posicao do vetor esteja zerada, ou seja, o usuario ainda nao "inputou" aquela coordenada, vai printar #, que seria a carta sem estar virada
            if(mostrador[contVetor] == 0) {

              printf("# ");
            //Caso contrário, mostra o número armazenado no vetor
            }else {

              printf("%d ", mostrador[contVetor]);

            }
          }
          //Caso o i (linha) e o j (coluna) da 1 carta forem iguais as coordenadas (linha e coluna) que o jogador digitou
          if(i == j1_l1 && j == j1_c1) {
            //Se for igual, adiciona o numero pertencente a coordenada digitada pelo usuario ao vetor, que ira armazenar todos os numeros da matriz
            mostrador[contVetor] = matrizNumeros[i][j];
            printf("%d ", mostrador[contVetor]);
          }
          //Adiciona 1 ao contador, para no fim do laco interno, armazenar na proxima posicao
          contVetor++;
        }
        printf("\n");
      }
      //Ao fim do laco externo, zeramos a posicao do vetor
      contVetor = 0;
      //Adiciona 1 a variavel contadora do jogador1, pois se entrar nessa condicional, é porque ele acertou a carta
      contjog1++;
      printf("Jogador 1 acertou!\n");

      //Caso as cartas não sejam iguais, irá entrar no else, e a logica é a mesma do if, pois a questao pede pra desvirar as cartas quando erra
    }else {
     
    for(int i = 0; i < 4; i++) {

      for(int j = 0; j < 4; j++ ) {

         if (mostrador[contVetor] != 0) {

            printf("%d ", mostrador[contVetor]);

        }else {

          if(i == j1_l1 && j == j1_c1) {

            mostrador[contVetor] = matrizNumeros[i][j];
            printf("%d ", mostrador[contVetor]);     

          }else {
            
            if(j1_l2 != i || j1_c2 != j) {
              
              printf("# ");
        
            }
          }
          if(i == j1_l2 && j == j1_c2) {

            mostrador[contVetor] = matrizNumeros[i][j];
            printf("%d ", mostrador[contVetor]);
          
          }
        }
        contVetor++;      
      }
      printf("\n");     
    }

    contVetor = 0;
    printf("Jogador 1 Errou! \n");

   }
    //Jogador 2 segue a mesma logica do jogador 1
    printf("J2, 1 coordenadas: ");
    scanf("%d %d", &j2_l1, &j2_c1);

    printf("J2, 2 coordenadas: ");
    scanf("%d %d", &j2_l2, &j2_c2);

    if(matrizNumeros[j2_l1][j2_c1] == matrizNumeros[j2_l2][j2_c2]) {

      for(int i = 0; i < 4; i++) {

        for(int j = 0; j < 4; j++) {

          if(i == j2_l2 && j == j2_c2) {

            mostrador[contVetor] = matrizNumeros[i][j];
            printf("%d ", mostrador[contVetor]);

          }else if(i != j2_l1 || j != j2_c1) {

            if(mostrador[contVetor] == 0) {

              printf("# ");

            }else {

              printf("%d ", mostrador[contVetor]);

            }
          }
          if(i == j2_l1 && j == j2_c1) {

            mostrador[contVetor] = matrizNumeros[i][j];
            printf("%d ", mostrador[contVetor]);
          }
          contVetor++;
        }
        printf("\n");        
      }

      contVetor = 0;
      contjog2++;
      printf("Jogador 2 acertou!\n");

    }else {
     
    for(int i = 0; i < 4; i++) {

      for(int j = 0; j < 4; j++ ) {

         if (mostrador[contVetor] != 0) {

            printf("%d ", mostrador[contVetor]);     


        }else {

          if(i == j2_l1 && j == j2_c1) {
            
            mostrador[contVetor] = matrizNumeros[i][j];
            printf("%d ", mostrador[contVetor]);
              

          }else {
            
            if(j2_l2 != i || j2_c2 != j) {
              
              printf("# ");
        
            }
          }
          if(i == j2_l2 && j == j2_c2) {

            mostrador[contVetor] = matrizNumeros[i][j];
            printf("%d ", mostrador[contVetor]);
          
          }
        }
        contVetor++;      
      }
      printf("\n");
      
      }

    contVetor = 0;
    printf("Jogador 2 Errou! \n");

    }
  
    //Variável contadora para ver se todas as posições do vetor foram preenchidas
    int contFinal = 0;
    //Laco para percorrer o vetor que esta armazenando as posicoes
    for(int i = 0; i < 16; i++) {

      if(mostrador[i] != 0) {

        contFinal++;
      
     }
    }
    //Condicao para ver se o vetor foi preenchido, quer dizer que todas as cartas foram viradas
    if(contFinal == 16) {
      
      if(contjog1 > contjog2) {

        printf("\n");
        printf("Jogador 1 venceu!");
        break;

      }else if(contjog2 > contjog1) {

        printf("\n");
        printf("Jogador 2 venceu!");
        break;

      }else if(contjog1 == contjog2) {

        printf("\n");
        printf("Empate!");
        break;
      
      }
    }
  }

return 0;

}
