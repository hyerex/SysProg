/*
 * copy.c
 *
 * Kopiert eine Datei.
 * Verwendet elementare Ein-/Ausgabe nach POSIX-Standard.
 *
 * Author H.Drachenfels
 * Erstellt am: 28.7.2017 / 8.3.2018 (C11)
 */

#define _POSIX_C_SOURCE 1

#include <stdlib.h>
#include <locale.h>

#include <stdio.h>  // fprintf
#include <string.h> // strerror

#include <fcntl.h>    // open, O_RDONLY, O_WRONLY, O_CREAT, O_EXCL
#include <sys/stat.h> // mode_t, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
#include <unistd.h>   // read, write
#include <errno.h>    // errno

int main(int argc, char *argv[])
{
    char* locale = setlocale(LC_MESSAGES, "de_DE.UTF-8");

    if (locale == NULL) {
        fprintf(stderr, "Deutsche Sprache wird nicht unterstützt");
    }


    if (argc != 3)
    {
        fprintf(stderr, "Aufruf: %s Quelle Ziel\n", argv[0]);
        return 1;
    }

    int in = open(argv[1], O_RDONLY); // Dateindeskriptor Quelle
    if (in == -1)
    {
        fprintf(stderr,
                "Quelle %s kann nicht geoeffnet werden (errno %d: %s)\n",
                argv[1], errno, strerror(errno));
        return 1;
    }

    const mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // rw-r--r--
    int out = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, mode); // Dateiseskriptor Ziel
    if (out == -1)
    {
        fprintf(stderr,
                "Ziel %s kann nicht erzeugt werden (errno %d: %s)\n",
                argv[2], errno, strerror(errno));
        return 1;
    }

    //int n;

    //unsigned char b;

    struct stat s;
    if (fstat(in, &s) < 0) {
        fprintf(stderr, "Stat Aufruf fehlgeschlagen (errno %d: %s)\n", errno, strerror(errno));
        return 1;
    }
    ssize_t l = s.st_size;

    //reservierung
    char* x = malloc(sizeof(char) * l);
    if(x == NULL) {
        printf("Speicher konnte nicht reserviert werden\n");
        return 1;
    }

    ssize_t n = read(in, x, l);
    if (n == -1)
    {
        fprintf(stderr,
                "Lesefehler (errno %d: %s)\n", errno, strerror(errno));
        return 1;
    }

    if (n < l)
    {
      fprintf(stderr, "Datei wurde nicht vollständig gelesen\n");
      return 1;
    }
    
    int m = write(out, x, l);
    if (m == -1)
    {
        fprintf(stderr,
                "Schreibfehler (errno %d: %s)\n", errno, strerror(errno));
        return 1;
    }

    if (n < l)
    {
      fprintf(stderr, "Datei wurde nicht vollstaendig geschrieben\n");
      return 1;
    }

    close(out);
    close(in);

    free(x);

    return 0;
}
