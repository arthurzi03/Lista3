#include <stdio.h>
#include <math.h>

double calcularMontanteMensal
(double valorAporte, double taxaDeJuros, int periodo)
 {
    double montante;
    montante = valorAporte * (1
 + taxaDeJuros) * ((
pow((1 + taxaDeJuros), periodo) - 1
) / taxaDeJuros);
    
return montante;
}

int main() {
    double valorAporte, taxaDeJuros;
    int periodo;

    scanf("%d", &periodo);
    scanf("%lf", &valorAporte);
    scanf("%lf", &taxaDeJuros);


    for (int mes = 1
; mes <= periodo; mes++) {
        
double
 montante = calcularMontanteMensal(valorAporte, taxaDeJuros, mes);
        
printf(
"Montante ao fim do mes %1d: R$ %.2f\n"
, mes, montante);
    }

    return 0;
}
