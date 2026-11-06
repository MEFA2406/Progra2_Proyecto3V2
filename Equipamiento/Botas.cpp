//
// Created by Manol on 11/5/2026.
//

#include "Botas.h"
#include "BotasDecorator.h"

Botas::Botas(const Posicion &p) : Equipamiento(p){
}

char Botas::simbolo() const {
    return 'B';
}

TipoEquipo Botas::tipoEquipo() const {
    return EQ_BOTAS;
}

const char * Botas::nombre() const {
    return "Botas (+3)";
}

IProteccion * Botas::wrap(IProteccion *actual) const {
    return new BotasDecorator(actual);
}
