//
// Created by Manol on 11/5/2026.
//

#include "Carnivoro.h"

Carnivoro::Carnivoro(const Posicion &posicion, int ataque, IEstrategiaMovimiento *estrategia) : Entidad(posicion), ataque(ataque), estrategia(estrategia) {
}

Carnivoro::~Carnivoro() {
    delete estrategia;
}

int Carnivoro::getAtaque() const {
    return ataque;
}

char Carnivoro::simbolo() const {
    return 'E';
}

TipoEntidad Carnivoro::tipo() const {
    return CARNIVORO;
}

Posicion Carnivoro::decidir(const Mundo &mundo, const Posicion &objetivo) const {
    return estrategia->siguiente(mundo,pos,objetivo);
}
