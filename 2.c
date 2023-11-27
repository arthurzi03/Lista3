#include <stdio.h>
#include <math.h>

// Função para calcular o valor do montante ao fim de cada mês
double calcularMontanteMensal(double principal, double taxaDeJuros, int periodo) {
    double montante = principal * pow(1 + taxaDeJuros, periodo);
    return montante;
}

int main() {
    double principal, taxaDeJuros;
    int periodo;

    // Entrada de dados
    printf("Informe o período em meses: ");
    scanf("%d", &periodo);

    printf("Informe o valor do investimento: R$ ");
    scanf("%lf", &principal);

    printf("Informe a taxa de juros mensal (em decimal): ");
    scanf("%lf", &taxaDeJuros);

    // Cálculo e exibição do montante ao fim de cada mês
    for (int mes = 1; mes <= periodo; mes++) {
        double montante = calcularMontanteMensal(principal, taxaDeJuros, mes);
        printf("Montante ao fim do mês %d: R$ %.2f\n", mes, montante);
    }

    return 0;
}