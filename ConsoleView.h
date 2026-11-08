//
// Created by Manol on 11/7/2026.
//

#ifndef PROYECTO3_CONSOLEVIEW_H
#define PROYECTO3_CONSOLEVIEW_H

#include <string>
#include "IObservador.h"

class ConsoleView : public IObservador {
private:
    void mostrarMenu() const;
public:
    void actualizar(const Juego& juego) override;

    void mostrarMensaje(const std::string& texto) const;
    bool pedirOpcion(int& opcion) const;
    bool pedirTecla(char& tecla) const;
    bool pedirSegundos(int& segundos) const;
};


#endif //PROYECTO3_CONSOLEVIEW_H