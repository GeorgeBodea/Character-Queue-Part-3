//
// Created by George on 4/18/2020.
//

#include "Coada_prioritati.h"

Coada<Prioritati>::Coada() {
    numar_elemente = 0;
    inceput = nullptr;
}

void Coada<Prioritati>::ultimul_element(Nod_dublu *&tata,
                                       int &last_move) { // Trebuie sa stim tatal si ultima miscare inainte sa adaugam un nod.

    tata = inceput;
    // Daca respectiva coada are doar nodul vid, atunci tatal e nodul vid
    //altfel luam  radacina cu nodul dublu si incepem sa parcurgem arborele

    last_move = 1;
    if (tata != nullptr) {
        Nod_dublu *nod_curent = inceput;
        int v[32];
        int poz = 0;
        int cnr = numar_elemente;
        while (cnr > 1) {
            v[poz++] = cnr & 1;
            cnr >>= 1;
        }
        while (poz > 0) {
            poz--;
            tata = nod_curent;
            if (v[poz] == 0) {
                nod_curent = nod_curent->get_fiu(1);
                last_move = 1;
            } else {
                nod_curent = nod_curent->get_fiu(2);
                last_move = 2;
            }
        }
        /*
        int s = 1 << ((int) log2(
                numar_elemente)); // parte intreaga log 2 n ??? POSIBILITATE REDUSA avem numar_elemente 4, s=>4 .
        int p2 = s >> 1; // am impartit cu 2 pentru ca prima cifra nu ne spune nimic despre subarbore

        while (nod_curent != nullptr && s != numar_elemente) {
            if (s + p2 <= numar_elemente) {
                nod_curent = nod_curent->get_fiu(2);
                s += p2;
                last_move = 2;
            } else {
                nod_curent = nod_curent->get_fiu(1);
                last_move = 1;
            }
            if (nod_curent != nullptr && s != numar_elemente)
                tata = nod_curent;
            p2 >>= 1;
        }*/
    }
}

std::istream &operator>>(std::istream &input, Coada<Prioritati> &coada) {
    char *info = new char[256];
    int prio;
    input >> info >> prio;
    coada.insereaza(info, prio);
    delete[] info;
    return input;
}

std::ostream &operator<<(std::ostream &output, Coada<Prioritati> &coada) {
    output << coada.top() << "\n";
    return output;
}

void Coada<Prioritati>::insereaza(const char *info, int prioritate) {

    numar_elemente++;

    // De exemplu 13 = 8 + 4 + 1 si daca facem impartirea cifre 1 care ii corespunde lui 8 in scrierea lui 13 e inutila
    Nod_dublu *tata;
    int last_move;
    ultimul_element(tata,
                    last_move); // tata va primi informatia despre care este nodul subarborelui unde trb adaugat ultimul nod,
    //iar last_move unde trebuie adaugat nodul (stanga sau dreapta)

    Nod_dublu *nod_de_inserat = new Nod_dublu(info, prioritate);
    if (tata == nullptr)
        inceput = nod_de_inserat;
    else
        tata->set_fiu(nod_de_inserat, last_move);
    nod_de_inserat->set_tata(tata);
    ///interschimbam cu tatal cat timp avem prioritate mai mare in nod curent
    urca(nod_de_inserat, inceput);
}

char *Coada<Prioritati>::top() {
    try {
        if (numar_elemente == 0)
            throw std::bad_function_call();
        Nod_dublu *nod = inceput;
        return nod->get_info();
    }
    catch (const std::bad_function_call &e) {
        return const_cast<char *>(e.what());
    }
}

void Coada<Prioritati>::pop() {
    try {

        if (numar_elemente == 1) {
            delete inceput;
            inceput = nullptr;
            numar_elemente--;
        } else if (numar_elemente > 1) {
            Nod_dublu *tata;
            int last_move;
            ultimul_element(tata, last_move);
            Nod_dublu *nod_curent = inceput;

            *nod_curent = *(tata->get_fiu(last_move));
            delete tata->get_fiu(last_move);
            tata->set_fiu(nullptr, last_move);
            coboara(nod_curent);
            numar_elemente--;
        } else
            throw std::bad_function_call();
    }
    catch (const std::bad_function_call &e) {
        std::cout << e.what();
    }
}

void Coada<Prioritati>::coboara(Nod_dublu *nod) {
    if (nod->get_fiu(2) != nullptr) {
        if (nod->get_fiu(1)->get_prioritate() > nod->get_fiu(2)->get_prioritate()) {
            if (nod->get_fiu(1)->get_prioritate() > nod->get_prioritate()) {
                swap_valori(nod, nod->get_fiu(1));
                coboara(nod->get_fiu(1));
            }
        } else {
            if (nod->get_fiu(2)->get_prioritate() > nod->get_prioritate()) {
                swap_valori(nod, nod->get_fiu(2));
                coboara(nod->get_fiu(2));
            }
        }
    } else if (nod->get_fiu(1) != nullptr) {
        if (nod->get_fiu(1)->get_prioritate() > nod->get_prioritate()) {
            swap_valori(nod, nod->get_fiu(1));
            coboara(nod->get_fiu(1));
        }
    }
}

Coada<Prioritati>::~Coada() {
    empty();
}

void Coada<Prioritati>::empty() {
    while (isEmpty() == false) {
        pop();
    }
}

bool Coada<Prioritati>::isEmpty() {
    return inceput == nullptr;
}

Coada<Prioritati> &Coada<Prioritati>::operator=(const Coada<Prioritati> &coada_noua) {
    empty(); // empty lasa doar radacina simplu
    numar_elemente = coada_noua.numar_elemente;
    inceput = deep_copy(coada_noua.inceput, inceput);

    return *this;
}

Nod_dublu *Coada<Prioritati>::deep_copy(Nod_dublu *nod_de_copiat, const Nod_dublu *tata) {
    if (nod_de_copiat == nullptr)
        return nullptr;
    else {
        Nod_dublu *nod_curent = new Nod_dublu(*nod_de_copiat);
        nod_curent->set_tata(const_cast<Nod_dublu *>(tata));
        nod_curent->set_fiu(deep_copy(nod_de_copiat->get_fiu(1), nod_curent), 1);
        nod_curent->set_fiu(deep_copy(nod_de_copiat->get_fiu(2), nod_curent), 2);
        return nod_curent;
    }
}

Nod_dublu *Coada<Prioritati>::get_inceput() {
    return inceput;
}