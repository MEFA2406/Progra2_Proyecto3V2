//
// Created by Manol on 11/7/2026.
//

#ifndef PROYECTO3_JUEGO_H
#define PROYECTO3_JUEGO_H

#include "IObservador.h"
#include "Jugador.h"
#include "Lista.h"
#include "Mundo.h"
#include "Hilos/ControlHilos.h"

enum EstadoJuego {JUGANDO,GANADO,PERDIDO};

class Juego {
public:
    static constexpr int NIVELES =3;
    static constexpr int Mov_por_nivel = 10;
    static constexpr int NUM_HILOS = 4;

    Juego();
    ~Juego();
    Juego(const Juego&) = delete;
    Juego& operator=(const Juego&) = delete;

    void agregarObservador(IObservador* observador);
    void notificarObservador() const;

    void nuevaPartida();
    void restaurar(int nuevoNivel,int movimientosNivel,int movimientosTotal);
    bool hayMovimientoValido() const;
    bool mover(char tecla);
    void pasarTurno();
    void ejecutarAutomatico(int segundos);

    const Mundo& getMundo() const;
    Mundo& getMundo();
    const Jugador& getJugador() const;
    Jugador& getJugador();
    int getNivel() const;
    int getMovNivel() const;
    int getMovTotal() const;
    EstadoJuego getEstado() const;

private:
    Mundo mundo;
    Jugador jugador;
    Lista<IObservador*> observadores;
    ControlHilos* hilos[NUM_HILOS];
    ControlTurnos sync;

    int nivel;
    int movNivel;
    int movTotal;
    EstadoJuego estado;

    static bool teclaDireccion(char tecla, Direccion& resultado);

    void colocar(char simbolo,int cantidad,bool lejosDelJugador = false);
    void generarNivel();
    void entrarEnCelda(const Posicion& destino);
    bool moverDireccion(Direccion d);
    void avanzarTurno();
    void terminarPerdido();
};


#endif //PROYECTO3_JUEGO_H