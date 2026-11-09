//
// Created by Manol on 11/8/2026.
//

#ifndef PROYECTO3_CONTROLCARNIVOROS_H
#define PROYECTO3_CONTROLCARNIVOROS_H
#include "ControlHilos.h"


class ControlCarnivoros : public ControlHilos{
protected:
    void actualizar() override;
public:
    ControlCarnivoros(Mundo& mundo,ControlTurnos& control);
};


#endif //PROYECTO3_CONTROLCARNIVOROS_H