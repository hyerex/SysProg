#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include "fachnote.h"
#include "liste.h"

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
