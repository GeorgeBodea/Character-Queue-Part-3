//
// Created by George on 4/18/2020.
//

#ifndef TEMA_POO_2_NOD_DUBLU_H
#define TEMA_POO_2_NOD_DUBLU_H

#include <iostream>
#include <cstring>


class Nod_dublu {
    Nod_dublu *anterior;
    Nod_dublu *fiu1;
    Nod_dublu *fiu2;
    int prioritate;
    char *info;
public:
    explicit Nod_dublu(const char *text = "", int val = 0);

    ~Nod_dublu();

    Nod_dublu *get_fiu(int nr_fiu);

    void set_fiu(Nod_dublu *nod, int nr_fiu);

    int get_prioritate();

    char *get_info();

    void set_tata(Nod_dublu *tata);

    Nod_dublu *get_tata();

    Nod_dublu &operator=(const Nod_dublu &nod);

    Nod_dublu(const Nod_dublu &nod);

    friend void urca(Nod_dublu *nod_de_inserat, Nod_dublu *inceput);

    friend void swap_valori(Nod_dublu *nod1, Nod_dublu *nod2);

    friend std::ostream &operator<<(std::ostream &out, Nod_dublu &nod);

    friend std::istream &operator>>(std::istream &in, Nod_dublu &nod);
};


#endif //TEMA_POO_2_NOD_DUBLU_H
