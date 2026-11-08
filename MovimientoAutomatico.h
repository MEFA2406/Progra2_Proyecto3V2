//
// Created by Manol on 11/7/2026.
//

#ifndef PROYECTO3_MOVIMIENTOAUTOMATICO_H
#define PROYECTO3_MOVIMIENTOAUTOMATICO_H

#include "Jugador.h"
#include "Mundo.h"

class MovimientoAutomatico {
private:
    static bool esDeseado(const Entidad* e,const Jugador& jugador);
    static bool esAmenaza(const Entidad* e,const Jugador& jugador);
    static int distanciaObjetivo(const Mundo& mundo,const Jugador& jugador,const Posicion& pos);
    static int peligro(const Mundo& mundo,const Jugador& jugador,const Posicion& pos);
public:
    static bool decidir(const Mundo& mundo, const Jugador& jugador, Direccion& resultado);
};


#endif //PROYECTO3_MOVIMIENTOAUTOMATICO_H