//
// Created by Manol on 11/5/2026.
//

#ifndef PROYECTO3_IESTRATEGIAMOVIMIENTO_H
#define PROYECTO3_IESTRATEGIAMOVIMIENTO_H

#include "Posicion.h"

class Mundo;

class IEstrategiaMovimiento {
public:
    virtual ~IEstrategiaMovimiento() = default;
    virtual Posicion siguiente(const Mundo& mundo, const Posicion& actual, const Posicion& objetivo) const = 0;
};


#endif //PROYECTO3_IESTRATEGIAMOVIMIENTO_H