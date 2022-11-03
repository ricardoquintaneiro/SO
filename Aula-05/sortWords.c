#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *sortorder = getenv("SORTORDER");
    if ((strcmp(sortorder, "D") != 0) || (strcmp(sortorder, "D") != 0))
        return EXIT_FAILURE;
    char palavras[90][90];
    int done = 0;
    for (int i = 1; i < argc; i++)
    {
        if (isalpha(argv[i][0]))
            strcpy(palavras[i - 1], argv[i]);
        done++;
    }
    if (done > 0)
    {
        int reset = 1;
        char stemp[90];
        while (reset == 1 && done > 0)
        {
            for (int i = 0; i < done - 1; i++)
            {
                reset = 0;
                for (int k = 0; k < strlen(palavras[i] + 1); k++)
                {
                    if (palavras[i][k] < palavras[i + 1][k])
                    {
                        strcpy(stemp, palavras[i + 1]);
                        strcpy(palavras[i + 1], palavras[i]);
                        strcpy(palavras[i], stemp);
                        reset = 1;
                        break;
                    }
                }
                if (reset == 1) break;
            }
        }
        for (int j = 0; j < done; j++)
            printf("%s\n", palavras[j]);
    }
    return EXIT_SUCCESS;
}