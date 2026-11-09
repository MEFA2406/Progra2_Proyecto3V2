//
// Created by Manol on 11/8/2026.
//

#ifndef PROYECTO3_APLICACION_H
#define PROYECTO3_APLICACION_H

#include "Juego.h"
#include "ConsoleView.h"

class Aplicacion {
private:
    ConsoleView vista;
    Juego juego;

    void modoManual();
    void modoAutomatico();
public:
    Aplicacion();
    int ejecutar();
};


#endif //PROYECTO3_APLICACION_H