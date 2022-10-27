#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man fopen
 man fgets
*/

#define LINEMAXSIZE 80 /* or other suitable maximum line size */

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char line[LINEMAXSIZE];

    /* Validate number of arguments */
    if (argc < 2)
    {
        printf("USAGE: %s fileName fileName...\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    for (int i = 1; i < argc; i++)
    {
        errno = 0;
        fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            perror("Error opening file!");
            return EXIT_FAILURE;
        }

        /* Read all the lines of the file */
        int lineCount = 0;
        int completeLine = 1;
        while (fgets(line, sizeof(line), fp) != NULL)
        {
            if (completeLine == 1)
            {
                lineCount++;
                printf("%d -> %s", lineCount, line); /* not needed to add '\n' to printf because fgets will read the '\n' that ends each line in the file */
            }
            else
            {
                printf("%s", line); /* not needed to add '\n' to printf because fgets will read the '\n' that ends each line in the file */
            }
            int linesize = strlen(line);
            if (linesize == LINEMAXSIZE - 1 && line[linesize-1] != '\n')
            {
                completeLine = 0;
            }
            else {
                completeLine = 1;
            }
        }
        puts("");
        fclose(fp);
    }

    return EXIT_SUCCESS;
}
