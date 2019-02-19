
#include <iostream>
#include <cstdlib>
#include <string>
#include "persona.h"
#include "crupier.h"

using namespace __cxx11;
using namespace std;

Crupier::Crupier(string DNI , string codigo, string nombre,
 string apellidos, string direccion, string localidad, string provincia,
  string pais): Persona( DNI , nombre, apellidos, direccion, localidad, provincia, pais){


setCodigo(codigo);

}


