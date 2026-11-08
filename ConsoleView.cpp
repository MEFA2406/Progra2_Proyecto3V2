//
// Created by Manol on 11/7/2026.
//

#include "ConsoleView.h"
#include "Juego.h"
#include <iostream>

void ConsoleView::mostrarMenu() const {
    std::cout <<    "\n === MENU ===\n"
                    "1. Nueva partida\n"
                    "2. Jugar manual (W/A/S/D) Q para volver\n"
                    "3. Ejecutar nivel actual automaticamente\n"
                    "4. Guardar partida\n"
                    "5. Cargar partida\n"
                    "0. Salir\n" << std::flush;
}

void ConsoleView::actualizar(const Juego &juego) {
    const Mundo& mundo = juego.getMundo();
    const Jugador& jugador = juego.getJugador();
    Posicion posJugador = mundo.getPosJugador();

    std::cout   << "\033[2J\033[H";
    std::cout   << "Nivel " << juego.getNivel() << "/" << Juego::NIVELES
                << "   Movimientos del nivel: "<<juego.getMovNivel() <<"/" << Juego::Mov_por_nivel
                << "   Total: "<<juego.getMovTotal() << "/"
                << Juego::NIVELES * Juego::Mov_por_nivel << "\n";
    std::cout   << "Vida: "<<jugador.getVida() << "  Proteccion: "<<jugador.getProteccion()
                << "  ["
                << (jugador.tiene(EQ_CASCO) ? "Casco: ": "")
                << (jugador.tiene(EQ_BOTAS) ? "Botas: " : "")
                << (jugador.tiene(EQ_ARMADURA) ? "Armadura: " : "") <<"]\n\n";

    for (int i=0;i < Mundo::TAM; i++) {
        std::cout<<"  ";
        for (int j=0; j < Mundo::TAM; j++) {
            Posicion p(i,j);
            char simbolo ='.';
            if (p==posJugador) {
                simbolo = 'J';
            }else if (mundo.getEntidad(p)) {
                simbolo = mundo.getEntidad(p)->simbolo();
            }
            std::cout<<simbolo<<' ';
        }
        std::cout<<"\n";
    }
    std::cout<<"\n J=JUGADOR C=COMIDA E=CARNIVORO P=PLANTA H=CASCO B=BOTAS A=ARMADURA\n";
    if (mundo.getEventos().empty()) {
        std::cout<< ">> " << mundo.getEventos() << "\n";
    }
    if (juego.getEstado() == GANADO) {
        std::cout   <<"\n *** GANASTE! *** Sobreviviste los"
                    <<Juego::NIVELES * Juego::Mov_por_nivel <<" movimientos \n";
    }
    if (juego.getEstado() == PERDIDO) {
        std::cout   <<"\n*** PERDISTE *** tu vida llego a 0 \n";
    }
    std::cout<<std::flush;
}

void ConsoleView::mostrarMensaje(const std::string &texto) const {
    std::cout<<texto <<"\n";
}

bool ConsoleView::pedirOpcion(int &opcion) const {
    mostrarMenu();
    return static_cast<bool>(std::cin>>opcion);
}

bool ConsoleView::pedirTecla(char &tecla) const {
    std::cout <<"Mover (W/A/S/D, Q = menu): "<<std::flush;
    return static_cast<bool>(std::cin>>tecla);
}

bool ConsoleView::pedirSegundos(int &segundos) const {
    std::cout<<"Segundos entre movimientos (1,2 o 3): "<<std::flush;
    return static_cast<bool>(std::cin>>segundos);
}
