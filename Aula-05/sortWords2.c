#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int count;
    char palavras[90][90], temp[25];
    char *sortorder = getenv("SORTORDER");
    if (sortorder == NULL)
    {
        printf("Exporte a variável SORTORDER na bash. export SORTORDER=D ou export SORTORDER=C.\n");
        return EXIT_FAILURE;
    }
    if ((strcasecmp(sortorder, "C") != 0) && (strcasecmp(sortorder, "D") != 0))
    {
        printf("SORTORDER inválido.\n");
        return EXIT_FAILURE;
    }

    printf("Introduza as palavras (ENTER para terminar):\n");
    while (1)
    {
        fgets(palavras[count], 100, stdin);
        if (palavras[count][0] == '\n')
            break;
        palavras[count][strlen(palavras[count]) - 1] = '\0';
        if (isalpha(palavras[count][0]))
            count++;
    }

    if (count > 0)
    {
        for (int k = 0; k < count; k++)
        {
            for (int j = k + 1; j < count; j++)
            {
                if (strcasecmp(sortorder, "C") == 0)
                {
                    if (strcasecmp(palavras[k], palavras[j]) > 0)
                    {
                        strcpy(temp, palavras[k]);
                        strcpy(palavras[k], palavras[j]);
                        strcpy(palavras[j], temp);
                    }
                }
                else
                {
                    if (strcasecmp(palavras[k], palavras[j]) < 0)
                    {
                        strcpy(temp, palavras[j]);
                        strcpy(palavras[j], palavras[k]);
                        strcpy(palavras[k], temp);
                    }
                }
            }
        }
        for (int l = 0; l < count; l++)
            printf("%s\n", palavras[l]);
    }
    return EXIT_SUCCESS;
}