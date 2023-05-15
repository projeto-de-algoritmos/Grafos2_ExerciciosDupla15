#include <stdio.h>


//exercicio 59 do leetcode

void generateMatrix(int n) {
    int matrix[n][n];
    int num = 1;
    int row_start = 0, row_end = n - 1;
    int col_start = 0, col_end = n - 1;

    while (row_start <= row_end && col_start <= col_end) {
        //Imprime a primeira linha
        for (int i = col_start; i <= col_end; i++) {
            matrix[row_start][i] = num++;
        }
        row_start++;

        // Imprime a coluna da direita a partir do final da primeira linha
        for (int i = row_start; i <= row_end; i++) {
            matrix[i][col_end] = num++;
        }
        col_end--;

        // imprime a linha inferior a partir do final da coluna da direita
        for (int i = col_end; i >= col_start; i--) {
            matrix[row_end][i] = num++;
        }
        row_end--;

        // imprime a coluna da esquerda a partir do final da linha inferior
        for (int i = row_end; i >= row_start; i--) {
            matrix[i][col_start] = num++;
        }
        col_start++;
    }

    // Mostra a matriz
    printf("Matriz Espiral Gerada:\n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%-3d ", matrix[i][j]); // %-3d imprime com largura de 3 campos, fica idêntico a uma matriz como conhecemos
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    printf("\n");
    generateMatrix(n);

    return 0;
}
