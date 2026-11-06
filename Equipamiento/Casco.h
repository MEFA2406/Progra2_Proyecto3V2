//
// Created by Manol on 11/5/2026.
//

#ifndef PROYECTO3_CASCO_H
#define PROYECTO3_CASCO_H

#include "Equipamiento.h"

class Casco : public Equipamiento {
public:
    Casco(const Posicion& p);
    char simbolo() const override;
    TipoEquipo tipoEquipo() const override;
    const char* nombre() const override;
    IProteccion* wrap(IProteccion* actual) const override;
};


#endif //PROYECTO3_CASCO_H