//
// Created by Manol on 11/5/2026.
//

#include "CascoDecorator.h"

int CascoDecorator::bonus() const {
    return 5;
}

TipoEquipo CascoDecorator::tipoEquipo() const {
    return EQ_CASCO;
}

CascoDecorator::CascoDecorator(IProteccion *wrapped) : EquipoDecorator(wrapped){
}
