#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <fstream>
#include "persona.h"

using namespace std ;

struct Apuesta{

	int tipo ;
	string valor;
	int cantidad ;

};

class Jugador : public Persona {

private:

int dinero_ ;
string codigo_ ;
list<Apuesta> apuestas_ ;


public:

	Jugador(string DNI , string codigo ,
		string nombre = "", string apellidos = "", string direccion = "", string localidad = "", 
		string provincia = "" , string pais = "" , int dinero= 1000 );

inline void setCodigo(string codigo) {codigo_= codigo ;};
inline string getCodigo() {return codigo_ ; };

inline void setDinero(int dinero) {dinero_ = dinero ;};
inline int getDinero() {return dinero_ ; };

inline list<Apuesta> getApuestas() {return apuestas_ ;} ;

void setApuestas() ;
};

#endif