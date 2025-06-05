//
// Created by aleja on 3/06/2025.
//
#include <string>
#include <iostream>
#include <vector>
#include "Enemigo.h"
#include "Heroe.h"
#include "Usuario.h"
#include "Objeto.h"
#include "Mazmorra.h"

using namespace std;
#ifndef CONTROLADOR_H
#define CONTROLADOR_H

class Controlador {
public:
  //Atributos
  vector <Enemigo> EnemigosDisponibles;
  vector <Heroe> HeroesDisponibles;
  vector <Usuario> UsuariosRegistrados;
  vector <Objeto> ObjetosRegistrados;
  vector <Mazmorra> Mazmorras;

  //Metodos Asociados
  Controlador(); //función para instanciar
  void InstanciarHeroes(); //Función asociada para instanciar los heroes
  void InstanciarEnemigos(); //Funcion asoaciada para instanciar los enemigos
  void InstanciarObjetos(); //Funcion para Instanciar Objetos del Juego
  void mostrarHeroesDisponibles();
  void mostrarEnemigosDisponibles();
  void mostrarObjetosDisponibles();
  Usuario* RegistrarUsuario(string nombre);
  void EscogerHeroes(Usuario *usuario); //Escoger heroes para un Usuario deseado
  void CrearMazmorraz(); //Funcion que crea el vector de Mazmorras
  void Jugar(Usuario *usuario);
};



#endif //CONTROLADOR_H
