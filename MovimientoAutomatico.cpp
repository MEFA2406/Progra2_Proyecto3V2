//
// Created by Manol on 11/7/2026.
//

#include "MovimientoAutomatico.h"
#include "Carnivoro.h"
#include "Equipamiento/Equipamiento.h"

bool MovimientoAutomatico::esDeseado(const Entidad *e, const Jugador &jugador) {
    if (e->tipo() == COMIDA) {
        return true;
    }
    if (e->tipo() == EQUIPO) {
        return !jugador.tiene(static_cast<const Equipamiento*>(e)->tipoEquipo());
    }
    return false;
}

bool MovimientoAutomatico::esAmenaza(const Entidad *e, const Jugador &jugador) {
    return e != nullptr && e->tipo() == CARNIVORO &&
        static_cast<const Carnivoro*>(e)->getAtaque() > jugador.getProteccion();
}

int MovimientoAutomatico::distanciaObjetivo(const Mundo &mundo, const Jugador &jugador, const Posicion &pos) {
    int mejor = 2* Mundo::TAM;
    for (int i = 0; i < Mundo::TAM; i++) {
        for (int j = 0; j < Mundo::TAM; j++) {
            Posicion p(i,j);
            Entidad* e = mundo.getEntidad(p);
            if (e == nullptr || !esDeseado(e,jugador)) {
                continue;
            }
            int d = pos.distanciaA(p);
            if (d < mejor) {
                mejor = d;
            }
        }
    }
    return mejor;
}

int MovimientoAutomatico::peligro(const Mundo &mundo, const Jugador &jugador, const Posicion &pos) {
    int total =0;
    if (esAmenaza(mundo.getEntidad(pos), jugador)) {
        total += 8;
    }
    for (int i = 0; i < TOTAL_DIRECCIONES; i++) {
        if (esAmenaza(mundo.getEntidad(pos.vecina(static_cast<Direccion>(i))), jugador)) {
            total += 8;
        }
    }
    return total;
}

bool MovimientoAutomatico::decidir(const Mundo &mundo, const Jugador &jugador, Direccion &resultado) {
    bool hayMovimiento = false;
    int mejorPuntaje = -999999;
    Posicion pos = mundo.getPosJugador();
    for (int i = 0; i < TOTAL_DIRECCIONES; i++) {
        Posicion n= pos.vecina(static_cast<Direccion>(i));
        if (!mundo.dentroLimites(n)) {
            continue;
        }
        Entidad* e = mundo.getEntidad(n);
        if (e && e->tipo() == PLANTA) {
            continue;
        }
        int puntos = rand() % 2;
        if (e) {
            if (e->tipo() == COMIDA) {
                puntos +=40 + (jugador.getVida() < 12 ? 20:0);
            }else if (e->tipo() == EQUIPO && esDeseado(e,jugador)) {
                puntos +=45;
            }else if (e->tipo() == CARNIVORO) {
                int ataque = static_cast<const Carnivoro*>(e)->getAtaque() - jugador.getProteccion();
                puntos -= (ataque > 0) ? 60 + ataque *4 :5;
            }
        }
        puntos += 2*Mundo::TAM - distanciaObjetivo(mundo, jugador, n);
        puntos -= peligro(mundo,jugador,n);

        if (puntos > mejorPuntaje) {
            mejorPuntaje = puntos;
            resultado = static_cast<Direccion>(i);
            hayMovimiento = true;
        }
    }
    return hayMovimiento;
}
