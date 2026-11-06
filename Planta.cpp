//
// Created by Manol on 11/5/2026.
//

#include "Planta.h"

Planta::Planta(const Posicion &p) : Entidad(p){
}

char Planta::simbolo() const {
    return 'P';
}

TipoEntidad Planta::tipo() const {
    return PLANTA;
}
