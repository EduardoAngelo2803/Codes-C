#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cont2;

typedef struct{

int codigo;
int qtdade;
float preco;

}Mercadoria;

void cadastrar(Mercadoria v_merc[], int contador) {
    
    cont2 = contador;
    char resp;
    do {
       
        printf("Digite o codigo da mercadoria: ");
        scanf("%d", &v_merc[cont2].codigo);

        printf("Digite a quantidade da mercadoria %d: ", v_merc[cont2].codigo);
        scanf("%d", &v_merc[cont2].qtdade);

        printf("Digite o preco da mercadoria %d: ", v_merc[cont2].codigo);
        scanf("%f", &v_merc[cont2].preco);
            
        printf("Deseja continuar o Cadastro? S/N: ");
        scanf(" %c", &resp);    
        printf("\n");
        resp = toupper(resp);
        cont2++;
        
    }while(resp == 'S');
}

int consultar(Mercadoria v_merc[]) {
  int consult_merc;
  
  printf("Qual o codigo da mercadoria deseja consultar? ");
  scanf("%d", &consult_merc);

  for(int i=0; i < 100;i++) {
  
      if (consult_merc == v_merc[i].codigo) {

          printf("Codigo mercadoria: %d\nQuantidade da mercadoria: %d\nPreco da mercadoria: %.2f\n\n", v_merc[i].codigo, v_merc[i].qtdade, v_merc[i].preco);
          i = 100;
          
      }else if(i == 99) {

        printf("Mercadoria nao encontrada!\n\n");
          
      }
  }
}

int valor_total(Mercadoria v_merc[], int contador) {

  float total, soma_total;
  
  for(int i  = 0; i < contador; i++) {
    
    total = v_merc[i].preco * v_merc[i].qtdade;
    soma_total = total+soma_total;
  }

  printf("O valor total de mercadorias do estoque eh de: %.2f\n\n", soma_total);

}


int main() {

   
    int opc;
    int contador = 0;
    Mercadoria v_merc[100];

  do {

  printf("||BEM-VINDO AO CONTROLE DE ESTOQUE||\nMENU\n1 - Cadastrar mercadoria \n2 - Consultar mercadoria\n3 - Valor total em mercadorias\n4 - Sair \n-> ");
  scanf("%d", &opc);

  switch(opc) {

    case 1:

    cadastrar(v_merc, contador);
    contador += cont2;
    break;
   
    case 2:

    consultar(v_merc);
    break;
     
    case 3:

    valor_total(v_merc, contador);
    break;
    
    case 4:
    
      printf("Encerrando... Obrigado por utilizar nosso sistema\n");
      break;
  }

  }while(opc != 4);
  
    return 0;
}