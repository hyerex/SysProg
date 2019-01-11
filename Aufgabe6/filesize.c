/*
 * filesize.c
 *
 * Gibt die Groesse der Dateien in Byte an.
 *
 * Author: Andreas Ly
 * Erstellt am: 10.01.2018
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h> // strerror
#include <locale.h>
#include <fcntl.h>    // open, O_RDONLY, O_WRONLY, O_CREAT, O_EXCL
#include <sys/stat.h> // mode_t, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
#include <unistd.h>   // read, write
#include <errno.h>    // errno

int main(int argc, char *argv[]) {

  setlocale(LC_ALL, "");

  if (argc == 1) {
    char p;
    int n = 0;
    while(read(0, &p, 1) > 0) {
      ++n;
    }

    if (ferror(stdin)) {
      perror("");
      return 1;
    }
    printf("Anzahl Bytes: %d\n", n);
    return 0;

  }


  for (int i = 1; i < argc; ++i) {
      struct stat s;
      if (stat(argv[i], &s) == -1) {
        perror(argv[i]);
        continue;
      }
      printf("Datei: %s Groesse: %d Bytes\n", argv[i], (int) s.st_size);
  }
  return 0;
}
