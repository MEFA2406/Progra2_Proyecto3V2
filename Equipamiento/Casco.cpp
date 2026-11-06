//
// Created by Manol on 11/5/2026.
//

#include "Casco.h"

#include "CascoDecorator.h"
#include "CascoDecorator.h"

Casco::Casco(const Posicion &p) : Equipamiento(p){
}

char Casco::simbolo() const {
    return 'H';
}

TipoEquipo Casco::tipoEquipo() const {
    return EQ_CASCO;
}

const char * Casco::nombre() const {
    return "Casco (+5)";
}

IProteccion * Casco::wrap(IProteccion *actual) const {
    return new CascoDecorator(actual);
}
