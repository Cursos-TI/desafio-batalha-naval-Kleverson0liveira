#include <stdio.h>

// Desafio Batalha Naval - MateCheck

int main() {
    
    // Inicialização do tabuleiro
    int tabuleiro[10][11] = {0}; // Tabuleiro 10x10 inicializado com zeros     
    
    char letrasColuna[11] = {'#','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    for(int i = 0; i<11; i++){
        tabuleiro[i][0] = i;
    }   

    // Exemplo de inicialização de navios
    for(int i =0; i <3; i++){
        tabuleiro[i][7] = 1; // Colocando navios na primeira coluna
        tabuleiro[3][i + 4] = 1; // Colocando navios na quarta linha
    }


    
    // Exemplo de exibição do tabuleiro
    printf("Tabuleiro Inicial:\n \n");

    for(int i=0; i<=10; i++){
        printf("%c ", letrasColuna[i]);
    }
    printf("\n");
    for (int l = 0; l < 10; l++) {  
        for (int c = 0; c < 11; c++) {
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n");
    }   

    return 0;
} 