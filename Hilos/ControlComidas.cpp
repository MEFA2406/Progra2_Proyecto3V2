//
// Created by Manol on 11/8/2026.
//

#include "ControlComidas.h"


void ControlComidas::actualizar() {
    Lista<Entidad*> comidas;
    mundo.recolectar(COMIDA, comidas);

    auto it = comidas.iterator();
    while (it.hayMas()) {
        pasoAleatorio(it.siguiente());
    }
}

ControlComidas::ControlComidas(Mundo &mundo, ControlTurnos &control) : ControlHilos(mundo, control) {
}
