/*
 * aufgabe4.c
 *
 * Liest Fachnamen mit Beurteilung ein und gibt dann einen Notenspiegel aus.
 *
 * Autor: TODO: Name
 * Erstellt am: TODO: Datum
 */

/* TODO: #include-Anweisungen, symbolische Konstante, Typen ... */

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

