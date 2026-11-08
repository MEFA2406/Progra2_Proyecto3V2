//
// Created by Manol on 11/7/2026.
//

#include "EstrategiaPerseguir.h"

#include "Mundo.h"

EstrategiaPerseguir::EstrategiaPerseguir(int radio) :radioVision(radio){

}

Posicion EstrategiaPerseguir::siguiente(const Mundo &mundo, const Posicion &actual, const Posicion &objetivo) const {
    if (actual.distanciaA(objetivo)>radioVision) {
        return estrategia.siguiente(mundo, actual, objetivo);
    }
    Posicion mejor = actual;
    int mejorDist = actual.distanciaA(objetivo);
    for (int i=0; i< TOTAL_DIRECCIONES;i++) {
        Posicion n = actual.vecina(static_cast<Direccion>(i));
        if (mundo.puedeMover(n) && n.distanciaA(objetivo) < mejorDist) {
            mejorDist = n.distanciaA(objetivo);
            mejor = n;
        }
    }
    return mejor;
}
