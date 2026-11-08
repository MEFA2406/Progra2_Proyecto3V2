//
// Created by Manol on 11/5/2026.
//

#include "Mundo.h"

Mundo::Mundo() : posJugador(TAM/2, TAM/2),jugador(nullptr){
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            celdas[i][j] = nullptr;
        }
    }
}

Mundo::~Mundo() {
    limpiar();
}

std::mutex & Mundo::getMutex() const {
    return mtx;
}

void Mundo::setJugador(Jugador *jugador) {
    this->jugador = jugador;
}

Jugador * Mundo::getJugador() const {
    return jugador;
}

Posicion Mundo::getPosJugador() const {
    return posJugador;
}

void Mundo::setPosJugador(const Posicion &posicion) {
    posJugador = posicion;
}

bool Mundo::dentroLimites(const Posicion &posicion) const {
    return posicion.getFila() >= 0 && posicion.getFila() < TAM &&
           posicion.getColumna() >= 0 && posicion.getColumna() < TAM;
}

Entidad * Mundo::getEntidad(const Posicion &posicion) const {
    return dentroLimites(posicion) ? celdas[posicion.getFila()][posicion.getColumna()] : nullptr;
}

bool Mundo::puedeMover(const Posicion &posicion) const {
    return dentroLimites(posicion) && celdas[posicion.getFila()][posicion.getColumna()] == nullptr;
}

bool Mundo::estaLibre(const Posicion &posicion) const {
    return puedeMover(posicion) && posicion != posJugador;
}

int Mundo::contarEntidades() const {
    int total = 0;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (celdas[i][j] != nullptr) {
                total++;
            }
        }
    }
    return total;
}

Posicion Mundo::celdaLibreAleatoria() const {
    for (int i = 0; i < (TAM*TAM); i++) {
        Posicion p(rand() % TAM, rand() % TAM);
        if (estaLibre(p)) return p;
    }
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (estaLibre(Posicion(i, j))) return Posicion(i, j);
        }
    }
    return posJugador;
}

bool Mundo::agregar(Entidad *entidad) {
    Posicion pos = entidad->getPosicion();
    if (!estaLibre(pos)) return false;
    celdas[pos.getFila()][pos.getColumna()] = entidad;
    return true;
}

void Mundo::mover(Entidad *entidad, const Posicion &destino) {
    Posicion origen = entidad->getPosicion();
    if (celdas[origen.getFila()][origen.getColumna()] == entidad) {
        celdas[origen.getFila()][origen.getColumna()] = nullptr;
    }
    celdas[destino.getFila()][destino.getColumna()] = entidad;
    entidad->setPosicion(destino);
}

void Mundo::reubicar(Entidad *entidad) {
    mover(entidad, celdaLibreAleatoria());
}

void Mundo::eliminar(Entidad *entidad) {
    auto pos = entidad->getPosicion();
    if (celdas[pos.getFila()][pos.getColumna()] == entidad) {
        celdas[pos.getFila()][pos.getColumna()] = nullptr;
    }
    delete entidad;
}

void Mundo::limpiar() {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            delete celdas[i][j];
            celdas[i][j] = nullptr;
        }
    }
}

void Mundo::agregarEvento(const std::string &texto) {
    if (!eventos.empty()) {
        eventos += " | ";
        eventos += texto;
    }
}

void Mundo::limpiarEventos() {
    eventos.clear();
}

const std::string & Mundo::getEventos() const {
    return eventos;
}
