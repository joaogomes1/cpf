#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    int p;

    int cpf;
    int cpfC;
    int cpfA[12];
    int i;
    int j;
    int k;
    int m;
    int soma;
    int resto;

    setlocale(LC_ALL, "");

    p = 0;
    while ( p == 0 ) {

        printf("Informe os 9 primeiros dígitos do cpf: ");
        scanf("%d", &cpf);

        cpfC = cpf;
        i = 0;
        while( cpfC >= 1 ) {

            cpfC /= 10;
            i++;
        }

        if ( i != 9 ) {

            printf("É necessário informar um número com nove dígitos\n");
            printf("\n");
        }
        else {

            p = 1;
        }

    }

    i = 8;
    cpfC = cpf;
    while ( cpfC > 0 ) {

        cpfA[i] = cpfC % 10;
        cpfC /= 10;
        i--;
    }

    j = 0;
    while ( j < 2 ) {

        i = 0;
        k = j + 10;
        m = k - 1;
        soma = 0;

        while ( i < m ) {

            soma += cpfA[i] * k;
            k--;
            i++;
        }

        resto = soma % 11;
        if ( resto < 2 ) {

            cpfA[m] = 0;
        }
        else {

            cpfA[m] = 11 - resto;
        }

        j++;
    }

    printf("\n");

    printf("Os dígitos verificadores do cpf '%d' são '%d' e '%d'\n", cpf, cpfA[9], cpfA[10]);

    return 0;
}
