//
// Created by Manol on 11/8/2026.
//

#include "ControlEquipamiento.h"

void ControlEquipamiento::actualizar() {
    Lista<Entidad*> equipo;
    mundo.recolectar(EQUIPO,equipo);
    auto it = equipo.iterator();
    while (it.hayMas()) {
        pasoAleatorio(it.siguiente());
    }
}

ControlEquipamiento::ControlEquipamiento(Mundo &mundo, ControlTurnos &control) : ControlHilos(mundo,control){
}
