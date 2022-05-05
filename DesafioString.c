#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main () {

    char Palavra[20];
    char Tentativa[20];
    int cont = 0;
    char LetraTentada[20];
    int tamanho;
    int acertos;
  
    printf("Digite a palavra a ser advinhada: ");
    fgets(Palavra, 20, stdin);
    
    //Apagar a tela depois que a palavra foi escrita
    system("cls");
    //Setando que a ultima letra da palavra eh uma quebra de linha
    Palavra[strlen(Palavra) - 1] = '\0';

    for(int j = 0; j < strlen(Palavra); j++) {

        Tentativa[j] = '_';
        tamanho = strlen(Palavra);
        acertos = tamanho;
    }
    for(int i = 0; i < tamanho; i++) {

        Palavra[i] = tolower(Palavra[i]);

    }
    while(cont < tamanho) {
        for(int i = 0; i < tamanho; i++) {
        printf("%c ", Tentativa[i]);
        }
        printf("\n\n");
        printf("Digite uma letra 'Apenas minusculas': ");
        
        scanf("%c", LetraTentada);
        getchar();
        printf("\n");
        for(int j = 0; j < tamanho; j++) {
        if(LetraTentada[0] == Palavra[j]) {

            Tentativa[j] = Palavra[j];
            
            }
        }
       cont++; 
        
        if(strncmp(Tentativa, Palavra, tamanho) != 0) {
       printf("Voce possui %d tentativas!\n\n" , acertos-1);
       acertos--;
        }

        if(acertos == 0) {

            printf("Voce perdeu!\n");
        }

       if(strncmp(Tentativa, Palavra, tamanho) == 0) {
           printf("%s\n", Palavra);
           printf("Voce ganhou, parabens!");
           break;
       }
    }

    return 0;
}