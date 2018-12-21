#ifndef FACHNOTE_H
#define FACHNOTE_H
#define FELDGROESSE 20

enum pruefungsArten {benotet, unbenotet};

struct fach_note {
    struct fach_note *next;
    struct fach_note *previous;
    char fachname[FELDGROESSE];

    enum pruefungsArten pfArt;

    union {
      int benotetePruefung;
      char leistung;
    };
};

typedef struct fach_note fach_note;
int einlesen (fach_note *fn);

void ausgeben(const fach_note *fn);
#endif
