//
// Created by Manol on 11/8/2026.
//

#include "ControlCarnivoros.h"
#include "../Carnivoro.h"

void ControlCarnivoros::actualizar() {
    Posicion pj = mundo.getPosJugador();
    Lista<Entidad*> carnivoros;
    mundo.recolectar(CARNIVORO,carnivoros);

    auto it = carnivoros.iterator();
    while (it.hayMas()) {
        auto c= static_cast<Carnivoro*>(it.siguiente());
        Posicion sig = c->decidir(mundo,pj);
        if (sig == pj) {
            int ataque = mundo.getJugador()->recibirAtaque(c->getAtaque());
            mundo.agregarEvento("Un carnivoro te ataco! -" + to_string(ataque) + " de vida");
            mundo.reubicar(c);
        }else if (mundo.estaLibre(sig)) {
            mundo.mover(c,sig);
        }
    }
}

ControlCarnivoros::ControlCarnivoros(Mundo &mundo, ControlTurnos &control) : ControlHilos(mundo,control){
}
