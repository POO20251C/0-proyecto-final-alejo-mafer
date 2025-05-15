//
// Created by mafer on 14/05/2025.
//

#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "Personaje.h"
#include <string>
using namespace std;



class Enemigo : public Personaje{
private:
    string raza;

public:
    Enemigo() = default;
    Enemigo(string tipo, string nombre);

    void atacar(Personaje& objetivo) override;
    void recibirDanio(float cantidad) override;
    float calcularDanio(Personaje& objetivo) const override;

    string getRaza() const;
    void setRaza(const string& raza);

};



#endif //ENEMIGO_H
