//
// Created by mafer on 14/05/2025.
//

#include "Enemigo.h"
#include "Personaje.h"
#include <string>
#include <iostream>
using namespace std;

Enemigo::Enemigo(string tipo, string nombre) {
    this->nombre = nombre;
    this->raza = tipo;

    if (tipo == "Soldado") {
        this->ataque = 6 + (rand() % 3);
        this->salud = 10 + (rand() % 6);
        this->defensa = 4;
        this->velocidad = 4;
        this->suerte = 1 + (rand() % 3);
    } else if (tipo == "MiniJefe") {
        this->ataque = 10;
        this->salud = 25;
        this->defensa = 6;
        this->velocidad = 5;
        this->suerte = 2;
    } else if (tipo == "GranJefe") {
        this->ataque = 14;
        this->salud = 40;
        this->defensa = 8;
        this->velocidad = 6;
        this->suerte = 4;
    } else {
        cout << "Tipo de enemigo no reconocido." << endl;
    }
}

void Enemigo::atacar(Personaje& objetivo) {
    float danio = this->calcularDanio(objetivo);
    cout << this->nombre << " ataca a " << objetivo.getNombre() << " e inflige " << danio << " de daño." << endl;
    objetivo.recibirDanio(danio);
}

void Enemigo::recibirDanio(float cantidad) {
    float danioFinal = cantidad - this->defensa;
    if (danioFinal < 0) danioFinal = 0;
    this->salud -= danioFinal;
    cout << this->nombre << " recibe " << danioFinal << " de daño. Salud restante: " << this->salud << endl;
}

float Enemigo::calcularDanio(Personaje& objetivo) const {
    float fallo = (rand() % 100) / 100.0f;
    if (fallo < objetivo.getSuerte() * 0.01f) {
        cout << objetivo.getNombre() << " esquiva el ataque del enemigo." << endl;
        return 0.0f;
    }

    float critChance = (rand() % 100) / 100.0f;
    bool esCritico = critChance < (this->suerte * 0.01f);

    float baseDanio = this->ataque - objetivo.getDefensa();
    if (baseDanio < 0) baseDanio = this->ataque * 0.3f;

    if (esCritico) {
        cout << "¡Golpe crítico enemigo!" << endl;
        baseDanio *= 1.3f;
    }

    return baseDanio;
}

string Enemigo::getRaza() const { return this->raza; }
void Enemigo::setRaza(const string& raza) { this->raza = raza; }