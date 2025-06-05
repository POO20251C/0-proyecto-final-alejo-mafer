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
    int NumHeroesEscogidos = 0;
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
        }else if(NumHeroesEscogidos == 3){
          cout << "Haz salido" << endl;
          escoger = false;
        }else if(tecla == 13){
          Heroe* HeroeEscogido = &(this->HeroesDisponibles[cursorPos]);
          usuario->HeroesEscogidos.push_back(HeroeEscogido);
          NumHeroesEscogidos++;
        }
	}
}

void Controlador::CrearMazmorraz() {
	vector<Enemigo*> soldados;
    vector<Enemigo*> jefes;
    vector<Enemigo*> granJefes;

    for (Enemigo& enemigo : this->EnemigosDisponibles) {
        string tipo = enemigo.getTipo();
        if (tipo == "Soldado") {
            soldados.push_back(&enemigo);
        } else if (tipo == "Jefe") {
            jefes.push_back(&enemigo);
        } else if (tipo == "GranJefe") {
            granJefes.push_back(&enemigo);
        }
    }


    srand(time(0));  // Asegura aleatoriedad solo una vez
    for (int i = 0; i < 10; ++i) {
        Mazmorra nueva;

        if (i < 6 && !soldados.empty()) {
            int idx = rand() % soldados.size();
            nueva.JefeSala = soldados[idx];
        } else if (i < 9 && !jefes.empty()) {
            int idx = rand() % jefes.size();
            nueva.JefeSala = jefes[idx];
        } else if (i == 9 && !granJefes.empty()) {
            int idx = rand() % granJefes.size();
            nueva.JefeSala = granJefes[idx];
        }


        if (!this->ObjetosRegistrados.empty()) {
            int idx = rand() % this->ObjetosRegistrados.size();
            nueva.ObjetoDeSala = &this->ObjetosRegistrados[idx];
        }


        this->Mazmorras.push_back(nueva);
    }
}

void Controlador::Jugar(Usuario* jugador) {
    srand(time(0));

    for (int i = 0; i < this->Mazmorras.size(); i++) {
        Enemigo* enemigo = Mazmorras[i].JefeSala;

        cout << "\n======= Sala " << (i + 1) << " =======\n";
        cout << "Enemigo: " << enemigo->getNombre()
             << " | Salud: " << enemigo->getSalud() << "\n";

        for (Heroe* h : jugador->HeroesEscogidos) {
            cout << "Héroe: " << h->getNombre()
                 << " | HP: " << h->getSalud()
                 << " | ATK: " << h->getAtaque()
                 << " | DEF: " << h->getDefensa() << endl;
        }

        // Determinar quién tiene la mayor velocidad
        bool turnoJugador = true;
        float velocidadMax = 0;

        for (Heroe* h : jugador->HeroesEscogidos) {
            if (h->getSalud() > 0 && h->getVelocidad() > velocidadMax) {
                velocidadMax = h->getVelocidad();
            }
        }

        if (enemigo->getVelocidad() > velocidadMax) {
            turnoJugador = false;  // Enemigo empieza
        }

        bool salaActiva = true;

        while (salaActiva) {
            if (turnoJugador) {
                // Turno del jugador
                int total = jugador->HeroesEscogidos.size();
                vector<string> cursores(total, " ");
                int cursorPos = 0;
                cursores[cursorPos] = ">";

                bool elegido = false;

                while (!elegido) {
                    system("cls");
                    cout << "Turno del jugador\n";
                    cout << "=== Selecciona un héroe para atacar ===\n";

                    for (int j = 0; j < total; j++) {
                        Heroe* h = jugador->HeroesEscogidos[j];
                        string estado = h->getSalud() > 0 ? "VIVO" : "KO";
                        cout << cursores[j] << " " << h->getNombre()
                             << " | HP: " << h->getSalud()
                             << " (" << estado << ")\n";
                    }

                    int tecla = _getch();
                    if (tecla == 80 && cursorPos < total - 1) { // Flecha abajo
                        cursores[cursorPos] = " ";
                        cursorPos++;
                        cursores[cursorPos] = ">";
                    } else if (tecla == 72 && cursorPos > 0) { // Flecha arriba
                        cursores[cursorPos] = " ";
                        cursorPos--;
                        cursores[cursorPos] = ">";
                    } else if (tecla == 13) { // ENTER
                        Heroe* h = jugador->HeroesEscogidos[cursorPos];
                        if (h->getSalud() <= 0) {
                            cout << "\nEste héroe está KO. Elige otro.\n";
                            system("pause");
                        } else {
                            cout << "\n golpe " << h->getNombre() << " ataca a " << enemigo->getNombre() << "...\n";
                            h->atacar(enemigo);

                            if (enemigo->getSalud() <= 0) {
                                cout << "\n exito " << enemigo->getNombre() << " ha sido derrotado.\n";
                                salaActiva = false;
                            }
                            elegido = true;
                        }
                    }
                }

                turnoJugador = false;
            } else {
                // Turno del enemigo
                vector<Heroe*> vivos;
                for (Heroe* h : jugador->HeroesEscogidos) {
                    if (h->getSalud() > 0) vivos.push_back(h);
                }

                if (vivos.empty()) {
                    cout << "\n Todos los héroes han caído. Fin del juego.\n";
                    return;
                }

                int idx = rand() % vivos.size();
                Heroe* objetivo = vivos[idx];

                cout << "\n muerte  " << enemigo->getNombre() << " ataca a " << objetivo->getNombre() << "...\n";
                enemigo->atacar(objetivo);

                if (objetivo->getSalud() <= 0) {
                    cout << "muerte " << objetivo->getNombre() << " ha sido derrotado.\n";
                }

                turnoJugador = true;
                system("pause");
            }

            // Verificar si ya perdiste 2 héroes
            int muertos = 0;
            for (Heroe* h : jugador->HeroesEscogidos) {
                if (h->getSalud() <= 0) muertos++;
            }

            if (muertos >= 2) {
                cout << "\n Has perdido a 2 héroes. Fin del juego.\n";
                return;
            }
        }

        cout << "\n Sala " << (i + 1) << " superada. Avanzas.\n";
        system("pause");
    }

    cout << "\n¡Felicidades! Has completado todas las salas de la mazmorra.\n";
}