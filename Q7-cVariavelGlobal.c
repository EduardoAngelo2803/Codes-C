#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


typedef struct {

  char nome_filme[30];
  char id[11];
  char categoria[20];
  int entrada;
  int assento_linha;
  int assento_coluna;
  float valor;

} Compra;


void aberturaCinema() {

  printf("=========================================================\n");
  printf("                 BEM VINDO AO CINEMA!                      \n");
  printf("=========================================================\n\n");
  printf("                   ________________ \n");
  printf("            ______|   Em Cartaz:   |______ \n");
  printf("           |                              |\n");
  printf("           |       O PESO DO TALENTO      |\n");
  printf("    _______|______________________________|_________\n");
  printf("   |________________________________________________|\n");
  printf("   |               -                -               |\n");
  printf("   |   -       -        CINEMAX        -          - |\n");
  printf("   |        ____    ______________-   ____          |\n");
  printf("   | -  -  |    |   | BILHETERIA |   |    | -       |\n");
  printf("   |       |    |   |            |   |    |         |\n");
  printf("   |  --   |____| - |_o___oo___o_| - |____|     -   |\n");
  printf("   | -     |    |  |     --       |  |    |         |\n");
  printf("   |    -  |    |- | -      -     |  |    | --      |\n");
  printf("   |_______|====|__|______________|__|====|_________|\n");
  printf("   /.                                                \\\n");
  printf("  /___________________________________________________\\\n\n");
}

void salaVazia(int tam, char sala[tam][tam]) {

  for (int l = 0; l < tam; l++) {
    for (int c = 0; c < tam; c++) {
      sala[l][c] = '-';
    }
  }
}

void imprimirSala(int tam, char sala[tam][tam]) {

  printf("\nSALA PRIME\n\n");

  for (int l = 0; l < tam; l++) {
    for (int c = 0; c < tam; c++) {
      printf("%c ", sala[l][c]);
    }
    printf("\n");
  }
}

void preencherSala(int tam, Compra registro[tam * tam], char sala[tam][tam], int i) {

  if (sala[registro[i].assento_linha][registro[i].assento_coluna] == '-') {
    sala[registro[i].assento_linha][registro[i].assento_coluna] = 'O';
   

  } else {
    printf("\nO assento escolhido não está disponível\n\n");
  
  }
}

void registroCompra(int tam, Compra registro[tam * tam], int i, char sala[tam][tam]) {

  int j;

  printf("\nInforme o nome do filme: ");
  scanf(" %[^\n]", registro[i].nome_filme);
  printf("\n");
  printf("Informe o ID do filme: ");
  scanf("%s", registro[i].id);
  printf("\n");
  printf("Informe a categoria do filme: ");
  scanf(" %[^\n]", registro[i].categoria);
  printf("\n");
  printf("Informe o tipo da entrada\n1 - Meia e 2 - Inteira: ");
  scanf("%i", &registro[i].entrada);
  printf("\n");
  printf("Informe a linha e coluna do assento: \n");
  scanf("%i %i", &registro[i].assento_linha, &registro[i].assento_coluna);
  j = verificarAssento(sala, registro[i].assento_linha, registro[i].assento_coluna);
  while(j == 0) {

    printf("Informe a linha e coluna do assento: \n");
    scanf("%i %i", &registro[i].assento_linha, &registro[i].assento_coluna);
    j = verificarAssento(sala, registro[i].assento_linha, registro[i].assento_coluna);
    
  }

  printf("\n");
  printf("Informe o valor do ingresso: ");
  scanf("%f", &registro[i].valor);
    
  sala[registro[i].assento_linha][registro[i].assento_coluna] = 'O';
      
}

void quantidadeMeiasInteiras(int tam, Compra registro[tam * tam]) {

  int qnt_meias = 0, qnt_inteiras = 0;

  for (int i = 0; i < (tam * tam); i++) {

    if (registro[i].entrada == 1) {

      qnt_meias++;

    } else if (registro[i].entrada == 2) {

      qnt_inteiras++;
    }
  }

  printf("\nAté o momento foram vendidas %d meias entradas e %d inteiras.\n",
         qnt_meias, qnt_inteiras);
}

void valorArrecadado(int tam, Compra registro[tam * tam], float somatorio) {

  for (int i = 0; i < (tam * tam); i++) {
    somatorio = somatorio + registro[i].valor;
  }

  printf("\nO Valor total arrecadado pela Sala Prime foi: R$ %.2f\n",
         somatorio);
}

void disponibilidadeAssentos(int tam, Compra registro[tam * tam], char sala[tam][tam]) {

  int ver_disponibilidade = 0;

  for (int l = 0; l < tam; l++) {
    for (int c = 0; c < tam; c++) {
      if (sala[l][c] == '-') {

        ver_disponibilidade++;

      }
    }
  }

  if (ver_disponibilidade <= (tam * tam)) {
    printf("Temos %d assento(s) disponível(eis) na Sala Prime.\n", ver_disponibilidade);

  }
  if (ver_disponibilidade == 0) {
    printf("\nNão há mais assentos disponíveis.\n\n");
  }
}

int verificarAssento(char sala[2][2], int l, int c) {  

  for(int i = 0; i < 4; i++) {

    for(int j = 0; j < 4; j++) {

      if(sala[l][c] == 'O') {

        printf("Assento ja ocupado!\n");
        return 0;

      }else {

        return 1;
      }
    } 
  }
}
/*
void executarPrograma(void){

  // Declaração de variáveis
  int tam = 2;
  Compra registro[tam * tam];
  char sala[tam][tam];
  float somatorio = 0.00;

  // Tela de abertura
  aberturaCinema();

  // Vizualização da sala vazia
  salaVazia(tam, sala);

  // Registro de Compra do Ingresso

  for (int i = 0; i < ((tam * tam) + 1); i++) {

    char verificador;

    printf(
        "O que você deja fazer? \na - registrar uma nova venda;\nb - Verificar "
        "o montante arrecado pela Sala Prime; \nc - Verificar a quantidade de "
        "meias entradas e inteiras vendidas pela Sala Prime; \nd - Verificar "
        "se há espaço disponível na Sala Prime; \ne - Encerrar a "
        "aplicação.\n\n");

    scanf(" %c", &verificador);

    if ((verificador == 'a' || verificador == 'A') && i < (tam * tam)) {
      system("clear");

      imprimirSala(tam, sala);
      registroCompra(tam, registro, i);
      preencherSala(tam, registro, sala, i);
      printf("\n");

    } else if (verificador == 'b' || verificador == 'B') {
      system("clear");
      valorArrecadado(tam, registro, i, somatorio);
      printf("\n");
      i--;

    } else if (verificador == 'c' || verificador == 'C') {
      system("clear");
      quantidadeMeiasInteiras(tam, registro, i);
      printf("\n");
      i--;

    } else if ((verificador == 'd' || verificador == 'D')) {
      system("clear");
      disponibilidadeAssentos(tam, registro, sala, i);
      printf("\n");
      i--;

    } else {
      printf("\nAté a próxima!\n");
      break;
   
    }
  }

}
*/

int main(void) {

/*
  executarPrograma();
*/

  // Declaração de variáveis
  int tam = 2;
  Compra registro[tam * tam];
  char sala[tam][tam];
  float somatorio = 0.0;
  char verificador;
  int i = 0;
  // Tela de abertura
  aberturaCinema();

  // Vizualização da sala vazia
  salaVazia(tam, sala);

  // Registro de Compra do Ingresso

  do{

    printf(
        "O que você deja fazer? \na - registrar uma nova venda;\nb - Verificar "
        "o montante arrecado pela Sala Prime; \nc - Verificar a quantidade de "
        "meias entradas e inteiras vendidas pela Sala Prime; \nd - Verificar "
        "se há espaço disponível na Sala Prime; \ns - Encerrar a "
        "aplicação.\n\n");

    scanf(" %c", &verificador);
    verificador = toupper(verificador);

    switch(verificador) {

      case 'A': 

        imprimirSala(tam, sala);
        registroCompra(tam, registro, i, sala);
        printf("\n");
        i++;
        break;
    
      case 'B':

      system("clear");
      valorArrecadado(tam, registro, somatorio);
      printf("\n");
      break;

      case 'C':

        system("clear");
        quantidadeMeiasInteiras(tam, registro);
        printf("\n");
        break;

      case 'D':

        system("clear");
        disponibilidadeAssentos(tam, registro, sala);
        printf("\n");
        break;

      case 'S':

        break;  

      default:

        printf("Digite um caracter valido!\n");

    }

  }while(verificador != 'S');

  
  printf("\nSistema encerrado.");

  // Impressão do registro
  /*
  for (int i = 0; i < (tam*tam); i++) {

    printf("\n");

    printf("Nome do filme: %s\n", registro[i].nome_filme);
    printf("Id: %s\n", registro[i].id);
    printf("Categoria: %s\n", registro[i].categoria);

    printf("Entrada: %d\n", registro[i].entrada);
    printf("Assento linha: %d\nAssento Coluna: %d\n", registro[i].assento_linha,
           registro[i].assento_coluna);
    printf("Valor: R$%.2f\n", registro[i].valor);

    printf("\n");
  }
*/

  return 0;
}