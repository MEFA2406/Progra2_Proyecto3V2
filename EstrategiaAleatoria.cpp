//
// Created by Manol on 11/5/2026.
//

#include "EstrategiaAleatoria.h"
#include "Mundo.h"

Posicion EstrategiaAleatoria::siguiente(const Mundo &mundo, const Posicion &actual, const Posicion &objetivo) const {
    auto d = static_cast<Direccion>(rand() % TOTAL_DIRECCIONES);
    Posicion n = actual.vecina(d);
    return mundo.puedeMover(n) ? n : actual;
}
