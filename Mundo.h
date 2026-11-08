//
// Created by Manol on 11/5/2026.
//

#ifndef PROYECTO3_MUNDO_H
#define PROYECTO3_MUNDO_H

#include <mutex>
#include <string>

#include "Entidad.h"
#include "Jugador.h"
#include "Posicion.h"

class Mundo {
public:
    static constexpr int TAM = 15;
    Mundo();
    ~Mundo();
    Mundo(const Mundo&) = delete;
    Mundo& operator=(const Mundo&) = delete;

    std::mutex& getMutex() const;

    void setJugador(Jugador* jugador);
    Jugador* getJugador() const;
    Posicion getPosJugador() const;
    void setPosJugador(const Posicion& posicion);

    bool dentroLimites(const Posicion& posicion) const;
    Entidad* getEntidad(const Posicion& posicion) const;
    bool puedeMover(const Posicion& posicion) const;
    bool estaLibre(const Posicion& posicion) const;
    int contarEntidades() const;
    Posicion celdaLibreAleatoria() const;

    bool agregar(Entidad* entidad);
    void mover(Entidad* entidad, const Posicion& destino);
    void reubicar(Entidad* entidad);
    void eliminar(Entidad* entidad);
    void limpiar();

    void agregarEvento(const std::string& texto);
    void limpiarEventos();
    const std::string& getEventos() const;

private:
    Entidad* celdas[TAM][TAM];
    Posicion posJugador;
    Jugador* jugador;
    mutable std::mutex mtx;
    std::string  eventos;
public:
};


#endif //PROYECTO3_MUNDO_H