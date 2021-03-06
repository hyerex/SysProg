/*
* aufgabe1.c
*
*
* Autor: Andreas Ly
* Erstellt am: 20.10.18
*/

#include <stdio.h>

int main(void)
{
    int a = 12;
    short int b = 13;
    long int c = 14L;
    long long int d = 15LL;

    unsigned int e = 0xffffffffU;  //hex ausgabe mit %x und dez ausgabe mit %u
    unsigned short int f = 0xffffU;

    float g = 3.14F;
    double h = 3.15;
    long double i = 3.16L;

    char j = 'a';
    signed char k = -1;
    unsigned char l = 0xff;

    unsigned long int m = 0xffffUL;
    unsigned long long int n = 0xffffULL;


    char* s = (char*) "Hallo";


    // %p für Adresse


    printf("\n");
    printf("\n");

    printf("%15p || %2zu || %22s || %s || %i\n ", (void*) &a, sizeof(a), "int", "a", a);
    //printf("------------------------------------------------------------------\n");

    printf("%14p || %2zu || %22s || %s || %hi\n ", (void*) &b, sizeof(b), "short int", "b", b);
    //printf("------------------------------------------------------------------\n");

    printf("%14p || %2zu || %22s || %s || %li\n ", (void*) &c, sizeof(c), "long int", "c", c);
    //printf("------------------------------------------------------------------\n");

    printf("%14p || %2zu || %22s || %s || %lli\n ", (void*) &d, sizeof(d), "long long int", "d", d);
    //printf("------------------------------------------------------------------\n");

    printf("%14p || %2zu || %22s || %s || %u\n ", (void*) &e, sizeof(e), "unsigned int", "e", e);
    //printf("------------------------------------------------------------------\n");

    printf("%14p || %2zu || %22s || %s || %hu\n ", (void*) &f, sizeof(f), "unsigned short int", "f", f);
    //printf("------------------------------------------------------------------\n");

    printf("%14p || %2zu || %22s || %s || %g\n ", (void*) &g, sizeof(g), "float", "g", g);
    //printf("------------------------------------------------------------------\n");

    printf("%14p || %2zu || %22s || %s || %g\n ", (void*) &h, sizeof(h), "double", "h", h);
    //printf("------------------------------------------------------------------\n");

    printf("%14p || %2zu || %22s || %s || %Lg\n ", (void*) &i, sizeof(i), "long double", "i", i);
    //printf("------------------------------------------------------------------\n");

    printf("%14p || %2zu || %22s || %s || %c\n ", (void*) &j, sizeof(j), "char", "j", j);
    //printf("------------------------------------------------------------------\n");

    printf("%14p || %2zu || %22s || %s || %hhi\n ", (void*) &k, sizeof(k), "signed char", "k", k);
    //printf("------------------------------------------------------------------\n");

    printf("%14p || %2zu || %22s || %s || %hhu\n ", (void*) &l, sizeof(l), "unsigned char", "l", l);

    //printf("------------------------------------------------------------------\n");
    printf("%14p || %2zu || %22s || %s || %lu\n ", (void*) &m, sizeof(m), "unsigned long int", "m", m);

    //printf("------------------------------------------------------------------\n");
    printf("%14p || %2zu || %22s || %s || %llu\n ", (void*) &n, sizeof(n), "unsigned long long int", "n", n);


    //printf("------------------------------------------------------------------\n");
    printf("%14p || %2zu || %22s || %s || %s\n ", (void*) &s, sizeof(char*), "char*", "s", s);

    printf("\n");
    printf("\n");



    /*
     * Ausgabe Datenmodell
     * a = int, c = long int, s = char*
     * Notiz for me: Siehe Aufgabenstellung und Script Folie 2-15.
     */

    printf("Aktuell benutztes Datenmodell:\n");

    if (sizeof(a) == 4 && sizeof(c) == 4 && sizeof(s) == 4)
        printf("ILP32");
    else if (sizeof(a) == 4 && sizeof(c) == 8 && sizeof(s) == 8)
        printf("LP64");
    else if (sizeof(a) == 4 && sizeof(c) == 4 && sizeof(d) == 8 && sizeof(s) == 8)
        printf("LLP64");






    printf("\n");


    return 0;

}
