#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

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

    printf("Informe os 9 primeiros dígitos do cpf: ");
    scanf("%d", &cpf);

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

            printf("%d\n", soma);
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

    printf("Os dígitos verificadores do cpf '%d' são '%d' e '%d'\n", cpf, cpfA[9], cpfA[10]);

    printf("\n");

    return 0;
}
