#include "src/Personaje.h"
#include "src/Heroe.h"
#include "src/Controlador.h"
#include "string"
#include "iostream"

using namespace std;

int main() {
    //Creemos una instancia del controlador

    Controlador Micontrolador;
    Micontrolador.InstanciarHeroes();

    Usuario * user = Micontrolador.RegistrarUsuario("Alejandro");
    Micontrolador.EscogerHeroes(user);

    //funciona bien porque si se guardan los Heroes
    for(int i = 0; i < user->HeroesEscogidos.size(); i++) {
    	cout << user->HeroesEscogidos[i]->getNombre() << "\n" << endl;
    }


};




