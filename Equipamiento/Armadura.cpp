//
// Created by Manol on 11/5/2026.
//

#include "Armadura.h"
#include "ArmaduraDecorator.h"

Armadura::Armadura(const Posicion &p) : Equipamiento(p){
}

char Armadura::simbolo() const {
    return 'A';
}

TipoEquipo Armadura::tipoEquipo() const {
    return EQ_ARMADURA;
}

const char * Armadura::nombre() const {
    return "Armadura (+10)";
}

IProteccion * Armadura::wrap(IProteccion *actual) const {
    return new ArmaduraDecorator(actual);
}
