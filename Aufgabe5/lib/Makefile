#Makefile
#Kommando-Variablen
CC = gcc
CFLAGS = -W -Wall -std=c11 -pedantic -fPIC
CPPFLAGS = -I.#sucht in dem aktuellen File
LIBNAME = aufgabe5#Bibliotheksname
LIBTYPE = a
RM = rm -f#remove sofort
AR = ar rs#ar: archiviere  r: fügt die inhalte in Archiv  s: fügt einen Index hinzu

#--------------------------------------- Hilfsvariablen
OBJECTS = fachnote.o liste.o
SOURCES = $(OBJECTS:.o=.c)#c-Dateien
HEADERS = $(OBJECTS:.o=.h)#h-dateien

#----------------------------------------- Musterregeln
%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<
#Compiliert

#---------------------------------------- Standardziele
.PHONY: all clean

all: lib$(LIBNAME).$(LIBTYPE)

clean:
	$(RM) $(OBJECTS) lib$(LIBNAME).a lib$(LIBNAME).so depend #löscht Objects, statische und dynamische Bibliothek

depend: $(SOURCES) $(HEADERS)#Abhängigkeit zwischen c. und h. dateien
	$(CC) $(CPPFLAGS) -MM $(SOURCES) > $@

lib$(LIBNAME).a: $(OBJECTS)#erstellen der statischen Bibliothek
	$(AR) $@ $^

lib$(LIBNAME).so: $(OBJECTS)#erstellen der dynamischen Bibliothek
	$(CC) $(CFLAGS) -shared -o $@ $^
#-------------------------------------- Abhaengigkeiten
include depend
