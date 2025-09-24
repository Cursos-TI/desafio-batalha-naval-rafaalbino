#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void mostrar_tabuleiro(int tabuleiro[10][10]) {
    printf("\n\n  A B C D E F G H I J");
    for (int i = 0; i < 10; i++) {
        printf("\n%d", i);
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
    }
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    int tabuleiro[10][10];
    int navio_1[] = {3, 3, 3}, navio_2[] = {3, 3, 3};
    int coordenada_navio_1[]= {1, 2}, coordenada_navio_2[]= {7, 5};
    int posicao_correta = 0;

    // Zerar tabuleiro
    for (int i = 0, j = 0; i < 10 && j < 10; i+= (j == 9) , j= (j == 9 ? 0 : ++j)) {
        tabuleiro[i][j] = 0;
    }

    //Colocando navio 1 no tabuleiro
    for (int i = 0; i < 3; i++) {
        int coluna, linha;
        coluna = coordenada_navio_1[1];
        linha = coordenada_navio_1[0] + i;
        tabuleiro[linha][coluna] = navio_1[i];
    }

    //Colocando navio 2 no tabuleiro
    for (int i = 0; i < 3; i++) {
        int coluna, linha;
        coluna = coordenada_navio_2[1] + i;
        linha = coordenada_navio_2[0];
        tabuleiro[linha][coluna] = navio_2[i];
    }

    // Mostrar tabuleiro
    mostrar_tabuleiro(tabuleiro);

    return 0;
}
