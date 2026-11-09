//
// Created by Manol on 11/8/2026.
//

#include "Aplicacion.h"
#include <ctime>

Aplicacion::Aplicacion() {
    srand(time(NULL));
    juego.agregarObservador(&vista);
}

void Aplicacion::modoManual() {
    if (juego.getEstado() != JUGANDO) {
        vista.mostrarMensaje("La partida termino. Inicia una nueva (opcion 1).");
        return;
    }
    char tecla;
    while (juego.getEstado() == JUGANDO) {
        if (!juego.hayMovimientoValido()) {
            juego.pasarTurno();
            continue;
        }
        if (!vista.pedirTecla(tecla) || tecla == 'q' || tecla == 'Q') return;
        juego.mover(tecla);
    }
}

void Aplicacion::modoAutomatico() {
    if (juego.getEstado() != JUGANDO) {
        vista.mostrarMensaje("La partida termino. Inicia una nueva (opcion 1).");
        return;
    }
    int segundos = 0;
    while (segundos < 1 || segundos > 3) {
        if (!vista.pedirSegundos(segundos)) return;
    }
    juego.ejecutarAutomatico(segundos);
}

int Aplicacion::ejecutar() {
    juego.nuevaPartida();

    int opcion = -1;
    do {
        if (!vista.pedirOpcion(opcion)) break;
        switch (opcion) {
            case 1: juego.nuevaPartida(); break;
            case 2: modoManual();         break;
            case 3: modoAutomatico();     break;
            case 4:
                break;
            case 5:
                break;
            case 0: break;
            default: vista.mostrarMensaje("Opcion invalida.");
        }
    } while (opcion != 0);

    vista.mostrarMensaje("\nHasta pronto!");
    return 0;
}