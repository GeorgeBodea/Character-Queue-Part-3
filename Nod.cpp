//
// Created by George on 5/15/2020.
//

#include "Nod.h"


Nod::Nod() {
    std::cin >> info;
    next = NULL;
}

Nod::Nod(char informatie) {
    info = informatie;
    next = NULL;
}

void Nod::seteaza_next(Nod *adresa) {
    next = adresa;
}

char Nod::interogare_info() {
    return info;
}

Nod *Nod::interogare_next() {
    return next;
}