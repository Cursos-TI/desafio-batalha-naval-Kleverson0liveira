#include <stdio.h>

// Desafio Batalha Naval - MateCheck

int main() {
    
    // Inicialização do tabuleiro
    int tabuleiro[10][10] = {0}; // Tabuleiro 10x10 inicializado com zeros      

    // Exemplo de inicialização de navios
    for(int i =0; i <3; i++){
        tabuleiro[i][0] = 1; // Colocando navios na primeira coluna
        tabuleiro[3][i + 2] = 1; // Colocando navios na quarta linha
    }

    // Exemplo de exibição do tabuleiro
    printf("Tabuleiro Inicial:\n");
    for (int l = 0; l < 10; l++) {  
        for (int c = 0; c < 10; c++) {
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n");
    }   

    return 0;
}
