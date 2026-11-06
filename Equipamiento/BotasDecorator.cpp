//
// Created by Manol on 11/5/2026.
//

#include "BotasDecorator.h"

int BotasDecorator::bonus() const {
    return 3;
}

TipoEquipo BotasDecorator::tipoEquipo() const {
    return EQ_BOTAS;
}

BotasDecorator::BotasDecorator(IProteccion *wrapped) : EquipoDecorator(wrapped) {
}
