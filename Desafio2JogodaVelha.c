#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
    
int Verificador(int m[3][3], int h) {
        
    for(int i = 0; i < 3; i++) {

        if((m[i][0] == 2) &&  (m[i][1] == 2) && (m[i][2] == 2)) {
            
            printf("Jogador 2 venceu na horizontal!\n");
                for(int i = 0; i < 3; i++) {
    
                for(int j = 0; j < 3; j++) {
    
                    printf("%d ", m[i][j]);
                }
                printf("\n");
                }
            return 10;
            break;

        }else if ((m[i][0] == 1) &&  (m[i][1] == 1) && (m[i][2] == 1)) {

            printf("Jogador 1 venceu na horizontal!\n");
                for(int i = 0; i < 3; i++) {
    
                for(int j = 0; j < 3; j++) {
    
                    printf("%d ", m[i][j]);

                    }

                printf("\n");
                }
            return 10;
            break;
        }
        }
    for(int j = 0; j < 3; j++) {
        
        if((m[0][j] == 1) &&  (m[1][j] == 1) && (m[2][j] == 1)) {
            
                printf("Jogador 1 venceu na vertical!\n");
                    for(int i = 0; i < 3; i++) {
    
                    for(int j = 0; j < 3; j++) {
    
                    printf("%d ", m[i][j]);
                    }
                    printf("\n");
                }
                return 10;
                break;
                
            }else if((m[0][j] == 2) &&  (m[1][j] == 2) && (m[2][j] == 2)) {

                printf("Jogador 2 venceu na vertical!\n");
                    for(int i = 0; i < 3; i++) {
        
                    for(int j = 0; j < 3; j++) {
        
                        printf("%d ", m[i][j]);
                    }
                    printf("\n");
                    }  
                return 10;
                break;
            }

        }

    if((m[0][0] == 1) &&  (m[1][1] == 1) && (m[2][2] == 1)) {

            printf("Jogador 1 venceu na diagonal\n");
                    for(int i = 0; i < 3; i++) {
    
                for(int j = 0; j < 3; j++) {
    
                    printf("%d ", m[i][j]);

        }
        printf("\n");
                        
        }
            return 10;
            
        }else if((m[0][0] == 2) &&  (m[1][1] == 2) && (m[2][2] == 2)) {

            printf("Jogador 2 venceu na diagonal\n");
                for(int i = 0; i < 3; i++) {
    
                for(int j = 0; j < 3; j++) {
    
                    printf("%d ", m[i][j]);

        }
        printf("\n");                       
        }   

        return 10;
        }

    if((m[0][2] == 1) &&  (m[1][1] == 1) && (m[2][0] == 1)) {

            printf("Jogador 1 venceu na diagonal\n");
                    for(int i = 0; i < 3; i++) {
    
                for(int j = 0; j < 3; j++) {
    
                    printf("%d ", m[i][j]);

        }
        printf("\n");
                        
        }
            return 10;
            
        }else if((m[0][2] == 2) &&  (m[1][1] == 2) && (m[2][0] == 2)) {

            printf("Jogador 2 venceu na diagonal\n");
                for(int i = 0; i < 3; i++) {
    
                for(int j = 0; j < 3; j++) {
    
                    printf("%d ", m[i][j]);

        }
        printf("\n");
                        
        }   

        return 10;
        }


    for(int i = 0; i < 3; i++) {

        for(int j = 0; j < 3; j++) {

            printf("%d ", m[i][j]);

        }
        printf("\n");

    }

    return h;

}

void JogodaVelha(int jogoVelha[3][3]) {

    for(int i = 0; i < 3; i++) {

        for(int j = 0; j < 3; j++) {

            jogoVelha[i][j] = 0 ;

        }
    }

    int i = 0;
    int l;
    int m = 0;
    
    while(i < 5) {

        while(m < 1) {

            printf("Voce eh o jogador 1. Digite sua posicao, de 1 ate 9: ");
            scanf("%d", &l);


            switch(l) {
            
            case 1: 
            
                if(jogoVelha[0][0] ==  0) {

                    jogoVelha[0][0] = 1;
                    

                }else {

                    printf("Local invalido, tente novamente! \n");

                }
                break;

            case 2:

                if(jogoVelha[0][1] ==  0) {

                        jogoVelha[0][1] = 1;
                        

                    }else {

                        printf("Local invalido, tente novamente! \n");

                    }
                break;
            case 3:

                if(jogoVelha[0][2] ==  0) {

                        jogoVelha[0][2] = 1;
                        

                    }else {

                        printf("Local invdálido, tente novamente! \n");

                    }
                break;
            case 4:

                if(jogoVelha[1][0] ==  0) {

                        jogoVelha[1][0] = 1;
                        

                    }else {

                        printf("Local invalido, tente novamente! \n");

                    }
                break;

            case 5:

                if(jogoVelha[1][1] ==  0) {

                        jogoVelha[1][1] = 1;
                        

                    }else {

                        printf("Local invdálido, tente novamente! \n");

                    }
                break;
            case 6: 

                if(jogoVelha[1][2] ==  0) {

                        jogoVelha[1][2] = 1;
                        

                    }else {

                        printf("Local invdálido, tente novamente! \n");

                    }
                break;
            case 7:

                if(jogoVelha[2][0] ==  0) {

                        jogoVelha[2][0] = 1;
                        

                    }else {

                        printf("Local invalido, tente novamente! \n");

                    }
                break;
            case 8:

                if(jogoVelha[2][1] ==  0) {

                        jogoVelha[2][1] = 1;
                        

                    }else {

                        printf("Local invalido, tente novamente! \n");

                    }
                break;
            case 9:
            
                if(jogoVelha[2][2] ==  0) {

                        jogoVelha[2][2] = 1;
                        

                    }else {

                        printf("Local invalido, tente novamente! \n");

                    }
                break;
            

            default:

                printf("Digite um valor valido!\n");

            }

            if(l >= 1 && l <=9) {
                break;
            }
        }

        i = Verificador(jogoVelha, i);

        if(i < 5 && i != 4) {
            while(m < 1) {

                printf("Voce eh o jogador 2. Digite sua posicao, de 1 ate 9: ");
                scanf("%d", &l);

                switch(l) {
                
                case 1: 
                
                    if(jogoVelha[0][0] ==  0) {

                        jogoVelha[0][0] = 2;
                    

                    }else {

                        printf("Local invdálido, tente novamente! \n");

                    }
                    break;
                case 2:

                    if(jogoVelha[0][1] ==  0) {

                            jogoVelha[0][1] = 2;
                    

                        }else {

                            printf("Local invalido, tente novamente! \n");

                        }
                    break;
                case 3:

                    if(jogoVelha[0][2] ==  0) {

                            jogoVelha[0][2] = 2;
                        

                        }else {

                            printf("Local invdálido, tente novamente! \n");

                        }
                    break;
                case 4:

                    if(jogoVelha[1][0] ==  0) {

                            jogoVelha[1][0] = 2;
                        

                        }else {

                            printf("Local invdálido, tente novamente! \n");

                        }
                    break;
                case 5:

                    if(jogoVelha[1][1] ==  0) {

                            jogoVelha[1][1] = 2;
                        

                        }else {

                            printf("Local invalido, tente novamente! \n");

                        }
                    break;
                case 6:

                    if(jogoVelha[1][2] ==  0) {

                            jogoVelha[1][2] = 2;
                        

                        }else {

                            printf("Local invdálido, tente novamente! \n");

                        }
                    break;
                case 7:

                    if(jogoVelha[2][0] ==  0) {

                            jogoVelha[2][0] = 2;
                        

                        }else {

                            printf("Local invdálido, tente novamente! \n");

                        }
                    break;
                case 8:

                    if(jogoVelha[2][1] ==  0) {

                            jogoVelha[2][1] = 2;
                        

                        }else {

                            printf("Local invalido, tente novamente! \n");

                        }
                    break;
                case 9:
                
                    if(jogoVelha[2][2] ==  0) {

                            jogoVelha[2][2] = 2;
                        

                        }else {

                            printf("Local invalido, tente novamente! \n");

                        }
                    break;   

                default:

                    printf("Digite um valor valido!\n"); 
                
                }

                if(l >= 1 && l <= 9) {
                  break;
            }
               
            }
            
        }

        if(i != 10) {

            i = Verificador(jogoVelha, i);
        }

        i++;
    
    }
    
    if(i == 5) {

        printf("Empate!\n");

    }


    }
        
void printMatriz(int m[3][3]) {

    int cont = 1;
    for(int i = 0; i < 3; i++) {

        for(int j = 0; j < 3; j++) {

            m[i][j] = cont;
            cont++;
        }

    }

    for(int i = 0; i < 3; i++) {

        for(int j = 0; j < 3; j++) {

            printf("%d ", m[i][j]);
        }
    printf("\n");
    }
}

int main () {

        int Jogo[3][3];
        int jogo2[3][3];

        printf("|||||||||||||||||||||||||||\n");
        printf("Bem-vindo ao Jogo da velha!\n");
        printf("|||||||||||||||||||||||||||\n\n");

        printf("Use a imagem abaixo para se basear no jogo!\n");

        printMatriz(jogo2);
        printf("\n");
        JogodaVelha(Jogo);

       return 0;
    }