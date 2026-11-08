//
// Created by Manol on 11/7/2026.
//

#include "Fabrica.h"

#include <cstdlib>

#include "Comida.h"
#include "Planta.h"
#include "Carnivoro.h"
#include "Equipamiento/Armadura.h"
#include "Equipamiento/Botas.h"
#include "Equipamiento/Casco.h"
#include "EstrategiaAleatoria.h"
#include "EstrategiaPerseguir.h"

IEstrategiaMovimiento * Fabrica::estrategiaPara(int nivel) {
    if (nivel <= 1) return new EstrategiaAleatoria(); // si es nivel 1 no persigue
    return new EstrategiaPerseguir(nivel ==2 ? 3:5); // nivel 2 radio 3, nivel 3 radio 5
}

Entidad * Fabrica::crear(char simbolo, const Posicion &p, int nivel, int valorComida) {
    switch (simbolo) {
        case 'C': return new Comida(p,valorComida > 0 ? valorComida : (rand() % 5) + 2);
        case 'P': return new Planta(p);
        case 'H': return new Casco(p);
        case 'B': return new Botas(p);
        case 'A': return new Armadura(p);
        case 'E': return new Carnivoro(p, 5*nivel,estrategiaPara(nivel));
        default: return nullptr;


    }
}
