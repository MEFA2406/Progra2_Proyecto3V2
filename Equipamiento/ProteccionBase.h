//
// Created by Manol on 11/5/2026.
//

#ifndef PROYECTO3_PROTECCIONBASE_H
#define PROYECTO3_PROTECCIONBASE_H
#include "IProteccion.h"


class ProteccionBase : public IProteccion {
public:
    int valor() const override;
    bool contiene(TipoEquipo tipo) const override;
};


#endif //PROYECTO3_PROTECCIONBASE_H