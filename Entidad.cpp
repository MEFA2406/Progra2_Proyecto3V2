//
// Created by Manol on 11/4/2026.
//

#include "Entidad.h"

Entidad::Entidad(const Posicion &pos) : pos(pos) {
}

Entidad::~Entidad() {
}

Posicion Entidad::getPosicion() const {
    return pos;
}

void Entidad::setPosicion(const Posicion &pos) {
    this->pos = pos;
}

int Entidad::valor() const {
    return 0;
}
