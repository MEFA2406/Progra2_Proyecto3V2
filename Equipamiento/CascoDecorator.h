//
// Created by Manol on 11/5/2026.
//

#ifndef PROYECTO3_CASCODECORATOR_H
#define PROYECTO3_CASCODECORATOR_H

#include "EquipoDecorator.h"

class CascoDecorator : public EquipoDecorator{
protected:
    int bonus() const override;
    TipoEquipo tipoEquipo() const override;
public:
    CascoDecorator(IProteccion* wrapped);
};


#endif //PROYECTO3_CASCODECORATOR_H