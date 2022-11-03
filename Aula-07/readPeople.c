#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct
{
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p)
{
    printf("Person: %s, %d, %f\n", p->name, p->age, p->height);
}

int main (int argc, char *argv[])
{
    FILE *fp = NULL;
    Person p;

    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "rb");
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    /* read all the itens of the file */
    while(fread(&p, sizeof(Person), 1, fp) == 1)
    {
        printPersonInfo(&p);
    }

    fclose(fp);

    char resposta;

    while (resposta != 'Y' && resposta != 'n')
    {
        printf("Pretende adicionar mais pessoas? (Y/n): ");
        (void)!scanf("%c",&resposta);
    }

    if (resposta == 'Y') {
        fp = fopen(argv[1], "ab");

        int i;
        int age;
        double height;
        char name[64];
        int numPessoas = 0;
        printf("Número de pessoas: ");
        (void)!scanf("%d",&numPessoas);
        for(i = 0 ; i < numPessoas ; i++)
        {    
            printf("Nome da pessoa: ");
            (void)!scanf("%s",name);
            printf("Idade da pessoa: ");
            (void)!scanf("%d",&age);
            printf("Altura da pessoa: ");
            (void)!scanf("%lf",&height);
            puts("");
            p.age = age;
            p.height = height;
            strcpy(p.name,name);
            fwrite(&p, sizeof(Person), 1, fp);
        }

        fclose(fp);
    }


    return EXIT_SUCCESS;
}
