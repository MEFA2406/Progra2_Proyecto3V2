//
// Created by Manol on 11/5/2026.
//

#include "Jugador.h"
#include "Equipamiento/Equipamiento.h"
#include "Equipamiento/ProteccionBase.h"

Jugador::Jugador() : vida(20), proteccion(new ProteccionBase()) {
}

Jugador::~Jugador() {
    delete proteccion;
}

void Jugador::reiniciar() {
    vida =20;
    delete proteccion;
    proteccion = new ProteccionBase();
}

int Jugador::getVida() const{
    return vida;
}

void Jugador::setVida(int nuevaVida) {
    vida = nuevaVida;
}

int Jugador::getProteccion() const {
    return proteccion->valor();
}

bool Jugador::tiene(TipoEquipo tipo) const {
    return proteccion->contiene(tipo);
}

void Jugador::curar(int cantidad) {
    vida += cantidad;
}

int Jugador::recibirAtaque(int ataque) {
    int p = proteccion->valor();
    if (p >= ataque) {
        return 0;
    }
    int dano = ataque -p;
    vida -= dano;
    if (p > 0) {
        delete proteccion;
        proteccion = new ProteccionBase();
    }
    return dano;
}

bool Jugador::equipar(const Equipamiento& equipo) {
    if (proteccion->contiene(equipo.tipoEquipo())) return false;
    proteccion = equipo.wrap(proteccion);
    return true;
}
