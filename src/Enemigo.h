#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Personaje.h"

class Enemigo : public Personaje {
public:
    Enemigo() = default;
    Enemigo(std::string nombre, std::string tipo);
    std::string getTipo();

private:
    std::string tipo;
};

#endif // ENEMIGO_H
