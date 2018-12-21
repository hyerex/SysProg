/*
 * aufgabe4.c
 *
 * Liest Fachnamen mit Beurteilung ein und gibt dann einen Notenspiegel aus.
 *
 * Autor: Andreas Ly
 * Erstellt am: 29.11.2018
 */

/* TODO: #include-Anweisungen, symbolische Konstante, Typen ... */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FELDGROESSE 20

enum pruefungsArten {benotet, unbenotet};

struct fach_note {
    struct fach_note *next;
    struct fach_note *previous;
    char fachname[FELDGROESSE];

    enum pruefungsArten pfArt;

    union {
      int benotetePruefung;
      char leistung;
    };
};

typedef struct fach_note fach_note;

int einlesen (fach_note *fn);

void ausgeben(const fach_note *fn);

fach_note* einfuegen (fach_note *, fach_note *);

void schleife (fach_note *, void (*func) (const fach_note *));

fach_note* entfernen (fach_note *, fach_note **);


int main(void)
{
    fach_note *notenspiegel = NULL;

    //------------------------------------------- Notenspiegel einlesen
    fprintf(stderr, "Faecher mit Noten eingeben (Ende mit Strg-D):\n");

    for (;;)
    {
        fach_note *p = (fach_note *) malloc(sizeof (fach_note));
        if (p == NULL)
        {
            fprintf(stderr, "Zu viele Faecher!\n");
            break;
        }

        if (! einlesen(p))
        {
            fprintf(stderr, "Eingabeende!\n");
            free(p);
            break;
        }

        notenspiegel = einfuegen(notenspiegel, p);
    }

    //------------------------------------------- Notenspiegel ausgeben
    printf("Notenspiegel:\n");

    schleife(notenspiegel, ausgeben);

    //------------------------------------------- Notenspiegel loeschen
    while (notenspiegel != NULL)
    {
        fach_note *p;
        notenspiegel = entfernen(notenspiegel, &p);
        free(p);
    }

    return 0;
}


/* TODO: Funktionsimplementierungen */
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

fach_note* einfuegen(fach_note *hl, fach_note *fn) {
    if (hl == NULL){
      hl = fn;
      hl->next = NULL;
    } else {
      hl->previous = fn;
      fn->next = hl;
      hl = fn;
      return hl;
    }
    return hl;
}

void schleife(fach_note *fn, void (*func) (const fach_note *fn)) {

  fach_note *h = fn;
  while (h != NULL) {
    func(h);
    h = h->next;
  }
}

fach_note* entfernen(fach_note *hl, fach_note **p) {

  *p = hl;
  hl = hl->next;

  if(hl != NULL) {
    hl->previous->next = NULL;
    hl->previous = NULL;
  }
  return hl;
}
