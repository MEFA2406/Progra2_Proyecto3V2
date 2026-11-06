//
// Created by Manol on 11/4/2026.
//

#ifndef PROYECTO3_POSICION_H
#define PROYECTO3_POSICION_H

enum Direccion {ARRIBA,ABAJO,IZQUIERDA,DERECHA,TOTAL_DIRECCIONES};

class Posicion {
private:
    int fila;
    int columna;
public:
    Posicion(int x=0,int y=0);

    int getFila() const;
    int getColumna() const;

    bool operator==(const Posicion &p) const;
    int distanciaA(Posicion& otra) const;
    Posicion vecina(Direccion direccion) const;


};


#endif //PROYECTO3_POSICION_H