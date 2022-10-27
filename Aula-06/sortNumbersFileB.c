#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man qsort
*/

int compareInts(const void *px1, const void *px2)
{
    int x1 = *((int *)px1);
    int x2 = *((int *)px2);
    return (x1 < x2 ? -1 : x1 == x2 ? 0
                                    : 1);
}

int main(int argc, char *argv[])
{
    FILE *fp = NULL;

    /* Validate number of arguments */
    if (argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        perror("Error opening file!");
        return EXIT_FAILURE;
    }

    /* Read all the lines of the file */
    int numSize = 0;
    /* Memory allocation for all the numbers in the arguments */
    int numbers[100];
    int number;
    while (fscanf(fp,"%d",&number) == 1)
    {
        /* Storing the arguments in the "array" numbers */
        numbers[numSize] = number;
        numSize++;
    }
    fclose(fp);

    /* void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
         The qsort() function sorts an array with nmemb elements of size size.*/
    qsort(numbers, numSize, sizeof(int), compareInts);

    /* Printing the sorted numbers */
    printf("Sorted numbers: \n");
    for (int i = 0; i < numSize; i++)
    {
        printf("%d\n", numbers[i]);
    }

    return EXIT_SUCCESS;
}
