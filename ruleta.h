#ifndef RULETA_H
#define RULETA_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <list>

#include "crupier.h"
#include "jugador.h"

using namespace std ;
using namespace __cxx11;

class Ruleta{

	private:

		int banca_  ;
		int bola_   ;
		list<Jugador> jugadores_ ;
		Crupier crupier_;


	public:

		Ruleta(Crupier crupier);


inline bool setBanca(int banca)
	{
		if(banca>=0)
		{
		banca_= banca ;
		return true;
		}
		return false ;
	};

inline int getBanca()const {return banca_ ; };

inline bool setBola(int bola)
	{
		if((bola>=0)&&(bola<=36))
		{
		bola_= bola ;
		return true;
		}
		return false ;
	};

inline int getBola() const{return bola_ ; };

inline void setCrupier(Crupier crupier) {crupier = crupier_ ;};
inline Crupier getCrupier() const{ return crupier_;};

inline list<Jugador> getJugadores() const{return jugadores_;};

bool addJugador(Jugador jugador);
int deleteJugador(Jugador jugador);
int deleteJugador(string jugadordni);

void escribeJugadores();
void leeJugadores();
void giraRuleta();
void getPremios();

string colorBola(int Bola);
string esPar(int Bola);
string esAlto(int Bola);

};


#endif