//
// Created by Manol on 11/8/2026.
//

#ifndef PROYECTO3_CONTROLHILOS_H
#define PROYECTO3_CONTROLHILOS_H

#include <thread>
#include "../Mundo.h"
#include "../ControlTurnos.h"

class ControlHilos {
private:
    void ciclo();
protected:
    Mundo& mundo;
    thread hilo;
    ControlTurnos& controlTurnos;

    virtual void actualizar()=0;
    void pasoAleatorio(Entidad* e);
public:
    ControlHilos(Mundo& mundo,ControlTurnos& control);
    virtual ~ControlHilos();
    ControlHilos(const ControlHilos&) = delete;
    ControlHilos& operator=(const ControlHilos&) = delete;
    void iniciar();
    void esperar();
};


#endif //PROYECTO3_CONTROLHILOS_H