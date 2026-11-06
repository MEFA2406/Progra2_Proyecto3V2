//
// Created by Manol on 11/5/2026.
//

#ifndef PROYECTO3_IPROTECCION_H
#define PROYECTO3_IPROTECCION_H

enum TipoEquipo{EQ_CASCO,EQ_BOTAS,EQ_ARMADURA};

class IProteccion {
public:
    virtual ~IProteccion() = default;
    virtual int valor() const =0;
    virtual bool contiene(TipoEquipo tipo) const =0;
};


#endif //PROYECTO3_IPROTECCION_H