//
// Created by Manol on 11/8/2026.
//

#ifndef PROYECTO3_LISTA_H
#define PROYECTO3_LISTA_H

#include "Iterator.h"
#include "Nodo.h"

template<class T>
class Lista {
private:
    Nodo<T>* primero;
    Nodo<T>* ultimo;
    int cant;
public:
    Lista() : primero(nullptr), ultimo(nullptr), cant(0) {}
    ~Lista() {limpiar();}
    Lista(const Lista&) = delete;
    Lista& operator=(const Lista&) = delete;

    void agregar(const T& valor) {
        auto nuevo = new Nodo<T>(valor);
        if (ultimo == nullptr) {
            primero = nuevo;
        }
        else {
            ultimo->setSiguiente(nuevo);
        }
        ultimo = nuevo;
        cant++;
    }

    bool eliminar(const T& valor) {
        Nodo<T>* anterior = nullptr;
        Nodo<T>* actual = primero;
        while (actual != nullptr) {
            if (actual->getDato() == valor) {
                if (anterior == nullptr) {
                    primero = actual->getSiguiente();
                }else {
                    anterior->setSiguiente(actual->getSiguiente());
                }
                if (actual == ultimo) {
                    ultimo = anterior;
                }
                delete actual;
                cant--;
                return true;
            }
            anterior = actual;
            actual = actual->getSiguiente();
        }
        return false;
    }

    void limpiar() {
        while (primero != nullptr) {
            Nodo<T>* actual = primero;
            primero = primero->getSiguiente();
            delete actual;
        }
        ultimo = nullptr;
        cant = 0;
    }

    int size() const {return cant;}

    Iterator<T> iterator() const {return Iterator<T>(primero);}
};

#endif //PROYECTO3_LISTA_H