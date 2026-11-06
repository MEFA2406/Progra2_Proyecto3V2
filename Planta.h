//
// Created by Manol on 11/5/2026.
//

#ifndef PROYECTO3_PLANTA_H
#define PROYECTO3_PLANTA_H
#include "Entidad.h"


class Planta : public Entidad{
public:
    Planta(const Posicion& p);
    char simbolo() const override;
    TipoEntidad tipo() const override;
};


#endif //PROYECTO3_PLANTA_H