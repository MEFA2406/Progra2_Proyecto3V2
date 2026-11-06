//
// Created by Manol on 11/5/2026.
//

#ifndef PROYECTO3_ESTRATEGIAALEATORIA_H
#define PROYECTO3_ESTRATEGIAALEATORIA_H
#include "IEstrategiaMovimiento.h"


class EstrategiaAleatoria : public IEstrategiaMovimiento{
public:
    Posicion siguiente(const Mundo &mundo, const Posicion &actual, const Posicion &objetivo) const override;
};


#endif //PROYECTO3_ESTRATEGIAALEATORIA_H