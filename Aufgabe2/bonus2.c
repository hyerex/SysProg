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
        printf("Aufruf: java Bubblesort Anzahl \n");
        return 0;
    }
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
    for (int i = 0; i < n; ++i) {
      int r = rand() % n;
      a[i] = r;
    }

    free(a);

    return 0;
}
