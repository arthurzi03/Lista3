#include <stdio.h>
#include <string.h>
#include <ctype.h>
int eNumero(char c) {
    return (c >= '0' && c <= '9');
}
void paraMinusculas(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int verificarPermissao(char placa[], char dia[]) {
    int tam = strlen(placa);

    char ultimoDigito = placa[tam - 1];
    int digito = ultimoDigito - '0';
    if ((strcmp(dia, "segunda-feira") == 0 && (digito == 0 || digito == 1)) ||
        (strcmp(dia, "terca-feira") == 0 && (digito == 2 || digito == 3)) ||
        (strcmp(dia, "quarta-feira") == 0 && (digito == 4 || digito == 5)) ||
        (strcmp(dia, "quinta-feira") == 0 && (digito == 6 || digito == 7)) ||
        (strcmp(dia, "sexta-feira") == 0 && (digito == 8 || digito == 9))) {
        return 0;
    } else {
        return 1; 
    }
}

int main() {
    char placaVeiculo[20];
    char nomeDiaSemana[20];

    scanf("%19s", placaVeiculo); 
    scanf("%19s", nomeDiaSemana);
    paraMinusculas(nomeDiaSemana);
    if (strcmp(nomeDiaSemana, "segunda-feira") != 0 &&
        strcmp(nomeDiaSemana, "terca-feira") != 0 &&
        strcmp(nomeDiaSemana, "quarta-feira") != 0 &&
        strcmp(nomeDiaSemana, "quinta-feira") != 0 &&
        strcmp(nomeDiaSemana, "sexta-feira") != 0 &&
        strcmp(nomeDiaSemana, "sabado") != 0 &&
        strcmp(nomeDiaSemana, "domingo") != 0) {
        printf("Dia da semana inválido\n");
        return 0;
    }

    if (!((strlen(placaVeiculo) == 7 || strlen(placaVeiculo) == 8) &&
          (isalpha((unsigned char)placaVeiculo[0]) && isalpha((unsigned char)placaVeiculo[1]) && isalpha((unsigned char)placaVeiculo[2]) &&
           eNumero(placaVeiculo[strlen(placaVeiculo) - 1])))) {
        printf("Placa inválida\n");
        return 0;
    }

    int autorizado = verificarPermissao(placaVeiculo, nomeDiaSemana);

    if (strcmp(nomeDiaSemana, "sabado") == 0 || strcmp(nomeDiaSemana, "domingo") == 0) {
        printf("Não há proibição no fim de semana\n");
    } else if (autorizado) {
        printf("%s pode circular %s\n", placaVeiculo, nomeDiaSemana);
    } else {
        printf("%s não pode circular %s\n", placaVeiculo, nomeDiaSemana);
    }

    return 0;
}