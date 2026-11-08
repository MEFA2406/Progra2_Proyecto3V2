//
// Created by Manol on 11/7/2026.
//

#ifndef PROYECTO3_FABRICA_H
#define PROYECTO3_FABRICA_H

#include "Entidad.h"
#include "IEstrategiaMovimiento.h"

class Fabrica {
private:
    static IEstrategiaMovimiento* estrategiaPara(int nivel);
public:
    static Entidad* crear(char simbolo,const Posicion& p, int nivel=0, int valorComida=0);
};


#endif //PROYECTO3_FABRICA_H