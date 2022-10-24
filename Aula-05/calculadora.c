#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 4) {
        double a1 = atof(argv[1]);
        if (strlen(argv[2]) != 1) {
            return EXIT_FAILURE;
        }
        char operacao = argv[2][0];
        double a2 = atof(argv[3]);
        double resultado;
        switch (operacao)
        {
        case '+':
            resultado = a1 + a2;
            break;
        case '-':
            resultado = a1 - a2;
            break;
        case 'x':
            resultado = a1 * a2;
            break;
        case '/':
            resultado = a1 / a2;
            break;
        case 'p':
            resultado = pow(a1,a2);
            break;
        default:
            return EXIT_FAILURE;
        }
        printf("Resultado: %.1f\n",resultado);
        return EXIT_SUCCESS;
    }
    else {
        printf("Número errado de argumentos.\n");
        return EXIT_FAILURE;
    }
}
