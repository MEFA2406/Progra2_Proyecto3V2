//
// Created by Manol on 11/5/2026.
//

#ifndef PROYECTO3_EQUIPAMIENTO_H
#define PROYECTO3_EQUIPAMIENTO_H

#include "../Entidad.h"
#include "IProteccion.h"

// El Equipo que se recoge en el mapa

class Equipamiento : public Entidad{
public:
    Equipamiento(const Posicion& posicion);

    TipoEntidad tipo() const override;

    virtual TipoEquipo tipoEquipo() const =0;
    virtual const char* nombre() const =0;
    virtual IProteccion* wrap(IProteccion* actual) const =0;
};


#endif //PROYECTO3_EQUIPAMIENTO_H