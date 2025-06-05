#include "Objeto.h"

using namespace std;

Objeto::Objeto(int NivelDisponible, string NombreObjeto, string Tipo, float PorcentajeAumento) {
    this->NombreObjeto = NombreObjeto;
    this->NivelDisponible = NivelDisponible;
    this->Tipo = Tipo;
    this->PorcentajeAumento = PorcentajeAumento;
};


string Objeto::getTipo() {
    return this->Tipo;
}

string Objeto::getNombre() {
    return this->NombreObjeto;
};

int Objeto::getNivelDisponible() {
    return this->NivelDisponible;
};

int Objeto::getPorcentajeAumento() {
    return this->PorcentajeAumento;
}