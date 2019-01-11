/*
 * stringsort.c
 *
 *
 * Author: Andreas Ly
 * Date:   14.11.2018
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <string.h>
 int main(int argc, char *argv[])
 {


   //--- Feldgroesse einlesen
   if (argc != 2) {
     printf("%d\n", argc);
     printf("Aufruf: C Stringsort Anzahl \n");
     return 1;
   }

   int n = atoi(argv[1]);

   if (n < 1) {
     printf("Anzahl muss mindestens 1 sein");
     return 1;
   }

   //--- Strings wuerfeln
   char **a = (char**) malloc(sizeof(char*) * n);

   if (a == NULL) {
     printf("ERROR");
     return 1;
   }

   srand((unsigned int) time(NULL));


   printf("argc %d\n", argc);

   printf("Unsortiertes Feld:\n");
   for(int i = 0; i < n; i++) {
     if (a == NULL) {
       printf("ERROR");
       return 1;
     }
     int r = rand() % n;
     a[i] = (char*) malloc(strlen(argv[1]) + 1 * sizeof(char));
     sprintf(a[i], "%i", r);
     printf("%s ", a[i]);
   }
   printf("\n");

   //--- String sortieren
   for (int i = n; i > 1; i--) {
       // groessten Wert nach hinten schieben
       for (int j = 0; j < i - 1; ++j) {
           if (strcmp(a[j], a[j + 1]) > 0) {
               // Werte tauschen
               char* tmp = a[j + 1];
               a[j + 1] = a[j];
               a[j] = tmp;
           }
       }
   }

   //--- String ausgeben
   printf("Sortiertes Feld:\n");
   char* all = (char*) calloc(n * (strlen(argv[1]) + 1) + n-1, sizeof(char));
   strcat(all, a[0]);
   for (int i = 1; i < n; ++i) {
     if (strcmp(a[i], a[i-1]) == 0) {
       strcat(all, "*");
     } else {
       strcat(all, " ");
       strcat(all, a[i]);
     }
   }
   printf("%s\n", all);

   //--- Speicher freigeben
   free(all);
   for (int i = 0; i < n; i++) {
     free(a[i]);
   }
   free(a);
   return 0;
 }
