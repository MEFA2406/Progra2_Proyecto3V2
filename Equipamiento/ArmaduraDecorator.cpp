//
// Created by Manol on 11/5/2026.
//

#include "ArmaduraDecorator.h"

int ArmaduraDecorator::bonus() const {
    return 10;
}

TipoEquipo ArmaduraDecorator::tipoEquipo() const {
    return EQ_ARMADURA;
}

ArmaduraDecorator::ArmaduraDecorator(IProteccion *wrapped) : EquipoDecorator(wrapped){
}
