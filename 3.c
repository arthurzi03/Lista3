#include <stdio.h>
#include <string.h>
#include <ctype.h>


int isNumber(char c) {
    return (c >= '0' && c <= '9');
}
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int verificarAutorizacao(char placa[], char diaSemana[]) {
    int tam = strlen(placa);

    char ultimoDigito = placa[tam - 1];
    int digito = ultimoDigito - '0';

    if ((strcmp(diaSemana, "segunda-feira") == 0 && (digito == 0 || digito == 1)) ||
        (strcmp(diaSemana, "terca-feira") == 0 && (digito == 2 || digito == 3)) ||
        (strcmp(diaSemana, "quarta-feira") == 0 && (digito == 4 || digito == 5)) ||
        (strcmp(diaSemana, "quinta-feira") == 0 && (digito == 6 || digito == 7)) ||
        (strcmp(diaSemana, "sexta-feira") == 0 && (digito == 8 || digito == 9))) {
        return 0; 
    } else {
        return 1; 
    }
}

int main() {
    char placa[20];
    char diaSemana[20];

    scanf("%19s", placa);  

    scanf("%19s", diaSemana);


    if (!((strlen(placa) == 7 || strlen(placa) == 8) &&
          (isalpha((unsigned char)placa[0]) && isalpha((unsigned char)placa[1]) && isalpha((unsigned char)placa[2]) &&
           isNumber(placa[strlen(placa) - 1])))) {
        printf("Placa invalida\n");
         if (strcmp(diaSemana, "SEGUNDA-FEIRA") != 0 &&
        strcmp(diaSemana, "TERCA-FEIRA") != 0 &&
        strcmp(diaSemana, "QUARTA-FEIRA") != 0 &&
        strcmp(diaSemana, "QUINTA-FEIRA") != 0 &&
        strcmp(diaSemana, "SEXTA-FEIRA") != 0 &&
        strcmp(diaSemana, "SABADO") != 0 &&
        strcmp(diaSemana, "DOMINGO") != 0) {
        printf("Dia da semana invalido\n");
    }
        return 0;
    }

    if (strcmp(diaSemana, "SEGUNDA-FEIRA") != 0 &&
        strcmp(diaSemana, "TERCA-FEIRA") != 0 &&
        strcmp(diaSemana, "QUARTA-FEIRA") != 0 &&
        strcmp(diaSemana, "QUINTA-FEIRA") != 0 &&
        strcmp(diaSemana, "SEXTA-FEIRA") != 0 &&
        strcmp(diaSemana, "SABADO") != 0 &&
        strcmp(diaSemana, "DOMINGO") != 0) {
        printf("Dia da semana invalido\n");
        return 0;
    }
 
    toLowerCase(diaSemana);

    int autorizado = verificarAutorizacao(placa, diaSemana);

    if (strcmp(diaSemana, "sabado") == 0 || strcmp(diaSemana, "domingo") == 0) {
        printf("Nao ha proibicao no fim de semana\n");
    } else if (autorizado) {
        printf("%s pode circular %s\n", placa, diaSemana);
    } else {
        printf("%s nao pode circular %s\n", placa, diaSemana);
    }

    return 0;
}
