//
// Created by George on 5/15/2020.
//



#ifndef TEMA_POO_2_COADA_DE_CARACTERE_H
#define TEMA_POO_2_COADA_DE_CARACTERE_H

#include <iostream>
#include <string>
#include "Nod.h"

typedef struct {
} Caractere;

template<typename tipCoada>
class Coada {
private:
    Nod *inceput, *sfarsit;
public:
    Coada(){
        inceput = NULL;
        sfarsit = NULL;
    }

    void adaugare();


    void adaugare(char informatie);

    void elimina();

    bool vida();

    Coada operator+(const Coada &coada_de_adaugat);


    Coada operator-(Coada &coada_de_adaugat);

    ~ Coada();

    friend std::ostream &operator<<(std::ostream &output, const Coada<Caractere> &coada);

    friend std::istream &operator>>(std::istream &input, Coada<Caractere> &coada);

    Coada& operator >> ( char informatie);
};
template<typename tipCoada>
void Coada<tipCoada>::adaugare() {
    Nod *curent = new Nod;
    if (inceput == NULL) {
        inceput = curent;
        sfarsit = curent;
    } else {
        sfarsit->seteaza_next(curent);
        sfarsit = curent;
    }
    sfarsit->seteaza_next(NULL);

}

template<typename tipCoada>
void Coada<tipCoada>::adaugare(char informatie) {
    Nod *curent = new Nod(informatie);
    if (inceput == NULL) {
        inceput = curent;
        sfarsit = curent;
    } else {
        sfarsit->seteaza_next(curent);
        sfarsit = curent;
    }
    sfarsit->seteaza_next(NULL);
}

template<typename tipCoada>
void Coada<tipCoada>::elimina() {
    Nod *curent = inceput;
    if (curent == sfarsit) {
        inceput = NULL;
        sfarsit = NULL;
    } else {
        inceput = inceput->interogare_next();
        delete curent;
    }
}

template<typename tipCoada>
bool Coada<tipCoada>::vida() {
    return inceput == NULL;
}

template<typename tipCoada>
Coada<tipCoada> Coada<tipCoada>::operator+(const Coada<tipCoada> &coada_de_adaugat) {
    Coada<tipCoada> coada_finala;
    Nod *adresa_ob1 = inceput;
    while (adresa_ob1 != NULL) // adaugam componentele din coada curenta
    {
        coada_finala.adaugare(adresa_ob1->interogare_info()); // Luam caracterul dau schimbam adresa
        adresa_ob1 = adresa_ob1->interogare_next();
    }
    Nod *adresa_ob2 = coada_de_adaugat.inceput;
    while (adresa_ob2 != NULL) {
        coada_finala.adaugare(adresa_ob2->interogare_info());
        adresa_ob2 = adresa_ob2->interogare_next();
    }
    return coada_finala;
}

template<typename tipCoada>
Coada<tipCoada>
Coada<tipCoada>::operator-(Coada<tipCoada> &coada_de_adaugat) // problema: se apeleaza destructorul cand avem =
{
    Coada<tipCoada> coada_finala;
    Nod *adresa_ob1 = inceput;
    Nod *adresa_ob2 = coada_de_adaugat.inceput;
    char aux1, aux2;
    while (adresa_ob1 != NULL && adresa_ob2 != NULL) {
        aux1 = adresa_ob1->interogare_info();
        aux2 = adresa_ob2->interogare_info();
        if (aux1 > aux2)
            coada_finala.adaugare(aux1);
        else
            coada_finala.adaugare(aux2);
        // this -> elimina();
        // coada_de_adaugat.elimina();
        adresa_ob1 = adresa_ob1->interogare_next();
        adresa_ob2 = adresa_ob2->interogare_next();
    }

    return coada_finala;
}

template<typename tipCoada>
Coada<tipCoada>::~Coada<tipCoada>() {

    Nod *curent = inceput;
    Nod *aux;
    while (curent != NULL) {
        aux = curent;
        curent = curent->interogare_next();
        delete aux;
    }
}


template<typename tipCoada>
Coada<tipCoada> &Coada<tipCoada>::operator>>(char informatie) {
    this->adaugare(informatie);
    return *this;
}




#endif //TEMA_POO_2_COADA_DE_CARACTERE_H
