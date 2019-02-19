#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <fstream>

#include "persona.h"
#include "jugador.h"

using namespace std ;




Jugador::Jugador(string DNI , string codigo, string nombre,
 string apellidos, string direccion, string localidad, string provincia,
  string pais , int dinero ): Persona( DNI , nombre, apellidos, direccion, localidad, provincia, pais){

 	dinero_=1000;
 	
 	setCodigo( codigo );
 	setDinero( dinero );
 	


 } 	

void Jugador::setApuestas()
{
  Apuesta aux ;
  string auxstr ;

  if(!apuestas_.empty())
  {
  	apuestas_.clear();
  }

  string nombfich = getDNI() + ".txt";

	ifstream fichero(nombfich.c_str());
 	
	while(getline(fichero ,auxstr, ','))
	{

		aux.tipo = atoi(auxstr.c_str());
		getline(fichero ,auxstr, ',');
		aux.valor = auxstr ;
		getline(fichero ,auxstr, '\n');
		aux.cantidad = atoi(auxstr.c_str());
		
		apuestas_.push_back(aux);

	}

 fichero.close();
}


