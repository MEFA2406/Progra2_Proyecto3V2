//
// Created by Manol on 11/5/2026.
//

#ifndef PROYECTO3_CARNIVORO_H
#define PROYECTO3_CARNIVORO_H
#include "Entidad.h"
#include "IEstrategiaMovimiento.h"

class Carnivoro : public Entidad{
private:
    int ataque;
    IEstrategiaMovimiento* estrategia;
public:
    Carnivoro(const Posicion& posicion,int ataque,IEstrategiaMovimiento* estrategia );
    ~Carnivoro() override;
    Carnivoro(const Carnivoro&) = delete;
    Carnivoro& operator=(const Carnivoro&) = delete;

    int getAtaque() const;
    char simbolo() const override;
    TipoEntidad tipo() const override;
    Posicion decidir(const Mundo& mundo, const Posicion& objetivo) const;
};


#endif //PROYECTO3_CARNIVORO_H