#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        char *endarg;
        double a1 = strtod(argv[1], &endarg);
        if (endarg == argv[1] || *endarg != '\0')
        {
            printf("Primeiro operando inválido.\n");
            return EXIT_FAILURE;
        }
        if (strlen(argv[2]) != 1)
        {
            return EXIT_FAILURE;
        }
        char operacao = argv[2][0];
        double a2 = strtod(argv[3], &endarg);
        if (endarg == argv[3] || *endarg != '\0')
        {
            printf("Segundo operando inválido.\n");
            return EXIT_FAILURE;
        }
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
            resultado = pow(a1, a2);
            break;
        default:
            return EXIT_FAILURE;
        }
        printf("Resultado: %.1f\n", resultado);
        return EXIT_SUCCESS;
    }
    else
    {
        printf("Número errado de argumentos.\n");
        return EXIT_FAILURE;
    }
}
