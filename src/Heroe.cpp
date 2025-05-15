//
// Created by mafer on 14/05/2025.
//

#include "Heroe.h"
#include "Personaje.h"
#include <iostream>
using namespace std;

Heroe::Heroe(string tipo, string nombre) {
    this->nombre = nombre;
    this->raza = tipo;
    if (tipo == "Guerrero") {
        this->ataque = 10; this->salud = 12; this->defensa = 7; this->velocidad = 5; this->suerte = 2;
    } else if (tipo == "Mago") {
        this->ataque = 8; this->salud = 7; this->defensa = 3; this->velocidad = 4; this->suerte = 6;
    } else if (tipo == "Hada") {
        this->ataque = 6; this->salud = 9; this->defensa = 4; this->velocidad = 6; this->suerte = 8;
    } else if (tipo == "Arquero") {
        this->ataque = 7; this->salud = 8; this->defensa = 5; this->velocidad = 8; this->suerte = 5;
    } else if (tipo == "Clerigo") {
        this->ataque = 5; this->salud = 10; this->defensa = 6; this->velocidad = 4; this->suerte = 7;
    } else if (tipo == "Samurai") {
        this->ataque = 12; this->salud = 9; this->defensa = 4; this->velocidad = 6; this->suerte = 4;
    } else {
        cout << "Tipo de héroe no reconocido." << endl;
    }
}

void Heroe::subirNivel() {
    this->ataque *= 1.02f;
    this->defensa *= 1.02f;
}

void Heroe::atacar(Personaje& objetivo) {
    float danio = this->calcularDanio(objetivo);
    cout << this->nombre << " ataca a " << objetivo.getNombre() << " e inflige " << danio << " de daño." << endl;
    objetivo.recibirDanio(danio);
}

void Heroe::recibirDanio(float cantidad) {
    float danioFinal = cantidad - this->defensa;
    if (danioFinal < 0) danioFinal = 0;
    this->salud -= danioFinal;
    cout << this->nombre << " recibe " << danioFinal << " de daño. Salud restante: " << this->salud << endl;
}

float Heroe::calcularDanio(Personaje& objetivo) const {
    float fallo = (rand() % 100) / 100.0f;
    if (fallo < objetivo.getSuerte() * 0.01f) {
        cout << objetivo.getNombre() << " esquiva el ataque." << endl;
        return 0.0f;
    }

    float critChance = (rand() % 100) / 100.0f;
    bool esCritico = critChance < (this->suerte * 0.01f);

    float baseDanio = this->ataque - objetivo.getDefensa();
    if (baseDanio < 0) baseDanio = this->ataque * 0.3f;

    if (esCritico) {
        cout << "¡Golpe crítico!" << endl;
        baseDanio *= 1.5f;
    }

    return baseDanio;
}

string Heroe::getRaza() const { return this->raza; }
void Heroe::setRaza(const string& raza) { this->raza = raza; }+