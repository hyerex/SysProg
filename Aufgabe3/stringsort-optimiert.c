/*
 * stringsort-optimiert.c
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
   srand((unsigned int) time(NULL));
   int n = atoi(argv[1]);
   int m = strlen(argv[1]) + 1;

   //--- Feldgroesse einlesen
   if (argc != 2) {
     printf("%d\n", argc);
     printf("Aufruf: C Stringsort Anzahl \n");
     return 1;
   }

   if (n < 1) {
     printf("Anzahl muss mindestens 1 sein");
     return 1;
   }

   //--- Strings wuerfeln
   printf("%d Laenge\n" , m);
   char* a = (char*) calloc(n * m, sizeof(char));

   printf("Unsortiertes Feld:\n");
   for(int i = 0; i < n; i++) {
     // erstellt eine Zufällige Zahl zwischen 0 und n
     int r = rand() % n;
     // x ist die Position, bei dem der String im Array startet  (Index vom String)
     int x = i * m;
     //
     sprintf(&a[x], "%i", r);
     printf("%s ", &a[x]);
   }
   printf("\n");

   char *tmp = (char*)malloc(m);

   //--- String sortieren
   for (int i = n; i > 1; i--) {
       // groessten Wert nach hinten schieben
       for (int j = 0; j < i - 1; ++j) {
         if (strcmp(&a[j * m], &a[(j + 1) * m]) > 0 ) {
           memcpy(tmp, &a[(j + 1) * m], m);         //speichert &a[(j+1)*m] in tmp zwischen
           memcpy(&a[(j + 1) * m], &a[j * m], m);   //ueberschreibt &a[j*m] in a[(j+1)*m]
           memcpy(&a[j*m], tmp, m);                 //ueberschreibt tmp in &a[j*m]
         }
       }
   }

   //--- String ausgeben
   printf("Sortiertes Feld:\n");
   char* all = (char*) calloc(n * (strlen(argv[1]) + 1) + n-1, sizeof(char));
   strcat(all, &a[0]);
   for (int i = 1; i < n; ++i) {
     int x = i * m;
     if (strcmp(&a[x], &a[x-m]) == 0) {
       strcat(all, "*");
     } else {
       strcat(all, " ");
       strcat(all, &a[x]);
     }
   }
   printf("%s\n", all);

   //--- Speicher freigeben

   free(a);
   free(tmp);
   free(all);

   return 0;
 }
