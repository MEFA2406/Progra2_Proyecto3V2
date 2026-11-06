//
// Created by Manol on 11/5/2026.
//

#include "Equipamiento.h"

Equipamiento::Equipamiento(const Posicion &posicion) : Entidad(posicion) {
}

TipoEntidad Equipamiento::tipo() const {
    return EQUIPO;
}
