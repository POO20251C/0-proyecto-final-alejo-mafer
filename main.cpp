#include <iostream>
#include "src/Controlador.h"

using namespace std;

int main() {
    Controlador controlador;


    controlador.InstanciarHeroes();
    controlador.InstanciarEnemigos();
    controlador.InstanciarObjetos();


    string nombre;
    cout << "=== Bienvenido a Natal Combat ===" << endl;
    cout << "Ingresa tu nombre de jugador: ";
    getline(cin, nombre);


    Usuario* usuario = controlador.RegistrarUsuario(nombre);


    cout << "\n=== Héroes Disponibles ===\n";
    controlador.mostrarHeroesDisponibles();


    cout << "\nSelecciona tus héroes (usa ↑ ↓ y ENTER para elegir, 'a' para salir):\n";
    controlador.EscogerHeroes(usuario);


    controlador.CrearMazmorraz();


    controlador.Jugar(usuario);

    return 0;
}



