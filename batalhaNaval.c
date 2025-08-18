#include <stdio.h>
#include <stdlib.h>

#define COLUNAS 10
#define LINHAS 10
#define NAVIO 3
#define AGUA 0


// Função para exibir o tabuleiro

void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    printf("  ");
    for (char c = 'A'; c <= 'J'; c++) {
        printf("%c ", c);
    }
    printf("\n");

    for (int l = 0; l < LINHAS; l++) {
        printf("%d ", l);
        for (int c = 0; c < COLUNAS; c++) {
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n");
    }
}


// Função para posicionar um navio com validações

void posicionarNavio(int tabuleiro[LINHAS][COLUNAS], int l_inicio, int c_inicio, int l_fim, int c_fim) {
    int i;
    int tamanho = 0;
    
    // Calcula os pontos min/max para garantir que o loop funcione
    int l_min = (l_inicio < l_fim) ? l_inicio : l_fim;
    int l_max = (l_inicio > l_fim) ? l_inicio : l_fim;
    int c_min = (c_inicio < c_fim) ? c_inicio : c_fim;
    int c_max = (c_inicio > c_fim) ? c_inicio : c_fim;
    
    // Determina a orientação e o tamanho
    if (l_inicio == l_fim) {
        tamanho = c_max - c_min + 1;
    } else if (c_inicio == c_fim) {
        tamanho = l_max - l_min + 1;
    } else if ((l_max - l_min) == (c_max - c_min)) {
        tamanho = l_max - l_min + 1;
    }else if(tamanho != 3 ){
        printf("Erro: Tamanho do navio deve ser 3. Posicionamento cancelado.\n");
        exit(1);
    } 
    else {
        printf("Erro: Navio nao alinhado. Posicionamento cancelado.\n");
        exit(1);
    }
    
    // Validação de Limites e Sobreposição
    for (i = l_min; i <= l_max; i++) {
        for (int j = c_min; j <= c_max; j++) {
            // Verifica a posição apenas se ela estiver no caminho do navio
            if ((l_inicio == l_fim && i == l_inicio) || 
                (c_inicio == c_fim && j == c_inicio) || 
                ((i - l_inicio) == (j - c_inicio)) || 
                ((i - l_inicio) == -(j - c_inicio))) { 
                
                if (i < 0 || i >= LINHAS || j < 0 || j >= COLUNAS) {
                    printf("Erro: Navio fora dos limites do tabuleiro em (%d, %d). Posicionamento cancelado.\n", i, j);
                    exit(1);
                }
                if (tabuleiro[i][j] == NAVIO) {
                    printf("Erro: Sobreposicao detectada em (%d, %d). Posicionamento cancelado.\n", i, j);
                    exit(1);
                }
            }
        }
    }
    
    // Se a validação passou, posiciona o navio
    for (i = l_min; i <= l_max; i++) {
        for (int j = c_min; j <= c_max; j++) {
            if ((l_inicio == l_fim && i == l_inicio) ||
                (c_inicio == c_fim && j == c_inicio) ||
                ((i - l_inicio) == (j - c_inicio)) ||
                ((i - l_inicio) == -(j - c_inicio))) {
                
                tabuleiro[i][j] = NAVIO;
            }
        }
    }
}

int main() {
    int tabuleiro[LINHAS][COLUNAS] = {0};


    posicionarNavio(tabuleiro, 4, 2, 4, 4); 
    posicionarNavio(tabuleiro, 6, 8, 8, 8); 
    posicionarNavio(tabuleiro, 1, 1, 3, 3); 
    posicionarNavio(tabuleiro, 5, 7, 7, 5); 
    
    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;

}