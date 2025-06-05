//
// Created by aleja on 3/06/2025.
//

#include <fstream>
#include <sstream>
#include <conio.h>   // Para _getch()
#include "Controlador.h"





using namespace std;

Controlador::Controlador(){
    this->EnemigosDisponibles = vector <Enemigo>();
    this->HeroesDisponibles = vector <Heroe>();
};

void Controlador::InstanciarHeroes() {
    ifstream file("src/Heroes.txt");


    if (file.is_open()) {
        string line;

        while (getline(file, line)) {
            string nombre, tipo, s;
            vector<string> tokens;
            stringstream ss(line);
            while (getline(ss,s,' ')){
              tokens.push_back(s);
            }
            nombre = tokens[0];
            tipo = tokens[1];
            // Si ambos campos fueron extraídos, crear el héroe
            if (!nombre.empty() && !tipo.empty()) {
                Heroe nuevoHeroe(nombre, tipo);
                this->HeroesDisponibles.push_back(nuevoHeroe);
            }
        }

        file.close();
    }
}

void Controlador::InstanciarEnemigos() {
    ifstream file("src/Enemigos.txt");


    if (file.is_open()) {
        string line;

        while (getline(file, line)) {
            string nombre, tipo, s;
            vector<string> tokens;
            stringstream ss(line);
            while (getline(ss,s,' ')){
              tokens.push_back(s);
            }
            nombre = tokens[0];
            tipo = tokens[1];
            // Si ambos campos fueron extraídos, crear el Enemigo
            if (!nombre.empty() && !tipo.empty()) {
                Enemigo nuevoEnemigo(nombre, tipo);
                this->EnemigosDisponibles.push_back(nuevoEnemigo);
            }
        }

        file.close();
    }
}



void Controlador::InstanciarObjetos() {
    ifstream file("src/Objetos.txt");

    if (file.is_open()) {
        string line;

        while (getline(file, line)) {
            vector<string> tokens;
            stringstream ss(line);
            string s;

            while (getline(ss, s, ' ')) {
                tokens.push_back(s);
            }

            if (tokens.size() == 4) {
                int nivel = stoi(tokens[0]);
                string nombre = tokens[1];
                string tipo = tokens[2];
                float porcentaje = stof(tokens[3]);

                Objeto nuevoObjeto(nivel, nombre, tipo, porcentaje);
                this->ObjetosRegistrados.push_back(nuevoObjeto);
            }
        }

        file.close();
    }
}

void Controlador::mostrarHeroesDisponibles() {
  cout << "Nombre   "  << "Tipo  " << endl;
  for (int i = 0; i < this->HeroesDisponibles.size(); i++) {
    cout << this->HeroesDisponibles[i].getNombre() << "    " << this->HeroesDisponibles[i].getTipo() << endl;
  }
}

void Controlador::mostrarEnemigosDisponibles() {
  cout << "Nombre   "  << "Tipo  " << endl;
  for (int i = 0; i < this->EnemigosDisponibles.size(); i++) {
    cout << this->EnemigosDisponibles[i].getNombre() << "    " << this->EnemigosDisponibles[i].getTipo() << endl;
  }
}

void Controlador::mostrarObjetosDisponibles() {
  cout << "Nombre   "  << "Tipo  " << endl;
  for (int i = 0; i < this->ObjetosRegistrados.size(); i++) {
    cout << this->ObjetosRegistrados[i].getNombre() << "    " << this->ObjetosRegistrados[i].getTipo() << endl;
  }
}

Usuario* Controlador::RegistrarUsuario(string nombre){
    Usuario NuevoUsuario(nombre);
    this->UsuariosRegistrados.push_back(NuevoUsuario);
    return &this->UsuariosRegistrados.back();
}

void Controlador::EscogerHeroes(Usuario* usuario){
  	bool escoger = true;
    int total = this->HeroesDisponibles.size();
    vector <string> cursores(total, " ");
    int cursorPos = 0;
    cursores[cursorPos] = ">";
    while(escoger){
        system("cls");
        for(int i = 0; i < this->HeroesDisponibles.size(); i++){
        	cout << cursores[i] << " " << this->HeroesDisponibles[i].getNombre() << " " << this->HeroesDisponibles[i].getTipo() << " " << this->HeroesDisponibles[i].getAtaque() << " " << this->HeroesDisponibles[i].getDefensa() << endl;
		}
        int tecla = _getch();
        if (tecla == 80 and cursorPos < total - 1 and cursorPos >= 0) { // Arriba
			cursores[cursorPos + 1] = cursores[cursorPos];
            cursores[cursorPos] = " ";
            cursorPos++;
        }else if (tecla == 72 and cursorPos < total and cursorPos >= 1) { // Abajo
            cursores[cursorPos - 1] = cursores[cursorPos];
            cursores[cursorPos] = " ";
            cursorPos--;
        }else if(tecla == 97){
          cout << "Haz salido" << endl;
          escoger = false;
        }else if(tecla == 13){
          Heroe* HeroeEscogido = &(this->HeroesDisponibles[cursorPos]);
          usuario->HeroesEscogidos.push_back(HeroeEscogido);
        }
	}
}

void Controlador::CrearMazmorraz() {

}