#ifndef LISTE_H
#define LIST_H
#include "fachnote.h"

fach_note* einfuegen (fach_note *, fach_note *);

void schleife (fach_note *, void (*func) (const fach_note *));

fach_note* entfernen (fach_note *, fach_note **);
#endif
