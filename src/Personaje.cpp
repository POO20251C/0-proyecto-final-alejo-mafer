//
// Created by mafer on 14/05/2025.
//

#include "Personaje.h"
#include <iostream>
using namespace std;

//constructor

Personaje::Personaje(string nombre, float salud, float ataque, float velocidad, float suerte, float defensa) {
    this->nombre = nombre;
    this->salud = salud;
    this->ataque = ataque;
    this->velocidad = velocidad;
    this->suerte = suerte;
    this->defensa = defensa;
}
string Personaje::getNombre() const {return this->nombre;}
float Personaje::getSalud() const { return this->salud; }
float Personaje::getAtaque() const { return this->ataque; }
float Personaje::getVelocidad() const { return this->velocidad; }
float Personaje::getSuerte() const { return this->suerte; }
float Personaje::getDefensa() const { return this->defensa; }
//vector<Objeto*> Personaje::getObjetos() const { return this->objetos; }

void Personaje::setNombre(const string& nombre) { this->nombre = nombre; }
void Personaje::setSalud(float salud) { this->salud = salud; }
void Personaje::setAtaque(float ataque) { this->ataque = ataque; }
void Personaje::setDefensa(float defensa) { this->defensa = defensa; }
void Personaje::setVelocidad(float velocidad) { this->velocidad = velocidad; }
void Personaje::setSuerte(float suerte) { this->suerte = suerte; }

void Personaje::mostrarNombre() const {
    cout << "Nombre del personaje: " << this->nombre << endl;
}