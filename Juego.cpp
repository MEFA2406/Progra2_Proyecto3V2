//
// Created by Manol on 11/7/2026.
//

#include <cstdio>
#include <string>
#include "Juego.h"
#include "Carnivoro.h"
#include "Fabrica.h"
#include "Equipamiento/Equipamiento.h"

Juego::Juego() : nivel(1), movNivel(0), movTotal(0), estado(JUGANDO) {
    mundo.setJugador(&jugador);
    //hilos
}

Juego::~Juego() {
    for (int i=0;i<NUM_HILOS;i++) {

    }
}

void Juego::agregarObservador(IObservador* observador) {
    observadores.agregar(observador);
}

void Juego::notificarObservador() const {
    auto it = observadores.iterator();
    while (it.hayMas()) {
        it.siguiente()->actualizar(*this);
    }
}

void Juego::nuevaPartida() {
    jugador.reiniciar();
    nivel=1;
    movNivel=0;
    movTotal=0;
    estado = JUGANDO;
    mundo.limpiarEventos();
    generarNivel();
    //notify;
}

void Juego::restaurar(int nuevoNivel, int movimientosNivel, int movimientosTotal) {

}

bool Juego::hayMovimientoValido() const {
    Posicion p = mundo.getPosJugador();
    for (int i =0;i<TOTAL_DIRECCIONES;i++) {
        Posicion n = p.vecina(static_cast<Direccion>(i));
        if (!mundo.dentroLimites(n)) continue;
        Entidad* e = mundo.getEntidad(n);
        if (!e || e->tipo() != PLANTA) return true;
    }
    return false;
}

bool Juego::mover(char tecla) {
    if (estado != JUGANDO) {
        return false;
    }
    Direccion d= ABAJO;
    if (teclaDireccion(tecla, d)) {
        mundo.limpiarEventos();
        mundo.agregarEvento("Tecla invalida! usa W / A / S / D ");
        //NOTIFY
        return false;
    }
    return moverDireccion(d);
}

void Juego::pasarTurno() {
    if (estado != JUGANDO) {
        return;
    }
    mundo.limpiarEventos();
    mundo.agregarEvento("No te puedes mover! pasa el turno.");
    avanzarTurno();
}

void Juego::ejecutarAutomatico(int segundos) {
    int nivelInicial = nivel;
    while (estado == JUGANDO && nivel == nivelInicial) {
        Direccion d = ABAJO;
        if (hayMovimientoValido()) {
            moverDireccion(d);
        }else {
            pasarTurno();
        }
        if (estado == JUGANDO && nivel == nivelInicial) {
            //sleep thread
        }
    }
}

const Mundo & Juego::getMundo() const {
    return mundo;
}

Mundo & Juego::getMundo() {
    return mundo;
}

const Jugador & Juego::getJugador() const {
    return jugador;
}

Jugador & Juego::getJugador() {
    return jugador;
}

int Juego::getNivel() const {
    return nivel;
}

int Juego::getMovNivel() const {
    return movNivel;
}

int Juego::getMovTotal() const {
    return movTotal;
}

EstadoJuego Juego::getEstado() const {
    return estado;
}

bool Juego::teclaDireccion(char tecla, Direccion &resultado) {
    switch (tecla) {
        case 'w': case'W': resultado = ARRIBA; return true;
        case 'a': case'A': resultado = IZQUIERDA; return true;
        case 's': case'S': resultado = ABAJO; return true;
        case 'd': case'D': resultado = DERECHA; return true;
        default: return false;
    }
}

void Juego::colocar(char simbolo, int cantidad, bool lejosDelJugador) {
    for (int i=0; i<cantidad; i++) {
        Posicion p = mundo.celdaLibreAleatoria();
        if (lejosDelJugador) {
            for (int j=0; j<50 && p.distanciaA(mundo.getPosJugador())<4 ;j++) {
                p = mundo.celdaLibreAleatoria();
            }
        }
        Entidad* e = Fabrica::crear(simbolo,p,nivel);
        if (e && !mundo.agregar(e)) {
            delete e;
        }
    }
}

void Juego::generarNivel() {
    mundo.limpiar();
    mundo.setPosJugador(Posicion(Mundo::TAM/2,Mundo::TAM/2));
    colocar('E',4,true);
    colocar('P',18);
    colocar('C',8);
    colocar('H',2);
    colocar('B',2);
    colocar('A',2);
}

void Juego::entrarEnCelda(const Posicion &destino) {
    Entidad* e = mundo.getEntidad(destino);
    mundo.setPosJugador(destino);
    if (!e){return;}

    switch (e->tipo()) {
        case COMIDA: {
            jugador.curar(e->valor());
            mundo.agregarEvento("Comiste: " + std::to_string(e->valor()) + "de vida");
            mundo.eliminar(e);
            break;
        }
        case EQUIPO: {
            auto pieza = static_cast<Equipamiento*>(e);
            if (jugador.equipar(*pieza)) {
                mundo.agregarEvento("Equipaste: " + pieza->nombre());
            }else {
                mundo.agregarEvento("Ya tenias" + pieza->nombre());
            }
            mundo.eliminar(e);
            break;
        }
        case CARNIVORO: {
            int ataque = jugador.recibirAtaque(static_cast<Carnivoro*>(e)->getAtaque());
            mundo.agregarEvento("Atacado por un carnivoro! - " + std::to_string(ataque) + "de vida" );
            mundo.reubicar(e);
            break;
        }
        default:break;

    }
}

bool Juego::moverDireccion(Direccion d) {
    if (estado != JUGANDO) return false;
    mundo.limpiarEventos();

    Posicion destino=mundo.getPosJugador().vecina(d);
    Entidad* e = mundo.getEntidad(destino);
    if (!mundo.dentroLimites(destino) || (e && e->tipo() == PLANTA)) {
        mundo.agregarEvento("Movimiento invalido: posicion bloquada");
        //
        return false;
    }
    {
        std::lock_guard<std::mutex> lk(mundo.getMutex());
        entrarEnCelda(destino);
    }
    avanzarTurno();
    return true;
}

void Juego::avanzarTurno() {
    movNivel++;
    movTotal++;
    if (jugador.getVida()<=0) {
        terminarPerdido();
        return;
    }
    //Hilos
    if (jugador.getVida()<=0) {
        terminarPerdido();
        return;
    }
    if (movNivel >= Mov_por_nivel) {
        if (nivel >= NIVELES) {
            estado = GANADO;
        }
        else {
            nivel++;
            movNivel =0;
            generarNivel();
            mundo.agregarEvento("NIVEL SUPERADO! Nuevo mapa, enemigos mas fuertes");
        }
    }
    //notify
}

void Juego::terminarPerdido() {
    estado = PERDIDO;
    //notify
}
