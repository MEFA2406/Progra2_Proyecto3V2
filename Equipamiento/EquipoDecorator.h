//
// Created by Manol on 11/5/2026.
//

#ifndef PROYECTO3_EQUIPODECORATOR_H
#define PROYECTO3_EQUIPODECORATOR_H

#include "IProteccion.h"

class EquipoDecorator : public IProteccion{
private:
    IProteccion* wrapped;
protected:
    virtual int bonus() const=0;
    virtual TipoEquipo tipoEquipo() const =0;
public:
    EquipoDecorator(IProteccion* wrapped);
    ~EquipoDecorator() override;
    EquipoDecorator(const EquipoDecorator&) = delete;
    EquipoDecorator& operator=(const EquipoDecorator&) = delete;

    int valor() const override;
    bool contiene(TipoEquipo tipo) const override;

};


#endif //PROYECTO3_EQUIPODECORATOR_H