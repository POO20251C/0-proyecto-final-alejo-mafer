#include "Heroe.h"
#include <iostream>
#include <string>

Heroe::Heroe(std::string nombre, std::string tipo) {
    this->nombre = nombre;
    this->tipo = tipo;
    this->salud = 100;


    static bool semillaInicializada = false;
    if (!semillaInicializada) {
        srand(time(0));
        semillaInicializada = true;
    }

    auto variar = [](int base, int margen) {
        return base + (rand() % (2 * margen + 1)) - margen;
    };

    if (tipo == "mago") {
        this->ataque   = variar(25, 5);
        this->velocidad= variar(15, 3);
        this->suerte   = variar(20, 4);
        this->defensa  = variar(10, 2);
    } else if (tipo == "caballero") {
        this->ataque   = variar(20, 4);
        this->velocidad= variar(10, 2);
        this->suerte   = variar(10, 3);
        this->defensa  = variar(30, 5);
    } else if (tipo == "ninja") {
        this->ataque   = variar(18, 3);
        this->velocidad= variar(25, 5);
        this->suerte   = variar(15, 3);
        this->defensa  = variar(12, 2);
    } else if (tipo == "curandero") {
        this->ataque   = variar(10, 2);
        this->velocidad= variar(12, 2);
        this->suerte   = variar(25, 4);
        this->defensa  = variar(20, 3);
    }
}




std::string Heroe::getTipo() {
  return this->tipo;
}