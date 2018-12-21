#
# Makefile
#
# Autor: H.Drachenfels
# Erstellt am: 25.7.2018
#----------------------------------- Kommando-Variablen
CC = gcc
CFLAGS = -W -Wall -std=c11 -pedantic -fpic
CPPFLAGS = -I$(LIBPATH)
LDFLAGS = -L$(LIBPATH)
#komplettes Verzeichnis nach libBibliotheke durchsucht
RM = rm -f
LIBNAME = aufgabe5#archiv name
LIBPATH = ../lib/#bibliotheksarchiv

#--------------------------------------- Hilfsvariablen
TARGET = notenspiegel
SOURCES = $(TARGET).c
HEADERS = $(LIBPATH)fachnote.h $(LIBPATH)liste.h

#----------------------------------------- Musterregeln
%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

#---------------------------------------- Standardziele
.PHONY: all clean#PsydoBefehle

all: $(TARGET)

clean:
	$(RM) $(TARGET) $(TARGET).o depend

depend: $(SOURCES) $(HEADERS)
	$(CC) $(CPPFLAGS) -MM $(SOURCES) > $@

#------------------------- Ziele zur Programmerstellung
$(TARGET): $(TARGET).o
	$(CC) $(CPPFLAGS) $(LDFLAGS) $< -l$(LIBNAME) -o $@

#-------------------------------------- Abhaengigkeiten
include depend
