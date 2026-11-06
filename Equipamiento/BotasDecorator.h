//
// Created by Manol on 11/5/2026.
//

#ifndef PROYECTO3_BOTASDECORATOR_H
#define PROYECTO3_BOTASDECORATOR_H
#include "EquipoDecorator.h"


class BotasDecorator : public EquipoDecorator {
protected:
    int bonus() const override;
    TipoEquipo tipoEquipo() const override;
public:
    BotasDecorator(IProteccion* wrapped);
};


#endif //PROYECTO3_BOTASDECORATOR_H