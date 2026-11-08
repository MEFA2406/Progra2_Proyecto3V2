cmake_minimum_required(VERSION 4.1)
project(Proyecto3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto3 main.cpp
        Entidad.cpp
        Entidad.h
        Posicion.cpp
        Posicion.h
        Equipamiento/Equipamiento.cpp
        Equipamiento/Equipamiento.h
        Equipamiento/Casco.cpp
        Equipamiento/Casco.h
        Equipamiento/Botas.cpp
        Equipamiento/Botas.h
        Equipamiento/Armadura.cpp
        Equipamiento/Armadura.h
        Equipamiento/IProteccion.h
        Equipamiento/EquipoDecorator.cpp
        Equipamiento/EquipoDecorator.h
        Equipamiento/CascoDecorator.cpp
        Equipamiento/CascoDecorator.h
        Equipamiento/BotasDecorator.cpp
        Equipamiento/BotasDecorator.h
        Equipamiento/ArmaduraDecorator.cpp
        Equipamiento/ArmaduraDecorator.h
        Jugador.cpp
        Jugador.h
        Equipamiento/ProteccionBase.cpp
        Equipamiento/ProteccionBase.h
        Comida.cpp
        Comida.h
        Planta.cpp
        Planta.h
        Carnivoro.cpp
        Carnivoro.h
        IEstrategiaMovimiento.h
        EstrategiaAleatoria.cpp
        EstrategiaAleatoria.h
        Mundo.cpp
        Mundo.h
        Juego.cpp
        Juego.h
        Fabrica.cpp
        Fabrica.h
        EstrategiaPerseguir.cpp
        EstrategiaPerseguir.h
        MovimientoAutomatico.cpp
        MovimientoAutomatico.h
        IObservador.h
        ConsoleView.cpp
        ConsoleView.h
        Lista.h
        Nodo.h
        Iterator.h)
