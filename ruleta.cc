#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <list>
#include <ctime>

#include "ruleta.h"


using namespace std ;
using namespace __cxx11;

Ruleta::Ruleta(Crupier crupier):crupier_(crupier)
{
	srand(time(NULL));
	banca_= 1000000 ;
	bola_ = -1 ;
	
}


bool Ruleta::addJugador(Jugador jugador)
{

	list<Jugador>::iterator i;
	for(i=jugadores_.begin(); i != jugadores_.end(); i++)
		{
		if((*i).getDNI()==jugador.getDNI())
			{
				return false;
			}
		}
	
	jugadores_.push_back(jugador);

	string nombfich = jugador.getDNI() + ".txt";

	if(ifstream(nombfich.c_str()))
	{
	return false ;
	}

	ofstream f(nombfich.c_str());
	return true ;
}



int Ruleta::deleteJugador(Jugador jugador)
{
	list<Jugador>::iterator i;

	if(jugadores_.empty())
	{
		return -1 ;
	}

	
	for(i=jugadores_.begin(); i != jugadores_.end(); i++)
		{
		if((*i).getDNI()==jugador.getDNI())
			{
				i= jugadores_.erase(i) ;
				return 1;
			}
		}

return -2 ;
}

int Ruleta::deleteJugador(string jugadordni)
{
	list<Jugador>::iterator i;

	if(jugadores_.empty())
	{
		return -1 ;
	}

	
	for(i=jugadores_.begin(); i != jugadores_.end(); i++)
		{
		if((*i).getDNI()==jugadordni )
			{
				i= jugadores_.erase(i) ;
				return 1;
			}
		}

return -2 ;
}

void Ruleta::escribeJugadores()
{
	list<Jugador>::iterator i;

	 ofstream myfile;
  	myfile.open ("jugadores.txt");

  	for(i=jugadores_.begin(); i != jugadores_.end() ; i++)
  	{
  		myfile << i->getDNI() << "," << i->getCodigo() << "," << i->getNombre() << "," << i->getApellidos() << ","
  				<<  i->getDireccion() << "," << i->getLocalidad() << "," << i->getProvincia() << "," 
  				<< i->getPais() << "," << i->getDinero() << "\n" ;
  	}


  	myfile.close();
}

void Ruleta::leeJugadores()
{
	string auxstr ;
	Jugador j("","") ;

	ifstream myfile ("jugadores.txt");
  if (myfile.is_open())
  {

  	jugadores_.clear();

  	while(getline (myfile, auxstr , ',' ))
    {			
    			
      			 j.setDNI(auxstr);

      			getline (myfile, auxstr , ',' );
      			 j.setCodigo(auxstr);

				getline (myfile, auxstr , ',' );
      			 j.setNombre(auxstr);

      			getline (myfile, auxstr , ',' );
      			 j.setApellidos(auxstr);

      			getline (myfile, auxstr , ',' );
      			 j.setDireccion(auxstr);

      			getline (myfile, auxstr , ',' );
      			 j.setLocalidad(auxstr);

      			getline (myfile, auxstr , ',' );
      			 j.setProvincia(auxstr);

      			getline (myfile, auxstr , ',' );
      			 j.setPais(auxstr);

      			getline (myfile, auxstr , '\n' );
      			 j.setDinero(atoi(auxstr.c_str()))  ; 
    
    jugadores_.push_back(j);	
    }

    myfile.close();
  }

  else cout << "No se pudo abrir el fichero"; 

}


void Ruleta::giraRuleta()
{
	int n ;
	n = rand() % 37 ;
	bola_ = n ;
}

void Ruleta::getPremios()
{
	list<Jugador>::iterator i ;
	string auxstr ;
	int tipoApuesta ;
	int numeroBolaJugador ;
	int dineroApuestaJugador ;
	string auxApuesta ;

	for(i=jugadores_.begin(); i != jugadores_.end() ; i++)
		{
			string nombfich = i->getDNI() + ".txt";
			ifstream myfile(nombfich.c_str());
			if (myfile.is_open())
				{
					while(getline (myfile, auxstr , ',' ))
					{
					
					tipoApuesta = atoi(auxstr.c_str()) ;

					switch(tipoApuesta) 
						{
							case 1:
									getline (myfile, auxstr , ',' );
									numeroBolaJugador = atoi(auxstr.c_str()) ;
									getline (myfile, auxstr , '\n' );
									dineroApuestaJugador = atoi(auxstr.c_str())  ;

									if(bola_== numeroBolaJugador)
									{
										i->setDinero(i->getDinero() + (dineroApuestaJugador*35));
										banca_= banca_ - (dineroApuestaJugador*35);

									}
									else
									{
										i->setDinero(i->getDinero() - (dineroApuestaJugador));
										banca_= banca_ + (dineroApuestaJugador);
									}

							break;

							case 2:
									getline (myfile, auxstr , ',' );
									auxApuesta = auxstr ;
									getline (myfile, auxstr , '\n' );
									dineroApuestaJugador = atoi(auxstr.c_str())  ;

									if(bola_==0)
									{
										i->setDinero(i->getDinero() - (dineroApuestaJugador));
										banca_= banca_ + (dineroApuestaJugador);
									}

									else
									{

									if(colorBola(bola_) == auxApuesta )
									{
										i->setDinero(i->getDinero() + (dineroApuestaJugador));
										banca_= banca_ - (dineroApuestaJugador);
									}
									else
									{
										i->setDinero(i->getDinero() - (dineroApuestaJugador));
										banca_= banca_ + (dineroApuestaJugador);
									}

									}

							break;

							case 3:
									getline (myfile, auxstr , ',' );
									auxApuesta = auxstr ;
									getline (myfile, auxstr , '\n' );
									dineroApuestaJugador = atoi(auxstr.c_str())  ;

									if(bola_==0)
									{
										i->setDinero(i->getDinero() - (dineroApuestaJugador));
										banca_= banca_ + (dineroApuestaJugador);
									}
									else
									{

									if(esPar(bola_) == auxApuesta )
									{
										i->setDinero(i->getDinero() + (dineroApuestaJugador));
										banca_= banca_ - (dineroApuestaJugador);
									}
									else
									{
										i->setDinero(i->getDinero() - (dineroApuestaJugador));
										banca_= banca_ + (dineroApuestaJugador);
									}

									}

							break;

							case 4:
									getline (myfile, auxstr , ',' );
									auxApuesta = auxstr ;
									getline (myfile, auxstr , '\n' );
									dineroApuestaJugador = atoi(auxstr.c_str())  ;

									if(bola_==0)
									{
										i->setDinero(i->getDinero() - (dineroApuestaJugador));
										banca_= banca_ + (dineroApuestaJugador);
									}
									else
									{



									if(esAlto(bola_) == auxApuesta )
									{
										i->setDinero(i->getDinero() + (dineroApuestaJugador));
										banca_= banca_ - (dineroApuestaJugador);
									}
									else
									{
										i->setDinero(i->getDinero() - (dineroApuestaJugador));
										banca_= banca_ + (dineroApuestaJugador);
									}

									}

							break;


						}
					}

				}
			else
				{
					cout<< "no se pudo abrir el fichero dni con las apuetas" << endl ;
				}

		}

	
}



string Ruleta::colorBola(int Bola)
{
	switch(Bola){
		case 1:
		case 3:
		case 5:
		case 7:
		case 9:
		case 12:
		case 14:
		case 16:
		case 18:
		case 19:
		case 21:
		case 23:
		case 25:
		case 27:
		case 30:
		case 32:
		case 34:
		case 36:
			return "rojo";
		default:
			return "negro";
	}
}

string Ruleta::esPar(int Bola)
{
	if(Bola%2==0)
	{
		return "par";
	}
	else
	{
		return "impar";
	}
}

string Ruleta::esAlto(int Bola)
{
	if((Bola>18)&&(Bola<37))
	{
		return "alto" ;
	}
	else
	{
		return "bajo" ;
	}	
}