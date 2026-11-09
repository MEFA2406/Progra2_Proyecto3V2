//
// Created by Manol on 11/8/2026.
//

#ifndef PROYECTO3_CONTROLCOMIDAS_H
#define PROYECTO3_CONTROLCOMIDAS_H
#include "ControlHilos.h"


class ControlComidas : public ControlHilos {
protected:
    void actualizar() override;
public:
    ControlComidas(Mundo& mundo,ControlTurnos& control);
};


#endif //PROYECTO3_CONTROLCOMIDAS_H