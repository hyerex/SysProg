/*
* bubblesort.c
*
*
* Autor: Andreas Ly
* Erstellt am: 31.10.18
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[])
{
    srand((unsigned int) time(NULL));
    //---- Feldgroesse einlesen
    if (argc != 2)
    {
        printf("%d\n", argc);
        printf("Aufruf: java Bubblesort Anzahl \n");
        return 0;
    }
    //argc = argc + 1;
    printf("argc %d\n", argc);

    int n = atoi(argv[1]);
    printf("atoi %d\n", n);
    int *a = (int*) calloc(n, sizeof(int));
    if ( a == NULL)
    {
        printf("Error!!\n");
        return 1;
    }
//---------------------------------------------------- Zahlen einlesen
    printf("Bitte %d ganze Zahlen eingeben: ", n);
    for (int i = 0; i < n; i++)
    {

        if (scanf("%d", &a[i]) != 1)
        {
            a[i] = rand();
        }

    }
    //--------------------------------------------------- Zahlen sortieren
    for (int i = n; i > 1; i--)
    {
        // groessten Wert nach hinten schieben
        for (int j = 0; j < i - 1; ++j)
        {
            if (a[j] > a[j + 1])
            {
                // Werte tauschen
                int tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }

    }
//---------------------------------------------------- Zahlen ausgeben
    printf("Sortierte Zahlenfolge: ");
    printf("%d\n", n);
    for (int i = 0; i < n; ++i)
    {
        printf("%d\n", a[i]);
    }

    free(a);

    return 0;
}
