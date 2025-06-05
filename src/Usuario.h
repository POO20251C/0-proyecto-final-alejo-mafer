//
// Created by aleja on 4/06/2025.
//

#ifndef USUARIO_H
#define USUARIO_H

#include "Heroe.h"
#include "Objeto.h"
#include <vector>
#include <string>

using namespace std;
class Usuario {
public:
  std::string nombre;
  vector<Heroe* > HeroesEscogidos;
  //un apuntador a una Sala, que seria la sala donde perdio
  vector<Objeto> ObjetosRecolectados;

  //Funciones
  Usuario(string nombre);
};



#endif //USUARIO_H
