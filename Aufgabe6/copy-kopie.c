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

#include <stdio.h>  // fprintf
#include <string.h> // strerror

#include <fcntl.h>    // open, O_RDONLY, O_WRONLY, O_CREAT, O_EXCL
#include <sys/stat.h> // mode_t, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
#include <unistd.h>   // read, write
#include <errno.h>    // errno

int main(int argc, char *argv[])
{
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

    int n;
    unsigned char b;
    while ((n = read(in, &b, 1)) > 0)
    {
        int m = write(out, &b, 1);
        if (m != 1)
        {
            fprintf(stderr,
                    "Schreibfehler (errno %d: %s)\n", errno, strerror(errno));
            return 1;
        }
    }

    if (n < 0)
    {
        fprintf(stderr,
                "Lesefehler (errno %d: %s)\n", errno, strerror(errno));
        return 1;
    }

    close(out);
    close(in);

    return 0;
}
