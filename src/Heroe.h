//
// Created by mafer on 14/05/2025.
//

#ifndef HEROE_H
#define HEROE_H
#include "Personaje.h"
#include <string>
using namespace std;


class Heroe: public Personaje {
private:
    string raza;

public:
    Heroe() = default;
    Heroe(string tipo, string nombre);

    void subirNivel();

    void atacar(Personaje& objetivo) override;
    void recibirDanio(float cantidad) override;
    float calcularDanio(Personaje& objetivo) const override;

    string getRaza() const;
    void setRaza(const string& raza);
};



#endif //HEROE_H
