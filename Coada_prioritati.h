//
// Created by George on 4/18/2020.
//

#ifndef TEMA_POO_2_COADA_PRIORITATI_H
#define TEMA_POO_2_COADA_PRIORITATI_H

#include "Nod_dublu.h"
#include "Coada_de_caractere.h"
#include <cmath>
#include <functional>

typedef struct {
} Prioritati;

template<>
class Coada<Prioritati> {
private:
    Nod_dublu *inceput;
    int numar_elemente;

    void ultimul_element(Nod_dublu *&tata, int &last_move);

    Nod_dublu *deep_copy(Nod_dublu *nod_de_copiat, const Nod_dublu *tata);

    void coboara(Nod_dublu *nod);

public:
    Coada();

    void insereaza(const char *info, int prioritate);

    char *top();

    void pop();

    Nod_dublu *get_inceput();

    bool isEmpty();

    void empty();

    Coada &operator=(const Coada &coada_noua);

    ~Coada();

    friend std::istream &operator>>(std::istream &input, Coada<Prioritati> &coada);

    friend std::ostream &operator<<(std::ostream &output, Coada<Prioritati> &coada);
};

#endif //TEMA_POO_2_COADA_PRIORITATI_H
