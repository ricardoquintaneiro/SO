#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char string[80];
    for (int i = 1; i < argc ; i++) {
        if (isalpha(*argv[i])) {
            strcat(string, argv[i]);
        }
    }
    printf("%s\n",string);
}