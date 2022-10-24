#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
        TO-DO TODO
*/

int main(int argc, char *argv[])
{
    char palavras[90][90];
    for (int i = 1; i < argc; i++) {
        if (isalpha(*argv[i])) {
            *palavras[i-1] = argv[i];
        }
    }
    for (int i = 0; i < sizeof(palavras); i++) {
        printf("%s",palavras[i]);
    }
    return EXIT_SUCCESS;
}