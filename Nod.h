//
// Created by George on 5/15/2020.
//

#ifndef TEMA_POO_2_NOD_H
#define TEMA_POO_2_NOD_H

#include <iostream>
class Nod {
private:
    char info;
    Nod *next;
public:
    Nod();

    explicit Nod(char informatie);

    void seteaza_next(Nod *adresa);

    char interogare_info();

    Nod *interogare_next();

};



#endif //TEMA_POO_2_NOD_H
