//
// Created by Manol on 11/8/2026.
//

#include "ControlHilos.h"

void ControlHilos::ciclo() {
    int ultimo=0;
    while (controlTurnos.esperarTurno(ultimo)) {
        {
            lock_guard<mutex> lk(mundo.getMutex());
            actualizar();
        }
        controlTurnos.terminarTurno();
    }
}

void ControlHilos::pasoAleatorio(Entidad *e) {
    auto d = static_cast<Direccion>(rand() % TOTAL_DIRECCIONES);
    Posicion n= e->getPosicion().vecina(d);
    if (mundo.estaLibre(n)) {
        mundo.mover(e,n);
    }
}

ControlHilos::ControlHilos(Mundo &mundo, ControlTurnos& control) : mundo(mundo), controlTurnos(control) {
}

ControlHilos::~ControlHilos() {
    esperar();
}

void ControlHilos::iniciar() {
    hilo = thread(&ControlHilos::ciclo, this);
}

void ControlHilos::esperar() {
    if (hilo.joinable()) {
        hilo.join();
    }
}
