#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

  char nome[40];
  char codigo_produto[20];
  float preco;
  int quantidade_disponivel;
  int n_vendas;
  int n_compras;
  int status;

}Produto;

int inserir(Produto produtos[], int tamanho, int posicao, Produto novo){ //F Inserir
  
  printf("Digite o nome do produto: ");
  scanf(" %s", novo.nome);
  printf("Digite o preco do produto: ");
  scanf("%f", &novo.preco);
  printf("Digite o codigo do produto: ");
  scanf(" %s", novo.codigo_produto);
  
  
  int veriF;
  
  for(int i = 0; i < tamanho; i++) {

    if(strcmp(produtos[i].codigo_produto, novo.codigo_produto) == 0) {
        
      veriF = 1;
      break;

    }else if (strcmp(produtos[i].codigo_produto, novo.codigo_produto) != 0) {

      veriF = 0;

    }

  }
    if(posicao > 0) {
      
      if(veriF == 1) {
        
        return 0;

      }else if (veriF == 0) {

        strcpy(produtos[posicao].nome, novo.nome);
        strcpy(produtos[posicao].codigo_produto, novo.codigo_produto);
        produtos[posicao].quantidade_disponivel = 0;
        produtos[posicao].status = 1;
        produtos[posicao].preco = novo.preco;
        return 1;
      
      }

    }else if(posicao == 0) {

      strcpy(produtos[posicao].nome, novo.nome);
      strcpy(produtos[posicao].codigo_produto, novo.codigo_produto);
      produtos[posicao].quantidade_disponivel = 0;
      produtos[posicao].status = 1;
      produtos[posicao].preco = novo.preco;

      return 1;

    }
  
}

int remover(Produto produtos[], int tamanho, char codigo[40]) {   //F Remover
  
  int produto_existe = 0;
  int i = 0;
  printf("Informe o codigo do produto que deseja remover:\n");
  scanf("%s", codigo);

  for(i = 0; i < tamanho; i++) {

    if(strcmp(produtos[i].codigo_produto, codigo) == 0) {
   
      produto_existe = 1;
      break;
    }

  }

  if(produto_existe == 1) {
   
    produtos[i].status = 0;
    return 1;

  }else{

    printf("Produto não existe na base!\n");
    return 0;

  } 

}

int buscar(Produto produtos[], int tamanho, char codigo[40]) {  //F Buscar
  
  int produto_existe = 0;
  int i = 0;

  printf("Informe o codigo do produto que deseja buscar:\n");
  scanf(" %s", codigo);

  for(i = 0; i < tamanho; i++){

    if(strcmp(produtos[i].codigo_produto, codigo) == 0){

      produto_existe = 1;
      break;
      }
  }

  if(produto_existe == 1 && produtos[i].status > 0) {
    
    printf("Nome: %s\nPreco: %.2f\nQuantidade disponivel: %d\nProdutos Vendidos: %d\nProdutos comprados :%d\n", produtos[i].nome, produtos[i].preco, produtos[i].quantidade_disponivel, produtos[i].n_vendas, produtos[i].n_compras);
    
    return i;

  }else {

    printf("Produto nao existe!\n");
    return -1;
  } 
}

int comprar(Produto produtos[], int tamanho, char codigo[40]) {  //F Comprar
  
  int produto_existe = 0;
  printf("Informe o codigo do produto que deseja comprar:\n");
  scanf(" %s", codigo);

  for(int i = 0; i < tamanho; i++){

    if(strcmp(produtos[i].codigo_produto, codigo) == 0){
      
      produto_existe = 1;
      produtos[i].quantidade_disponivel += 1;
      produtos[i].n_compras += 1;
    }
  }

  if(produto_existe == 1) {

    return 1;

  }else {
    
    printf("Produto nao existe!\n");
    return 0;

  }
}

int vender(Produto produtos[], int tamanho, char codigo[40]){  //F Vender
  
  int produto_existe = 0;

  printf("Informe o codigo do produto que deseja vender:\n");
  scanf(" %s", codigo);

  for(int i = 0; i < tamanho; i++) {
    
    if(strcmp(produtos[i].codigo_produto, codigo) == 0) {
    
      if(produtos[i].quantidade_disponivel > 0) {
      
        produto_existe = 1;
        produtos[i].quantidade_disponivel -= 1;
        produtos[i].n_vendas += 1;
        break;
      }
    }
  }

  if(produto_existe == 1){
    
    return 1;

  }else {

    printf("Produto nao existe!\n");
    return 0;

  }
}

void SelectionSort(Produto produtos[], int n) {

    int maior, aux;

    for(int i = 0; i < n; i++) {

        maior = i;

        for(int j = i+1; j < n; j++) {

            if(produtos[j].n_vendas > produtos[maior].n_vendas) {

                maior = j;
          }

            if(produtos[i].n_vendas < produtos[j].n_vendas) {

            aux = produtos[i].n_vendas;
            produtos[i].n_vendas = produtos[maior].n_vendas;
            produtos[maior].n_vendas = aux;
            }
       
        }
    }
}

int main(void) {               //Programa principal
  
  Produto novo;
  int indice_busca;
  int tamanho = 1, posicao = 0, menu;
  char codigo[40];
  Produto produtos[100];
  produtos->n_compras = 0;
  produtos->n_vendas = 0;
  produtos->quantidade_disponivel = 0;
  float extrato;
  float extrato_compras, extrato_vendas;
  float saldo_inic = 0;
  float extrato_c[100];
  float extrato_v[100];
  int  j = 0, v = 0;

  do{

    printf("----------------------------\n");
    printf("||||||||||| MENU |||||||||||\n");
    printf("----------------------------");
    printf("\n1- Inserir produto\n2- Remover produto\n3- Buscar produto\n4- Comprar produto\n5- Vender Produto\n6- Sair\n");
    scanf("%i", &menu);

    switch (menu) {
      
      case 1:

        j = inserir(produtos, tamanho, posicao, novo);
        if(j == 0) {
          printf("Esse codigo ja existe, digite um codigo diferente!\n");
        }
        tamanho+=1;
        posicao = tamanho - 1;
        break;

      case 2:

        remover(produtos, tamanho, codigo);
        break;

      case 3:

        indice_busca = buscar(produtos, tamanho, codigo);
        
        break;

      case 4:

        comprar(produtos, tamanho, codigo);

        for(int i = 0; i < tamanho; i++) {

          extrato_c[i] = produtos[i].preco;
      
        }

        break;
        
      case 5:

        vender(produtos, tamanho, codigo);

        for(int i = 0; i< tamanho; i++) {

          extrato_v[i] = produtos[i].preco;

        }

        break;

      case 6:

        menu = 6;
        break;
       
    }

  }while(menu != 6);


  printf("\n--------------------------------------------\n");
  printf("||||||||||| RELATORIO DA PADARIA |||||||||||\n");
  printf("--------------------------------------------\n\n");

  printf("\n------------------------------------------------\n");
  printf("|||||||||||| PRODUTOS MAIS VENDIDOS ||||||||||||\n");
  printf("------------------------------------------------\n\n");
  
  SelectionSort(produtos, tamanho);

  for(int i=0; i < tamanho-1; i++){

    if(produtos[i].status != 0) {

      printf("Produto %s = %d vendas\n", produtos[i].nome, produtos[i].n_vendas);
    
    }
  }

 printf("\n-------------------------------------------------\n");
  printf("|||||||||||| PRODUTOS MAIS COMPRADOS ||||||||||||\n");
  printf("-------------------------------------------------\n\n");

  for(int i=0; i < tamanho-1; i++){

    if(produtos[i].status != 0)
    printf("Produto %s = %d compras\n", produtos[i].nome, produtos[i].n_compras);

  }

  for(int i=0; i < tamanho-1; i++){

    if(produtos[i].quantidade_disponivel > 0) {

      if(produtos[i].status != 0) {
     
          extrato = produtos[i].quantidade_disponivel * produtos[i].preco * -1;
          extrato_compras += extrato;
      }
    }
  }

  printf("\n------------------------------------------\n");
  printf("|||||||||||| EXTRATO DA CONTA ||||||||||||\n");
  printf("------------------------------------------\n\n");

  printf("Saldo inicial: %.2f\n\n", saldo_inic);
  
  for(int i = 0; i < tamanho-1; i++){

      int cont_compras = produtos[i].n_compras;
      int cont_vendas = produtos[i].n_vendas;

      if(produtos[i].status != 0) {

        if(extrato_c[i] > 0) {

          while(cont_compras > 0) {

            printf("Compra: -%.2f (%s)\n", extrato_c[i], produtos[i].nome);
            cont_compras--;
          }

        }

        if(extrato_v[i] > 0) {

          while(cont_vendas > 0) {

            printf("Venda: +%.2f (%s)\n", extrato_c[i], produtos[i].nome);
            cont_vendas--;
          }
        }
      
      }
  }

  printf("\nSaldo final: %.2f\n", extrato_compras);
  
  printf("\n--------------------------------\n");
  printf("|||||||||||| ESTOQUE||||||||||||\n");
  printf("--------------------------------\n\n");

  for(int i=0; i < tamanho-1; i++){

    if(produtos[i].status != 0) {

      printf("Nome: %s\nPreco: %.2f\nQuantidade disponivel: %d\nProdutos Vendidos: %d\nProdutos comprados: %d\n\n", produtos[i].nome, produtos[i].preco, produtos[i].quantidade_disponivel, produtos[i].n_vendas, produtos[i].n_compras);

    }
  }

  return 0;
}