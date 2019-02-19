#ifndef CRUPIER_H
#define CRUPIER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "persona.h"
using namespace std ;


class Crupier : public Persona {

private:

string codigo_ ;


public:

Crupier(string DNI , string codigo , string nombre = "", string apellidos = "", string direccion = "", string localidad = "", string provincia = "" , string pais = "");


inline void setCodigo(string codigo) {codigo_= codigo ;};
inline string getCodigo() {return codigo_ ; };



};

#endif