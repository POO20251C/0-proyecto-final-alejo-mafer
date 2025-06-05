#include "Enemigo.h"

using namespace std;

Enemigo::Enemigo(string nombre, string tipo){
    this->nombre = nombre;
    this->tipo = tipo;
    this->salud = 100;

    static bool semillaInicializada = false;
    if (!semillaInicializada) {
        srand(time(0));
        semillaInicializada = true;
    }

    auto variar = [](int base, int margen) {
        return base + (rand() % (2 * margen + 1)) - margen;
    };

    if( tipo == "Soldado"){
      this->ataque = variar(15, 3);
      this->velocidad = variar(10, 4);
      this->suerte = variar(20, 5);
      this->defensa  = variar(10, 6);
    } else if (tipo == "Jefe"){
        this->ataque = variar(25, 3);
        this->velocidad = variar(15, 4);
        this->suerte = variar(24, 5);
        this->defensa  = variar(18, 6);
    } else if (tipo == "GranJefe"){
        this->ataque = variar(30, 4);
        this->velocidad = variar(20, 4);
        this->suerte = variar(30, 5);
        this->defensa  = variar(22, 6);
    }

}



std::string Enemigo::getTipo() {
    return this->tipo;
}