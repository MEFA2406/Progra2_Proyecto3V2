//
// Created by Manol on 11/5/2026.
//

#ifndef PROYECTO3_ARMADURADECORATOR_H
#define PROYECTO3_ARMADURADECORATOR_H
#include "EquipoDecorator.h"


class ArmaduraDecorator : public EquipoDecorator {
protected:
    int bonus() const override;
    TipoEquipo tipoEquipo() const override;
public:
    ArmaduraDecorator(IProteccion* wrapped);
};


#endif //PROYECTO3_ARMADURADECORATOR_H