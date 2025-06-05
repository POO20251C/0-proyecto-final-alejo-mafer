//
// Created by aleja on 4/06/2025.
//

#ifndef HEROE_H
#define HEROE_H

#include "Personaje.h"

class Heroe : public Personaje {
public:
    Heroe() = default;
    Heroe(std::string nombre, std::string tipo);
    std::string getTipo();
private:
    std::string tipo;
};

#endif