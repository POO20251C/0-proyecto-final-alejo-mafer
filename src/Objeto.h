#ifndef OBJETO_H
#define OBJETO_H

#include <string>

using namespace std;

class Objeto {
public:
    Objeto() = default;
    Objeto(int NivelDisponible, string NombreObjeto, string Tipo, float Porcentaje) ;

    string getTipo();
    string getNombre();
    int getNivelDisponible();
    int getPorcentajeAumento();
private:
    string Tipo;
    string NombreObjeto;
    int NivelDisponible;
    float PorcentajeAumento;

};



#endif //OBJETO_H
