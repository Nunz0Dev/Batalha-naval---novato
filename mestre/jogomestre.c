#include <stdio.h>

//Tabuleiro//

//loop externo = linhas
//loop interno = colunas



#define LINHAS 10
#define COLUNAS 10

//Poderes//

//cruz

//loop externo = linhas
//loop interno = colunas

#define LINHASCR 5
#define COLUNASCR 5

// cone

//loop externo = linhas
//loop interno = colunas

#define LINHASCO 5
#define COLUNACO 5


// octaedro

//loop externo = linhas
//loop interno = colunas

#define LINHAOC 5
#define COLUNAOC 5
 
int main(){


    // tabuleiro do jogo

    int tabuleiro [LINHAS][COLUNAS];

    //inicialização

    for (int i = 0; i < LINHAS; i++){
        for (int j = 0; j < COLUNAS; j++){
        (tabuleiro[i][j] = 0);

        }
    }

// coordenadas

int linhaH = 2, colunaH = 3; //Horizontal // Primeiro navio
int linhaV = 5, colunaV = 7; //Vertical // Segundo navio
int linha1 = 4, coluna1 = 4; // Diagonal descendo para direita // Terceiro navio
int linha2 = 9, coluna2 = 0; // Diagonal subindo para direita // Quarto navio
int linhacentrocruz = 5, colunacentrocruz = 5; // centro do tabuleiro da cruz
int linhacentrocone = 2, colunacentrocone = 7; // centro do tabuleiro do cone
int linhacentrooctaedro = 7, colunacentrooctaedro = 2;
int linhatabuleiro, colunatabuleiro;

// 1° Navio na horizontal

for (int i = 0; i < 3; i++) {
    tabuleiro[linhaH][colunaH + i] = 3;
}

// 2° Navio na vertical

for (int i = 0; i < 3; i++) {
    tabuleiro[linhaV + i][colunaV] = 3;
}

// 3° Navio 

for (int i = 0; i < 3; i++) {
    tabuleiro[linha1 + i][coluna1 + i] = 3;
}

// 4° Navio

for (int i = 0; i < 3; i++) {
    tabuleiro[linha2 - i][coluna2 + i] = 3;
}

//////////////////////////////////////////////////////////////////////

//poderes

int cruz [LINHASCR][COLUNASCR];

//inicialização do poderes da cruz

for (int i = 0; i < LINHASCR; i++){
    for (int j = 0; j < COLUNASCR; j++){
    
if (i == 2 || j == 2){
    cruz[i][j] = 1;
    
} else {
    cruz[i][j] = 0;

       }
   }
}

//1. cruz

for (int i = 0; i < LINHASCR; i++) {
    for (int j = 0; j < COLUNASCR; j++) {

    linhatabuleiro = linhacentrocruz + (i - 2);
    colunatabuleiro = colunacentrocruz + (j - 2);
    
    if(linhatabuleiro >= 0 && linhatabuleiro < LINHAS &&
       colunatabuleiro >= 0 && colunatabuleiro < COLUNAS) {

             if (cruz[i][j] == 1 && 
             tabuleiro[linhatabuleiro][colunatabuleiro] == 0) {

             tabuleiro[linhatabuleiro][colunatabuleiro] = 5;

           }
        }
    }
}

//2. cone

int cone[LINHASCO][COLUNACO];

for (int i = 0; i < LINHASCO; i++) {
    for(int j = 0; j < COLUNACO; j++) {

    linhatabuleiro = linhacentrocone + (i- 2);
    colunatabuleiro = colunacentrocone + (j - 2);
    
    if (i <= 2 && j >= 2 - i && j <= 2 + i) {
        cone[i][j] = 1;
    } else {
        cone[i][j] = 0;
    }

    if (linhatabuleiro >= 0 && linhatabuleiro < LINHAS &&
       colunatabuleiro >= 0 && colunatabuleiro  < COLUNAS) {

       if (cone[i][j] == 1 &&
          tabuleiro[linhatabuleiro][colunatabuleiro] == 0) {

          tabuleiro[linhatabuleiro][colunatabuleiro] = 5;

         }
      }
   }
}

//3. octaedro

int octaedro[LINHAOC][COLUNAOC];

for (int i = 0; i < LINHAOC; i++){
    for(int j = 0; j < COLUNAOC; j++) {

        linhatabuleiro = linhacentrooctaedro + (i - 2);
        colunatabuleiro = colunacentrooctaedro + (j - 2);

        int distanciaLinha;
        int distanciaColuna;

        if (i > 2){
            distanciaLinha = i - 2;
        } else {
            distanciaLinha = 2 - i;
        }

        if (j > 2){
            distanciaColuna = j - 2;
        } else {
            distanciaColuna = 2 - j;    
        }

        if (distanciaLinha + distanciaColuna <= 2){
            octaedro[i][j] = 1;
        } else {
            octaedro[i][j] = 0;
        }

        if (linhatabuleiro >= 0 && linhatabuleiro < LINHAS &&
            colunatabuleiro >= 0 && colunatabuleiro < COLUNAS ) {

            if (octaedro[i][j] == 1 && 
                tabuleiro[linhatabuleiro][colunatabuleiro] == 0) {

                tabuleiro[linhatabuleiro][colunatabuleiro] = 5;
           }
        }
     }
  }

//////////////////////////////////////////////////////////////////////

// Mostra o tabuleiro do jogo

printf("=== BATALHA NAVAL ===\n\n");

for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
        
    if (tabuleiro[i][j] == 0) {
        printf("~ ");
    } else if (tabuleiro[i][j] == 3) {
        printf("N ");
    } else if (tabuleiro[i][j] == 5) {
        printf("* ");
    }

  }
     printf("\n");
}

    return 0;
     
}




