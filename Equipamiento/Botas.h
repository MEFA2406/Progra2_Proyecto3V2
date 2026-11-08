//
// Created by Manol on 11/5/2026.
//

#ifndef PROYECTO3_BOTAS_H
#define PROYECTO3_BOTAS_H
#include "Equipamiento.h"


class Botas : public Equipamiento {
public:
    Botas(const Posicion& p);
    char simbolo() const override;
    TipoEquipo tipoEquipo() const override;
    const std::string nombre() const override;
    IProteccion* wrap(IProteccion *actual) const override;
};


#endif //PROYECTO3_BOTAS_H