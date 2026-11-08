//
// Created by Manol on 11/8/2026.
//

#ifndef PROYECTO3_NODO_H
#define PROYECTO3_NODO_H

template <typename T>
class Nodo {
private:
    T dato;
    Nodo<T>* siguiente;
public:
    explicit Nodo(const T& valor) : dato(valor), siguiente(nullptr) {}
    Nodo(const Nodo&) = delete;
    Nodo& operator=(const Nodo&) = delete;
    ~Nodo(){
        if(std::is_pointer_v<T>() ) {
            delete dato;
        }
    }
    T& getDato() { return dato; }
    const T& getDato() const { return dato; }
    Nodo<T>* getSiguiente() { return siguiente; }
    void setSiguiente(Nodo<T>* sig) { siguiente = sig; }

};

#endif //PROYECTO3_NODO_H