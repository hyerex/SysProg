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
#define FELDGROESSE 20

struct fach_note {
    struct fach_note *next;
    struct fach_note *previous;
    char fachname[FELDGROESSE];

    enum pruefungsArten {benotet, unbenotet}

    union {
      int benotetePruefung;
      char leistung;
    }
}

int einlesen (fach_note *fn);

void ausgeben(const fach_note *fn);

int einfuegen (fach_note *, fach_note*);

void schleife (fach_note *fn, void (*pfunc) (const fach_note *));

void entfernen (fach_note *fn, )


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

int einlesen (fach_note *fn) {

  if (scanf())
}
/* TODO: Funktionsimplementierungen */
