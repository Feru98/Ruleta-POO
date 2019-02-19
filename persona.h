#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std ;




class Persona{

private:

string DNI_ ;
string nombre_ ;
string apellidos_ ;
string direccion_ ;
string localidad_ ;
string provincia_ ;
string pais_;

public:

	Persona(string DNI , string nombre = "", string apellidos = "", string direccion = "", string localidad = "", string provincia = "" , string pais = "");

inline void setDNI(string DNI) {DNI_= DNI ;};
inline string getDNI() {return DNI_ ; };

inline void setNombre(string nombre) {nombre_= nombre ;};
inline string getNombre() {return nombre_ ; };

inline void setApellidos(string apellidos) {apellidos_= apellidos ;};
inline string getApellidos() {return apellidos_ ; };

inline void setDireccion(string direccion) {direccion_= direccion ;};
inline string getDireccion() {return direccion_ ; };

inline void setLocalidad(string localidad) {localidad_ = localidad ;};
inline string getLocalidad() {return localidad_ ; };

inline void setProvincia(string provincia) {provincia_= provincia ;};
inline string getProvincia() {return provincia_ ; };

inline void setPais(string pais) {pais_= pais ;};
inline string getPais() {return pais_ ; };

inline string getApellidosyNombre() {return (apellidos_ + ", " + nombre_ ) ;};

};

#endif