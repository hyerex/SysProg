#include <stdlib.h>
#include <string.h>
#include "liste.h"

fach_note* einfuegen(fach_note *hl, fach_note *fn) {
    if (hl == NULL){
      hl = fn;
      hl->next = NULL;
    } else {
      hl->previous = fn;
      fn->next = hl;
      hl = fn;
      return hl;
    }
    return hl;
}

void schleife(fach_note *fn, void (*func) (const fach_note *fn)) {

  fach_note *h = fn;
  while (h != NULL) {
    func(h);
    h = h->next;
  }
}

fach_note* entfernen(fach_note *hl, fach_note **p) {

  *p = hl;
  hl = hl->next;

  if(hl != NULL) {
    hl->previous->next = NULL;
    hl->previous = NULL;
  }
  return hl;
}
