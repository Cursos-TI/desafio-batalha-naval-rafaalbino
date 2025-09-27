#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int navio_1[] = {3, 3, 3}, navio_2[] = {3, 3, 3}, navio_3[] = {3, 3, 3}, navio_4[] = {3, 3, 3};
    int coordenada_navio_1[2], coordenada_navio_2[2], coordenada_navio_3[2], coordenada_navio_4[2];
    int posicao_correta = 0;
    int posicao_habilidade[2] = {0, 0};
    int habilidade_cone[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };
    int habilidade_cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };
    int habilidade_octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    srand(time(NULL)); //para jogar as habilidades em lugares aleatorios

    // Zerar tabuleiro
    for (int i = 0, j = 0; i < 10 && j < 10; i+= (j == 9) , j= (j == 9 ? 0 : ++j)) {
        tabuleiro[i][j] = 0;
    }

    // Mostrar tabuleiro para visualização antes de posicionar
    mostrar_tabuleiro(tabuleiro);
    
    // Recebendo posição dos navios
    // Navio 1
    printf("\n\nSelecione a posição do primeiro navio (3 casas, vertical, cima para baixo):");
    while (1) {
        char coluna;
        printf("\nColuna: ");
        scanf(" %c", &coluna);

        // caso esteja em minusculo trocar para maiusculo
        if (coluna >= 'a' && coluna <= 'j') {
                coluna -= 32; 
            }
            
        if (coluna < 'A' || coluna > 'J') {
            printf("\nColuna Inválida!");
            continue;
        }
        coordenada_navio_1[1] = (int) coluna - 65;
        break;
    }
    while (1) {
        int linha;
        printf("\nLinha: ");
        scanf(" %d", &linha);
        if (linha < 0 || linha > 7) {
            printf("\nLinha Inválida!");
            continue;
        }
        coordenada_navio_1[0] = linha;
        break;
    }

    //Colocando navio 1 no tabuleiro
    for (int i = 0; i < 3; i++) {
        int coluna, linha;
        coluna = coordenada_navio_1[1];
        linha = coordenada_navio_1[0] + i;
        tabuleiro[linha][coluna] = navio_1[i];
    }
    
    // Mostrar tabuleiro
    mostrar_tabuleiro(tabuleiro);

    // Navio 2
    while (!posicao_correta) {
        printf("\n\nSelecione a posição do segundo navio (3 casas, horizontal, esquerda para direita):");
        while (1) {
            char coluna;
            printf("\nColuna: ");
            scanf(" %c", &coluna);

            // caso esteja em minusculo trocar para maiusculo
            if (coluna >= 'a' && coluna <= 'j') {
                    coluna -= 32; 
                }
            
            if (coluna < 'A' || coluna > 'H') {
                printf("\nColuna Inválida!");
                continue;
            }
            coordenada_navio_2[1] = (int) coluna - 65;
            break;
        }
        while (1) {
            int linha;
            printf("\nLinha: ");
            scanf(" %d", &linha);
            if (linha < 0 || linha > 9) {
                printf("\nLinha Inválida!");
                continue;
            }
            coordenada_navio_2[0] = linha;
            break;
        }

        // verificar se chocou com outro navio
        posicao_correta = 1;
        for (int i = 0; i < 3; i++) {
            int coluna, linha;
            coluna = coordenada_navio_2[1] + i;
            linha = coordenada_navio_2[0];
            if (tabuleiro[linha][coluna] == 3){
                printf("\nPosição Inválida! o navio não pode chocar com outro");
                posicao_correta = 0;
            };
        }
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

    // Navio 3
    posicao_correta = 0; //reiniciando a variavel
    while (!posicao_correta) {
        printf("\n\nSelecione a posição do terceiro navio (3 casas, diagonal, esquerda p/ direita, cima p/ baixo):");
        while (1) {
            char coluna;
            printf("\nColuna: ");
            scanf(" %c", &coluna);

            // caso esteja em minusculo trocar para maiusculo
            if (coluna >= 'a' && coluna <= 'j') {
                    coluna -= 32; 
                }
            
            if (coluna < 'A' || coluna > 'H') {
                printf("\nColuna Inválida!");
                continue;
            }
            coordenada_navio_3[1] = (int) coluna - 65;
            break;
        }
        while (1) {
            int linha;
            printf("\nLinha: ");
            scanf(" %d", &linha);
            if (linha < 0 || linha > 7) {
                printf("\nLinha Inválida!");
                continue;
            }
            coordenada_navio_3[0] = linha;
            break;
        }

        // verificar se chocou com outro navio
        posicao_correta = 1;
        for (int i = 0; i < 3; i++) {
            int coluna, linha;
            coluna = coordenada_navio_3[1] + i;
            linha = coordenada_navio_3[0] + i;
            if (tabuleiro[linha][coluna] == 3){
                printf("\nPosição Inválida! o navio não pode chocar com outro");
                posicao_correta = 0;
            };
        }
    }

    //Colocando navio 3 no tabuleiro
    for (int i = 0; i < 3; i++) {
        int coluna, linha;
        coluna = coordenada_navio_3[1] + i;
        linha = coordenada_navio_3[0] + i;
        tabuleiro[linha][coluna] = navio_3[i];
    }

    // Mostrar tabuleiro
    mostrar_tabuleiro(tabuleiro);

    // Navio 4
    posicao_correta = 0; //reiniciando a variavel
    while (!posicao_correta) {
        printf("\n\nSelecione a posição do quarto navio (3 casas, diagonal, direita p/ esquerda, cima p/ baixo):");
        while (1) {
            char coluna;
            printf("\nColuna: ");
            scanf(" %c", &coluna);

            // caso esteja em minusculo trocar para maiusculo
            if (coluna >= 'a' && coluna <= 'j') {
                    coluna -= 32; 
                }
            
            if (coluna < 'C' || coluna > 'J') {
                printf("\nColuna Inválida!");
                continue;
            }
            coordenada_navio_4[1] = (int) coluna - 65;
            break;
        }
        while (1) {
            int linha;
            printf("\nLinha: ");
            scanf(" %d", &linha);
            if (linha < 0 || linha > 7) {
                printf("\nLinha Inválida!");
                continue;
            }
            coordenada_navio_4[0] = linha;
            break;
        }

        // verificar se chocou com outro navio
        posicao_correta = 1;
        for (int i = 0; i < 3; i++) {
            int coluna, linha;
            coluna = coordenada_navio_4[1] - i;
            linha = coordenada_navio_4[0] + i;
            if (tabuleiro[linha][coluna] == 3){
                printf("\nPosição Inválida! o navio não pode chocar com outro");
                posicao_correta = 0;
            };
        }
    }

    //Colocando navio 4 no tabuleiro
    for (int i = 0; i < 3; i++) {
        int coluna, linha;
        coluna = coordenada_navio_4[1] - i;
        linha = coordenada_navio_4[0] + i;
        tabuleiro[linha][coluna] = navio_4[i];
    }

    // Mostrar tabuleiro
    mostrar_tabuleiro(tabuleiro);

    printf("\n\nDisparando habilidades...\n");

    // Jogando habilidade de cone
    posicao_habilidade[0] = rand() % 10;
    posicao_habilidade[1] = rand() % 10;

    printf("\nDisparando Habilidade em cone em: %c%d",posicao_habilidade[1] + 65, posicao_habilidade[0]);

    for (int i = -2; i < 3; i++) {
        for (int j = -2; j < 3; j++) {
            if (habilidade_cone[i+2][j+2] == 0) continue;
            if ((posicao_habilidade[0] + i) < 0 || (posicao_habilidade[0] + i) > 9) continue;
            if ((posicao_habilidade[1] + j) < 0 || (posicao_habilidade[1] + j) > 9) continue;
            tabuleiro[posicao_habilidade[0] + i][posicao_habilidade[1] + j] = habilidade_cone[i+2][j+2];
        }
    }

    // Jogando habilidade de cruz
    posicao_habilidade[0] = rand() % 10;
    posicao_habilidade[1] = rand() % 10;

    printf("\nDisparando Habilidade em cruz em: %c%d",posicao_habilidade[1] + 65, posicao_habilidade[0]);

    for (int i = -2; i < 3; i++) {
        for (int j = -2; j < 3; j++) {
            if (habilidade_cruz[i+2][j+2] == 0) continue;
            if ((posicao_habilidade[0] + i) < 0 || (posicao_habilidade[0] + i) > 9) continue;
            if ((posicao_habilidade[1] + j) < 0 || (posicao_habilidade[1] + j) > 9) continue;
            tabuleiro[posicao_habilidade[0] + i][posicao_habilidade[1] + j] = habilidade_cruz[i+2][j+2];
        }
    }

    // Jogando habilidade de octaedro
    posicao_habilidade[0] = rand() % 10;
    posicao_habilidade[1] = rand() % 10;

    printf("\nDisparando Habilidade em octaedro em: %c%d",posicao_habilidade[1] + 65, posicao_habilidade[0]);

    for (int i = -2; i < 3; i++) {
        for (int j = -2; j < 3; j++) {
            if (habilidade_octaedro[i+2][j+2] == 0) continue;
            if ((posicao_habilidade[0] + i) < 0 || (posicao_habilidade[0] + i) > 9) continue;
            if ((posicao_habilidade[1] + j) < 0 || (posicao_habilidade[1] + j) > 9) continue;
            tabuleiro[posicao_habilidade[0] + i][posicao_habilidade[1] + j] = habilidade_octaedro[i+2][j+2];
        }
    }

    // Mostrar tabuleiro
    mostrar_tabuleiro(tabuleiro);

    return 0;
}
