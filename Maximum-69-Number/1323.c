#include <stdio.h>

// Exercicio 1323 do Leetcode

// Reverte os digitos
int reverse(int num) {
    int res = 0;
    while (num != 0) {
        res = res * 10 + num % 10;
        num = num / 10;
    }
    return res;
}

// encontra o maior numero possivel encontrado com a alteracao
int maximumNumber(int num) {
    num = reverse(num);
    int res = 0;
    int change = 0;

    // passa por cada digito do numero revertido
    while (num != 0) {
        int temp = num % 10; // pega o digito mais a direita

        // Caso o digito seja 6 e nao tenha sido alterado, muda para 9
        if (temp == 6 && !change) {
            res = res * 10 + 9; // adiciona 9
            change = 1; // muda o indicador de alteracao
        } else {
            res = res * 10 + temp; // adiciona o digito ao resultado
        }

        num = num / 10; // passa para o proximo digito
    }

    return reverse(res); // reverte o resultado novamente (numero maximo)
}

int main() {
    int num;

    printf("Informe um numero composto apenas pelos digitos 6 e 9: ");
    scanf("%d", &num);

    int maxNum = maximumNumber(num);

    printf("Numero inicial: %d\n", num);
    printf("Numero Maximo: %d\n", reverse(maxNum));

    return 0;
}
