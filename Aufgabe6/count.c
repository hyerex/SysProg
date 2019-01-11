/*
 * count.c
 *
 * Zaehlt die Zeichen in Dateien.
 *
 * Author H.Drachenfels
 * Erstellt am: 28.7.2017 / 14.11.2017 (C11)
 */

#include <stdio.h>  // fopen, fgetc, fclose, ferror, perror

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            perror(argv[i]);
            continue;
        }

        int n = 0;
        while (fgetc(fp) != EOF)
        {
            ++n;
        }

        if (ferror(fp))
        {
            perror(argv[i]);
            fclose(fp);
            continue;
        }

        printf("%s: %d Zeichen\n", argv[i], n);

        fclose(fp);
    }

    return 0;
}
