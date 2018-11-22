#
# Makefile
#
# Autor: H.Drachenfels
# Erstellt am: 28.9.2018
#

CC=gcc -g
CFLAGS = -g -W -Wall -std=$(STD) -pedantic
CPPCHECK = cppcheck --enable=all --std=$(STD)
STD=c11

TARGET = stringsort

.PHONY: all clean cppcheck

all: $(TARGET)

clean:
	$(RM) $(TARGET) $(TARGET).o

cppcheck: $(TARGET).c
	$(CPPCHECK) $<

