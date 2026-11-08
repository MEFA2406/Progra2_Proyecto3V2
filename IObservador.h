//
// Created by Manol on 11/7/2026.
//

#ifndef PROYECTO3_IOBSERVADOR_H
#define PROYECTO3_IOBSERVADOR_H

class Juego;

class IObservador {
public:
    virtual ~IObservador() = default;
    virtual void actualizar(const Juego& juego) = 0;
};


#endif //PROYECTO3_IOBSERVADOR_H