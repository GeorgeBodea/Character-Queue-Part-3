//
// Created by George on 5/15/2020.
//

#include "Coada_de_caractere.h"


std::ostream &operator<<(std::ostream &output, const Coada<Caractere> &coada) {
    Nod *curent = coada.inceput;
    while (curent != NULL) {
        output << curent->interogare_info() << ' '; // Inainte: curent->afisare_informatie(); Problema.
        curent = curent->interogare_next();
    }
    return output;
}

std::istream &operator>>(std::istream &input, Coada<Caractere> &coada) {
    char caracter;
    input >> caracter;
    coada.adaugare(caracter);
    return input; // Pentru a folosii >> de mai multe ori pe aceasi linie
}