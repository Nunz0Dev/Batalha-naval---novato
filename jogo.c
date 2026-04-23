#include <stdio.h>

int main(){

int tabuleiro [10][10];
int i, j;

// inicializa com água que é representada por (0)

for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++ ) {
        tabuleiro[i][j] = 0;

    }

}

// Coordenadas 

int linhaH = 2, colunaH = 3; //horizontal
int linhaV = 5, colunaV = 7; // vertical

// Navio na horizontal

for (i = 0; i < 3; i++) {
    tabuleiro[linhaH][colunaH + i] = 3;
}

// Navio na vertical

for (i = 0; i < 3; i++) {
    tabuleiro[linhaV + i][colunaV] = 3;
}

// Mostra o tabuleiro do jogo

printf("=== BATALHA NAVAL ===\n\n");

for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
        
    if (tabuleiro[i][j] == 0)
        printf("~ ");
    else
        printf("N ");

    }
    printf("\n");

 }

    return 0;
}