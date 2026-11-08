//
// Created by Manol on 11/7/2026.
//

#ifndef PROYECTO3_ESTRATEGIAPERSEGUIR_H
#define PROYECTO3_ESTRATEGIAPERSEGUIR_H

#include "EstrategiaAleatoria.h"

class EstrategiaPerseguir : public IEstrategiaMovimiento{
private:
    int radioVision;
    EstrategiaAleatoria estrategia;
public:
    EstrategiaPerseguir(int radio);
    Posicion siguiente(const Mundo& mundo,const Posicion& actual, const Posicion& objetivo) const override;
};


#endif //PROYECTO3_ESTRATEGIAPERSEGUIR_H