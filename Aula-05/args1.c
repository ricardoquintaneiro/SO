#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 3) {
       for(int i = 0 ; i < argc ; i++) {
            printf("Argument %02d: \"%s\"\n", i, argv[i]);        
        }
        return EXIT_SUCCESS;
    }
    else {
        printf("Número errado de argumentos.\n");
        return EXIT_FAILURE;
    }

}
