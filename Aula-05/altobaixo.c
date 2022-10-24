#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[])
{
    char *endarg;
    int liminf = strtod(argv[1], &endarg);
    if (endarg == argv[1] || *endarg != '\0')
    {
        printf("Primeiro limite inválido.\n");
        return EXIT_FAILURE;
    }
    int limsup = strtod(argv[2], &endarg);
    if (endarg == argv[2] || *endarg != '\0')
    {
        printf("Segundo limite inválido.\n");
        return EXIT_FAILURE;
    }
    srand(time(NULL));
    int numero = (rand() % (limsup + abs(liminf)) - abs(liminf));
    int tentativa = liminf - 1;
    int contagem = 0;
    while (tentativa != numero)
    {
        printf("Tentativa? ");
        scanf("%d", &tentativa);
        contagem++;
        if (tentativa < numero) {
            printf("É mais alto.\n");
        }
        else if (tentativa > numero) {
            printf("É mais baixo.\n");
        }
    }
    printf("Acertou no número %d em %d tentativas.\n", numero, contagem);
    return EXIT_SUCCESS;
}