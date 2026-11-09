//
// Created by Manol on 11/8/2026.
//

#ifndef PROYECTO3_CONTROLTURNOS_H
#define PROYECTO3_CONTROLTURNOS_H

#include <condition_variable>
#include <mutex>
using namespace std;

class ControlTurnos {
private:
    mutex mtx;
    condition_variable cvInicio;
    condition_variable cvFin;
    int turno;
    int pendiente;
    bool detener;
public:
    ControlTurnos();

    void iniciarTurno(int cantHilos);
    void esperarFin();
    void detenerTodo();
    bool esperarTurno(int& ultimo);
    void terminarTurno();
};


#endif //PROYECTO3_CONTROLTURNOS_H