#include <stdio.h>

// Definição do tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0)
                printf(" 0 ");  // Água
            else if (tabuleiro[i][j] == 3)
                printf(" 3 ");  // Navio
            else if (tabuleiro[i][j] == 5)
                printf(" 5 ");  // Área afetada pela habilidade
        }
        printf("\n");
    }
}

// Função para aplicar a habilidade Cone
void aplicarHabilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemX, int origemY) {
    // Matriz de habilidade Cone 5x5
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplicar a habilidade no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int x = origemX - 2 + i;  // Ajusta a posição no tabuleiro
            int y = origemY - 2 + j;  // Ajusta a posição no tabuleiro
            if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO && cone[i][j] == 1) {
                tabuleiro[x][y] = 5;  // Marca a área afetada
            }
        }
    }
}

// Função para aplicar a habilidade Cruz
void aplicarHabilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemX, int origemY) {
    // Matriz de habilidade Cruz 5x5
    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplicar a habilidade no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int x = origemX - 2 + i;  // Ajusta a posição no tabuleiro
            int y = origemY - 2 + j;  // Ajusta a posição no tabuleiro
            if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO && cruz[i][j] == 1) {
                tabuleiro[x][y] = 5;  // Marca a área afetada
            }
        }
    }
}

// Função para aplicar a habilidade Octaedro
void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemX, int origemY) {
    // Matriz de habilidade Octaedro 5x5
    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplicar a habilidade no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int x = origemX - 2 + i;  // Ajusta a posição no tabuleiro
            int y = origemY - 2 + j;  // Ajusta a posição no tabuleiro
            if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO && octaedro[i][j] == 1) {
                tabuleiro[x][y] = 5;  // Marca a área afetada
            }
        }
    }
}

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Definindo navios no tabuleiro (exemplo)
    tabuleiro[2][2] = 3;
    tabuleiro[4][4] = 3;
    tabuleiro[6][6] = 3;

    // Ponto de origem das habilidades (exemplo)
    int origemX = 4, origemY = 4;

    // Aplicar habilidades no tabuleiro
    aplicarHabilidadeCone(tabuleiro, origemX, origemY);
    aplicarHabilidadeCruz(tabuleiro, origemX, origemY);
    aplicarHabilidadeOctaedro(tabuleiro, origemX, origemY);

    // Exibir o tabuleiro após aplicar as habilidades
    exibirTabuleiro(tabuleiro);

    return 0;
}
