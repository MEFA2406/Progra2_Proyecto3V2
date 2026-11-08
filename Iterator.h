//
// Created by Manol on 11/8/2026.
//

#ifndef PROYECTO3_ITERATOR_H
#define PROYECTO3_ITERATOR_H

#include "Nodo.h"

template<class T>
class Iterator {
private:
    Nodo<T>* actual;
public:
    explicit Iterator(Nodo<T>* actual) : actual(actual) {}

    bool hayMas() const {return actual!=nullptr;}

    T& siguiente() {
        T& dato = actual->getDato();
        actual = actual->getSiguiente();
        return dato;
    }
};

#endif //PROYECTO3_ITERATOR_H