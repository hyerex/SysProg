#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fachnote.h"


int einlesen (fach_note *fn) {
    //char fach[FELDGROESSE + 1];
    fn->next = NULL;
    fn->previous = NULL;

    if (scanf("%20s", (char*) &fn->fachname) != 1) {
      return 0;
    }
    if (scanf("%d", &fn->benotetePruefung) == 1) {
      fn->pfArt = benotet;
    } else if (scanf("%c", &fn->leistung) == 1) {
      fn->pfArt = unbenotet;
    } else {
      return 0;
    }

      char *leerzeichen = strchr(fn->fachname, '_');
      while(leerzeichen != NULL) {
        *leerzeichen = ' ';
        leerzeichen = strchr(fn->fachname, '_');
      }
    return 1;
}

void ausgeben(const fach_note *fn) {
    printf("%-*s\t", 20, fn->fachname);

    if(fn->pfArt== benotet) {
      switch(fn->benotetePruefung) {
        case 10:
          printf("1,0\n");
          break;
        case 13:
          printf("1,3\n");
          break;
        case 17:
          printf("1,7\n");
          break;
        case 20:
          printf("2,0\n");
          break;
        case 23:
          printf("2,3\n");
          break;
        case 27:
          printf("2,7\n");
          break;
        case 30:
          printf("3,0\n");
          break;
        case 33:
          printf("3,3\n");
          break;
        case 40:
          printf("4,0\n");
          break;
        case 50:
          printf("5,0\n");
          break;
        default:
          printf("Fehler: %d\n", fn->benotetePruefung);
          break;
      }
    } else if (fn->pfArt == unbenotet) {
      if (fn->leistung == 'B') {
        printf("bestanden\n");
      } else if (fn->leistung == 'N') {
        printf("nicht bestanden\n");
      } else {
        printf("Fehler: %c\n", fn->leistung);
      }
    }
}
