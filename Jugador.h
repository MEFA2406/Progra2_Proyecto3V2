//
// Created by Manol on 11/5/2026.
//

#ifndef PROYECTO3_JUGADOR_H
#define PROYECTO3_JUGADOR_H

#include "Equipamiento/IProteccion.h"

class Equipamiento;

class Jugador {
private:
    int vida;
    IProteccion* proteccion;
public:
    Jugador();
    ~Jugador();
    Jugador(const Jugador&) = delete;
    Jugador& operator=(const Jugador&) = delete;

    void reiniciar();

    int getVida();
    void setVida(int nuevaVida);
    int getProteccion() const;
    bool tiene(TipoEquipo tipo) const;

    void curar(int cantidad);
    int recibirAtaque(int ataque);
    bool equipar(const Equipamiento* equipo);

};


#endif //PROYECTO3_JUGADOR_H