#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include <iostream>

class Personaje {
public:
    Personaje() = default;
    Personaje(std::string nombre, float salud, float ataque, float velocidad, float suerte, float defensa);

    //Getters y Setters

    float getAtaque();
    float getVelocidad();
    float getSuerte();
    float getSalud();
    float getDefensa();
    std::string getNombre();
    void setSalud(float salud);
    virtual void atacar(Personaje* objetivo);


    virtual ~Personaje() = default;

protected:
    std::string nombre;
    float salud;
    float ataque;
    float velocidad;
    float suerte;
    float defensa;
};

#endif // PERSONAJE_H

