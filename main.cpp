#include <iostream>
#include <fstream>
#include "Coada_prioritati.h"
#include "Coada_de_caractere.h"

int main() {
    std::ifstream f("date.in");
    int nr;
    f >> nr;
    Coada<Prioritati> p;
    for (int i = 0; i < nr; i++)
        f >> p;
    while (p.isEmpty() == false) {
        std::cout << p.get_inceput()->get_prioritate() << " " << p;
        p.pop();
        std::cout << p.isEmpty() << '\n';
    }

    f.close();

    Coada<Caractere> coada1, coada2, coada3, coada4;
    coada1 >> 'a' >> 'b';
    coada2.adaugare('c');
    std::cout << coada1 + coada2 << '\n';
    std::cout << "coada2 - coada1 = " <<  coada2 - coada1 << '\n';
    std::cout << "Dati un caracter: ";
    std::cin >> coada4;
    std::cout <<  coada4;
    std::cout << coada4.vida();
    return 0;
}
