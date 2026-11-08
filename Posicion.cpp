//
// Created by Manol on 11/4/2026.
//

#include "Posicion.h"

Posicion::Posicion(int x, int y) :fila(x),columna(y) {
}

int Posicion::getFila() const {
    return fila;
}

int Posicion::getColumna() const {
    return columna;
}

bool Posicion::operator==(const Posicion &p) const {
    return fila == p.fila && columna == p.columna;
}

int Posicion::distanciaA(const Posicion & otra) const {
    int df = fila - otra.fila; //df = distanciaFila
    int dc = columna - otra.columna;
    if (df < 0) df = -df;
    if (dc < 0) dc = -dc;
    return df + dc;
}

Posicion Posicion::vecina(Direccion direccion) const {
    switch (direccion) {
        case ARRIBA: return Posicion(fila-1, columna);
        case ABAJO: return Posicion(fila+1, columna);
        case IZQUIERDA: return Posicion(fila, columna -1);
        case DERECHA: return Posicion(fila, columna +1);
        default: return *this;
    }
}
