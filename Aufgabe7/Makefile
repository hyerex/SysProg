#
# Makefile
#
# Autor: H.Drachenfels
# Erstellt am: 28.9.2018
#

CXX=g++ -g
CXXFLAGS = -W -Wall -std=$(STD) -pedantic
CPPCHECK = cppcheck --enable=all --std=$(STD)
STD=c++03

TARGET = stringsort

.PHONY: all clean cppcheck

all: $(TARGET)

clean:
	$(RM) $(TARGET) $(TARGET).o

cppcheck: $(TARGET).cpp
	$(CPPCHECK) $<
