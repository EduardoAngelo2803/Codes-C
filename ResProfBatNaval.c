#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {

  srand(time(NULL));

  int tam = 10;
 
  int mat_jog1[tam][tam], mat_jog2[tam][tam];

  int barcos_jog1 = 10, barcos_jog2 = 10;

  for(int l = 0; l < tam; l++)
    {
      for(int c = 0; c < tam; c++)
        {
          mat_jog1[l][c] = 0;
          mat_jog2[l][c] = 0;
        }
    }
 
  for(int barco = 1; barco <= barcos_jog1; )
    {
      int b_l = rand()%tam;
      int b_c = rand()%tam;

      if(mat_jog1[b_l][b_c] == 0)
      {
        mat_jog1[b_l][b_c] = 1;
        barco++;
      }
    }

  for(int barco = 1; barco <= barcos_jog2; )
    {
      int b_l = rand()%tam;
      int b_c = rand()%tam;

      if(mat_jog2[b_l][b_c] == 0)
      {
        mat_jog2[b_l][b_c] = 2;
        barco++;
      }
    }

    /*
 
    for(int l = 0; l < tam; l++)
    {
      for(int c = 0; c < tam; c++)
        {
          printf("%i ", mat_jog1[l][c]);
        }
      printf("\n");
    }

  printf("\n\n");

  for(int l = 0; l < tam; l++)
    {
      for(int c = 0; c < tam; c++)
        {
          printf("%i ", mat_jog2[l][c]);
        }
      printf("\n");
    }
  */

  int jog_atual = 1;
  do
  {

    for(int l = 0; l < tam; l++)
    {
      for(int c = 0; c < tam; c++)
        {
          printf("%i ", mat_jog1[l][c]);
        }
      printf("\n");
    }

  printf("\n\n");

  for(int l = 0; l < tam; l++)
    {
      for(int c = 0; c < tam; c++)
        {
          printf("%i ", mat_jog2[l][c]);
        }
      printf("\n");
    }
   
    int linha, coluna;
   
    printf("Jogador %i, digite a coordenada desejada: ", jog_atual);
    scanf("%i %i", &linha, &coluna);
    getchar();

    if(jog_atual == 1)
    {
      if(mat_jog2[linha][coluna] == 2)
      {
        mat_jog2[linha][coluna] = 0;
        barcos_jog2--;

        printf("\nVoce acertou!\n");
      }
      jog_atual = 2;
    }
    else if(jog_atual == 2)
    {
      if(mat_jog1[linha][coluna] == 1)
      {
        mat_jog1[linha][coluna] = 0;
        barcos_jog1--;

        printf("\nVoce acertou!\n");
      }
      jog_atual = 1;
    }

    printf("\n\n");

  system("@cls||clear");
   
  }while(1);
 
 
  return 0;
  }