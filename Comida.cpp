//
// Created by Manol on 11/5/2026.
//

#include "Comida.h"

Comida::Comida(const Posicion &p, int vida) : Entidad(p), vida(vida) {
}

char Comida::simbolo() const {
    return 'C';
}

TipoEntidad Comida::tipo() const {
    return COMIDA;
}

int Comida::valor() const {
    return vida;
}
