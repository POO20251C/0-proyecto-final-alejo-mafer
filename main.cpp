#include "src/Controlador.h"
#include "string"
#include "iostream"

using namespace std;

int main() {
    //Prueba de Instanciacion de Enemigos
    Controlador MiPrimerControlador;
    MiPrimerControlador.InstanciarObjetos();
    MiPrimerControlador.mostrarObjetosDisponibles();
    MiPrimerControlador.CrearMazmorraz();
    cout << MiPrimerControlador.Mazmorras.size() << endl;
};




