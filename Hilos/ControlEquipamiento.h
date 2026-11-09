//
// Created by Manol on 11/8/2026.
//

#ifndef PROYECTO3_CONTROLEQUIPAMIENTO_H
#define PROYECTO3_CONTROLEQUIPAMIENTO_H
#include "ControlHilos.h"


class ControlEquipamiento : public ControlHilos{
protected:
    void actualizar() override;
public:
    ControlEquipamiento(Mundo& mundo,ControlTurnos& control);
};


#endif //PROYECTO3_CONTROLEQUIPAMIENTO_H