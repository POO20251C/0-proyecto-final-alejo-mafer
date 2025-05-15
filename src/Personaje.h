//
// Created by mafer on 14/05/2025.
//

#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <string>
//#include <vector>
#include <iostream>
using namespace std;


class Personaje {
public:
    Personaje() = default;
    Personaje(string nombre, float salud, float ataque, float velocidad, float suerte, float defensa);

    // Getters
    string getNombre() const;
    float getSalud() const;
    float getAtaque() const;
    float getVelocidad() const;
    float getSuerte() const;
    float getDefensa() const;

    // Setters
    void setNombre(const string& nombre);
    void setSalud(float salud);
    void setAtaque(float ataque);
    void setVelocidad(float velocidad);
    void setSuerte(float suerte);
    void setDefensa(float defensa);

    // Métodos
    void mostrarNombre() const;

    // Métodos de combate
    virtual void atacar(Personaje& objetivo) = 0;
    virtual void recibirDanio(float cantidad) = 0;
    virtual float calcularDanio(Personaje& objetivo) const = 0;

    virtual ~Personaje() = default;

protected:
    string nombre;
    float salud;
    float ataque;
    float velocidad;
    float suerte;
    float defensa;
};
#endif //PERSONAJE_H
