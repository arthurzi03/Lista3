#include <stdio.h>
#include <string.h>

void converteDecimalParaHexadecimal(int decimal) {
    char hexadecimalNum[20];
    int index = 0;

    while (decimal > 0) {
        int resto = decimal % 16;

        if (resto < 10) {
            hexadecimalNum[index] = resto + 48;
        } else {
            hexadecimalNum[index] = resto + 87;
        }

        index++;
        decimal = decimal / 16;
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexadecimalNum[i]);
    }

    printf("\n");
}
void converteDecimalParaBinario(int decimal) {
    int binario[1000];
    int i = 0;

    while (decimal > 0) {
        binario[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
}

int obtemValorCaractereRomano(char c) {
    if (c == 'I')
        return 1;
    if (c == 'V')
        return 5;
    if (c == 'X')
        return 10;
    if (c == 'L')
        return 50;
    if (c == 'C')
        return 100;
    if (c == 'D')
        return 500;
    if (c == 'M')
        return 1000;
    return -1;
}

int converteRomanoParaInteiro(char *s) {
    int res = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        int val1 = obtemValorCaractereRomano(s[i]);

        if (s[i + 1] != '\0') {
            int val2 = obtemValorCaractereRomano(s[i + 1]);

            if (val1 >= val2) {
                res = res + val1;
            } else {
                res = res + val2 - val1;
                i++;
            }
        } else {
            res = res + val1;
        }
    }

    return res;
}

int main() {
    char numRomano[20];
    scanf("%s", numRomano);

    int resultado = converteRomanoParaInteiro(numRomano);

    printf("%s em base 10: %d\n", numRomano, resultado);
    printf("%s em base 2: ", numRomano);
    converteDecimalParaBinario(resultado);
    printf("%s em base 16: ", numRomano);
    converteDecimalParaHexadecimal(resultado);

    return 0;
}