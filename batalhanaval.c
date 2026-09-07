#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define NAVIO 3
#define AGUA 0
#define BOMBA 5
#define ACERTO -1
#define TAM_HABILIDADE 5

int main() {

    int tabuleiro[LINHAS][COLUNAS] = {0};
    int posicaoValida;
    int posicaoValida2;

    char colunas[COLUNAS] =
        {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int linha;
    int coluna;

    printf("\n\tBEM-VINDO AO JOGO BATALHA NAVAL!\n\n");

    printf("\t   ");

    for (coluna = 0; coluna < COLUNAS; coluna++) {
        printf("%c ", colunas[coluna]);
    }

    printf("\n");

    for (linha = 0; linha < LINHAS; linha++) {

        printf("\t%2d ", linha + 1);

        for (coluna = 0; coluna < COLUNAS; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }

        printf("\n");
    }

    char colunaNavio;
    int linhaNavio;

    printf("\nPrimeiro navio - HORIZONTAL - 3 casas\n");

    do {

        printf("Digite a posicao inicial (exemplo: B1): ");
        scanf(" %c%d", &colunaNavio, &linhaNavio);

        int posicaoValida = 1;

        if (linhaNavio < 1 || linhaNavio > LINHAS) {
            posicaoValida = 0;
        }

        if (colunaNavio < 'A' || colunaNavio > 'J') {
            posicaoValida = 0;
        }

        if (colunaNavio > 'H') {
            posicaoValida = 0;
        }

        if (posicaoValida == 1) {

            int linhaMatriz = linhaNavio - 1;
            int colunaMatriz = colunaNavio - 'A';

            if (tabuleiro[linhaMatriz][colunaMatriz] != AGUA ||
                tabuleiro[linhaMatriz][colunaMatriz + 1] != AGUA ||
                tabuleiro[linhaMatriz][colunaMatriz + 2] != AGUA) {

                posicaoValida = 0;

                printf("Erro: uma ou mais casas ja estao ocupadas.\n");
            }
        }

        if (posicaoValida == 0) {
            printf("Posicao invalida. Tente novamente.\n");
        }

    } while (posicaoValida == 0);

    int linhaMatriz = linhaNavio - 1;
    int colunaMatriz = colunaNavio - 'A';

    tabuleiro[linhaMatriz][colunaMatriz] = NAVIO;
    tabuleiro[linhaMatriz][colunaMatriz + 1] = NAVIO;
    tabuleiro[linhaMatriz][colunaMatriz + 2] = NAVIO;

    printf("Navio colocado com sucesso!\n");

    char colunaNavio2;
    int linhaNavio2;

    printf("\nSegundo navio - VERTICAL - 3 casas\n");

    do {

        printf("Digite a posicao inicial (exemplo: B3): ");
        scanf(" %c%d", &colunaNavio2, &linhaNavio2);

        int posicaoValida2 = 1;

        if (linhaNavio2 < 1 || linhaNavio2 > LINHAS) {
            posicaoValida2 = 0;
        }

        if (colunaNavio2 < 'A' || colunaNavio2 > 'J') {
            posicaoValida2 = 0;
        }

        if (linhaNavio2 > 8) {
            posicaoValida2 = 0;
        }

        if (posicaoValida2 == 1) {

            int linhaMatriz2 = linhaNavio2 - 1;
            int colunaMatriz2 = colunaNavio2 - 'A';

            if (tabuleiro[linhaMatriz2][colunaMatriz2] != AGUA ||
                tabuleiro[linhaMatriz2 + 1][colunaMatriz2] != AGUA ||
                tabuleiro[linhaMatriz2 + 2][colunaMatriz2] != AGUA) {

                posicaoValida2 = 0;

                printf("Erro: uma ou mais casas ja estao ocupadas.\n");
            }
        }

        if (posicaoValida2 == 0) {
            printf("Posicao invalida. Tente novamente.\n");
        }

    } while (posicaoValida2 == 0);

    int linhaMatriz2 = linhaNavio2 - 1;
    int colunaMatriz2 = colunaNavio2 - 'A';

    tabuleiro[linhaMatriz2][colunaMatriz2] = NAVIO;
    tabuleiro[linhaMatriz2 + 1][colunaMatriz2] = NAVIO;
    tabuleiro[linhaMatriz2 + 2][colunaMatriz2] = NAVIO;

    printf("Navio colocado com sucesso!\n");

    printf("\n\tTABULEIRO APOS COLOCAR OS NAVIOS\n\n");

    printf("\t   ");

    for (coluna = 0; coluna < COLUNAS; coluna++) {
        printf("%c ", colunas[coluna]);
    }

    printf("\n");

    for (linha = 0; linha < LINHAS; linha++) {

        printf("\t%2d ", linha + 1);

        for (coluna = 0; coluna < COLUNAS; coluna++) {

            printf("%d ", tabuleiro[linha][coluna]);

        }

        printf("\n");
    }

    for (linha = 3, coluna = 4;
         linha <= 5 && coluna <= 6;
         linha++, coluna++) {

        tabuleiro[linha][coluna] = NAVIO;
    }

    for (linha = 8, coluna = 0;
         linha >= 6 && coluna <= 2;
         linha--, coluna++) {

        tabuleiro[linha][coluna] = NAVIO;
    }

    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    for (linha = 0; linha < TAM_HABILIDADE; linha++) {

        for (coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            if (coluna >= TAM_HABILIDADE / 2 - linha &&
                coluna <= TAM_HABILIDADE / 2 + linha) {

                cone[linha][coluna] = 1;

            } else {

                cone[linha][coluna] = 0;
            }
        }
    }

    for (linha = 0; linha < TAM_HABILIDADE; linha++) {

        for (coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            if (linha == TAM_HABILIDADE / 2 ||
                coluna == TAM_HABILIDADE / 2) {

                cruz[linha][coluna] = 1;

            } else {

                cruz[linha][coluna] = 0;
            }
        }
    }

    for (linha = 0; linha < TAM_HABILIDADE; linha++) {

        for (coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            if (linha + coluna >= TAM_HABILIDADE / 2 &&
                linha + coluna < TAM_HABILIDADE + TAM_HABILIDADE / 2 &&
                linha - coluna <= TAM_HABILIDADE / 2 &&
                coluna - linha <= TAM_HABILIDADE / 2) {

                octaedro[linha][coluna] = 1;

            } else {

                octaedro[linha][coluna] = 0;
            }
        }
    }

    int origemConeLinha = 2;
    int origemConeColuna = 2;

    int origemCruzLinha = 8;
    int origemCruzColuna = 1;

    int origemOctaedroLinha = 7;
    int origemOctaedroColuna = 7;

    for (linha = 0; linha < TAM_HABILIDADE; linha++) {

        for (coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            if (cone[linha][coluna] == 1) {

                int x = origemConeLinha +
                        linha -
                        TAM_HABILIDADE / 2;

                int y = origemConeColuna +
                        coluna -
                        TAM_HABILIDADE / 2;

                if (x >= 0 && x < LINHAS &&
                    y >= 0 && y < COLUNAS) {

                    if (tabuleiro[x][y] == NAVIO) {

                        tabuleiro[x][y] = ACERTO;

                    } else if (tabuleiro[x][y] == AGUA) {

                        tabuleiro[x][y] = BOMBA;
                    }
                }
            }

            if (cruz[linha][coluna] == 1) {

                int x = origemCruzLinha +
                        linha -
                        TAM_HABILIDADE / 2;

                int y = origemCruzColuna +
                        coluna -
                        TAM_HABILIDADE / 2;

                if (x >= 0 && x < LINHAS &&
                    y >= 0 && y < COLUNAS) {

                    if (tabuleiro[x][y] == NAVIO) {

                        tabuleiro[x][y] = ACERTO;

                    } else if (tabuleiro[x][y] == AGUA) {

                        tabuleiro[x][y] = BOMBA;
                    }
                }
            }

            if (octaedro[linha][coluna] == 1) {

                int x = origemOctaedroLinha +
                        linha -
                        TAM_HABILIDADE / 2;

                int y = origemOctaedroColuna +
                        coluna -
                        TAM_HABILIDADE / 2;

                if (x >= 0 && x < LINHAS &&
                    y >= 0 && y < COLUNAS) {

                    if (tabuleiro[x][y] == NAVIO) {

                        tabuleiro[x][y] = ACERTO;

                    } else if (tabuleiro[x][y] == AGUA) {

                        tabuleiro[x][y] = BOMBA;
                    }
                }
            }
        }
    }

    printf("\n\n\tTABULEIRO APOS AS HABILIDADES\n\n");

    printf("\t   ");

    for (coluna = 0; coluna < COLUNAS; coluna++) {
        printf("%c ", colunas[coluna]);
    }

    printf("\n");

    for (linha = 0; linha < LINHAS; linha++) {

        printf("\t%2d ", linha + 1);

        for (coluna = 0; coluna < COLUNAS; coluna++) {

            if (tabuleiro[linha][coluna] == AGUA) {

                printf("0 ");

            } else if (tabuleiro[linha][coluna] == NAVIO) {

                printf("3 ");

            } else if (tabuleiro[linha][coluna] == BOMBA) {

                printf("5 ");

            } else if (tabuleiro[linha][coluna] == ACERTO) {

                printf("X ");
            }
        }

        printf("\n");
    }

    return 0;
}