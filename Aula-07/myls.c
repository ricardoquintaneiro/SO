#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void listDir(char dirname[], char option)
{
    DIR *dp;
    struct dirent *dent;
    int extension_length = 0;
    char extension[40];
    if (option == 'e')
    {
        while (dirname[extension_length] != ' ')
        {
            extension_length++;
        }
        char extension_local[extension_length + 1];
        strncpy(extension_local, dirname, extension_length);
        extension_local[extension_length] = '\0';
        dirname = dirname + extension_length + 1;
        strcpy(extension,extension_local);
    }

    dp = opendir(dirname);

    if (dp == NULL)
    {
        perror("Error opening directory");
        return;
    }
    dent = readdir(dp);
    while (dent != NULL)
    {
        if (dent->d_name[0] != '.') /* do not list hidden dirs/files */
        {
            if (option == 'd')
            {
                if (dent->d_type == DT_DIR)
                    printf("%s\n", dent->d_name);
            }
            else if (option == 'f')
            {
                if (dent->d_type != DT_DIR)
                    printf("%s\n", dent->d_name);
            }
            else if (option == 'e')
            {
                if (dent->d_type != DT_DIR)
                {

                    char *file_name = strtok(dent->d_name, ".");
                    char *ext = strtok(NULL, ".");
                    if (strcmp(ext,extension) == 0) {
                        printf("%s.%s\n", dent->d_name, ext);
                    }
                }
            }
        }
        dent = readdir(dp);
    }

    closedir(dp);
}

int main(int argc, char *argv[])
{
    int opt;
    while ((opt = getopt(argc, argv, "d:e:f:")) != -1)
    {
        if (opt == 'f' || opt == 'd' || opt == 'e')
        {
            listDir(optarg, opt);
        }
        else
        {
            fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",
                    argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    return EXIT_SUCCESS;
}
