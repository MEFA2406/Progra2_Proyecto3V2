//
// Created by Manol on 11/8/2026.
//

#ifndef PROYECTO3_CONTROLPLANTAS_H
#define PROYECTO3_CONTROLPLANTAS_H
#include "ControlHilos.h"


class ControlPlantas : public ControlHilos{
protected:
    void actualizar() override;
public:
    ControlPlantas(Mundo& mundo,ControlTurnos& control);
};


#endif //PROYECTO3_CONTROLPLANTAS_H