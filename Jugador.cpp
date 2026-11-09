//
// Created by Manol on 11/5/2026.
//

#include "Jugador.h"
#include <algorithm>
#include "Equipamiento/Equipamiento.h"
#include "Equipamiento/ProteccionBase.h"

Jugador::Jugador() : vida(20), proteccion(new ProteccionBase()), desgaste(0) {
}

Jugador::~Jugador() {
    delete proteccion;
}

void Jugador::reiniciar() {
    vida =20;
    delete proteccion;
    proteccion = new ProteccionBase();
    desgaste = 0;
}

int Jugador::getVida() const{
    return vida;
}

void Jugador::setVida(int nuevaVida) {
    vida = nuevaVida;
}

int Jugador::getProteccion() const {
    return std::max(0, proteccion->valor() - desgaste);
}

bool Jugador::tiene(TipoEquipo tipo) const {
    return proteccion->contiene(tipo);
}

void Jugador::curar(int cantidad) {
    vida += cantidad;
}

int Jugador::recibirAtaque(int ataque) {
    int p = getProteccion();
    int absorbido = std::min(p, ataque);
    int dano = ataque - absorbido;
    desgaste += absorbido;
    vida = std::max(0, vida - dano);

    if (getProteccion() == 0 && proteccion->valor() > 0) {
        delete proteccion;
        proteccion = new ProteccionBase();
        desgaste = 0;
    }
    return dano;
}

bool Jugador::equipar(const Equipamiento& equipo) {
    if (proteccion->contiene(equipo.tipoEquipo())) return false;
    proteccion = equipo.wrap(proteccion);
    return true;
}
