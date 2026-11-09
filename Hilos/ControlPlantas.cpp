//
// Created by Manol on 11/8/2026.
//

#include "ControlPlantas.h"

void ControlPlantas::actualizar() {
    Lista<Entidad*> plantas;
    mundo.recolectar(PLANTA, plantas);
    auto it = plantas.iterator();
    while (it.hayMas()) {
        Entidad* planta = it.siguiente();
        if (rand() % 100 <30) {
            mundo.reubicar(planta);
        }
    }
}

ControlPlantas::ControlPlantas(Mundo &mundo, ControlTurnos &control) : ControlHilos(mundo, control){
}
