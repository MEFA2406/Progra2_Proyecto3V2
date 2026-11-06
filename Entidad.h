//
// Created by Manol on 11/4/2026.
//

#ifndef PROYECTO3_ENTIDADES_H
#define PROYECTO3_ENTIDADES_H
#include "Posicion.h"

enum TipoEntidad {COMIDA,CARNIVORO,PLANTA,EQUIPO};

class Entidad {
protected:
    Posicion pos;
public:
    Entidad(const Posicion &pos);
    virtual ~Entidad();

    Posicion getPosicion() const;
    void setPosicion(const Posicion &pos);

    virtual char simbolo() const =0;
    virtual TipoEntidad tipo() const=0;
    virtual int valor() const;

};


#endif //PROYECTO3_ENTIDADES_H