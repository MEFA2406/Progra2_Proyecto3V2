//
// Created by Manol on 11/8/2026.
//

#include "ControlTurnos.h"

ControlTurnos::ControlTurnos() :turno(0), pendiente(0),detener(false){
}

void ControlTurnos::iniciarTurno(int cantHilos) {
    lock_guard<mutex> lk(mtx);
    turno++;
    pendiente = cantHilos;
    cvInicio.notify_all();
}

void ControlTurnos::esperarFin() {
    unique_lock<mutex> lk(mtx);
    cvFin.wait(lk,[this](){return pendiente ==0;});
}

void ControlTurnos::detenerTodo() {
    lock_guard<mutex> lk(mtx);
    detener = true;
    cvInicio.notify_all();
}

bool ControlTurnos::esperarTurno(int &ultimo) {
    unique_lock<mutex> lk(mtx);
    cvInicio.wait(lk, [&] { return detener || turno > ultimo; });
    if (detener) {
        return false;
    }
    ultimo = turno;
    return true;
}

void ControlTurnos::terminarTurno() {
    lock_guard<mutex> lk(mtx);
    if (--pendiente == 0) {
        cvFin.notify_one();
    }
}
