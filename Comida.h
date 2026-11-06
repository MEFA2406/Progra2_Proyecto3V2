//
// Created by Manol on 11/5/2026.
//

#ifndef PROYECTO3_COMIDA_H
#define PROYECTO3_COMIDA_H
#include "Entidad.h"


class Comida : public Entidad{
private:
    int vida;
public:
    Comida(const Posicion&p, int vida);

    char simbolo() const override;
    TipoEntidad tipo() const override;
    int valor() const override;
};


#endif //PROYECTO3_COMIDA_H