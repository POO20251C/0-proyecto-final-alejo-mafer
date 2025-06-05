//
// Created by aleja on 4/06/2025.
//

#include "Personaje.h"

//Constructor de la Clase

Personaje::Personaje(std::string nombre, float salud, float ataque, float velocidad, float suerte, float defensa)
    : nombre(nombre), salud(salud), ataque(ataque), velocidad(velocidad), suerte(suerte), defensa(defensa) {}

//getters

float Personaje::getAtaque(){
  return this->ataque;
}
float Personaje::getDefensa(){
  return this->defensa;
}
float Personaje::getSalud(){
  return this->salud;
}

float Personaje::getVelocidad(){
  return this->velocidad;
}

float Personaje::getSuerte(){
  return this->suerte;
}

std::string Personaje::getNombre(){
  return this->nombre;
}

void Personaje::setSalud(float salud_nueva){
  this->salud = salud_nueva;
}

//Metodo de atacar entre personajes

void Personaje::atacar(Personaje* objetivo) {
    //Se multiplica mi capacidad de dañar( ataque )* Suerte/100

    float danio;
    danio = this->ataque;
    float DefensaObjetivo = objetivo->getDefensa();
	float resistencia = objetivo->getDefensa() * objetivo->getSuerte();
    if(danio > resistencia) {
      std::cout << "Acabas de recibir a recibir un golpe crítico" << std::endl;
      float porcentaje = (danio - resistencia)/danio;
      //Disminuyamos la salud del Objetivo en ese porcentaje
      float nueva_salud = objetivo->getSalud()*(1 - porcentaje);
      objetivo->setSalud(nueva_salud);
    }else if( danio > DefensaObjetivo) {
      std::cout << "Haz sido Atacado, pero no haz recibido daño por un glope de suerte" << std::endl;
    }else if( danio < DefensaObjetivo) {
      std::cout << "Tienes una muy buena defensa, no haz recibido daño" << std::endl;
    }
}

