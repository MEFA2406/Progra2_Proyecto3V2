//
// Created by Manol on 11/5/2026.
//

#include "EquipoDecorator.h"

EquipoDecorator::EquipoDecorator(IProteccion *wrapped) : wrapped(wrapped) {
}

EquipoDecorator::~EquipoDecorator() {
    delete wrapped;
}

int EquipoDecorator::valor() const {
    return wrapped->valor() + bonus();
}

bool EquipoDecorator::contiene(TipoEquipo tipo) const {
    return tipo == tipoEquipo() || wrapped->contiene(tipo);
}
