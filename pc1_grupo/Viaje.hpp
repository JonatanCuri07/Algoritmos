#ifndef VIAJE_HPP_
#define VIAJE_HPP_
#include "Chofer.hpp"
class Viaje{
	private:
		string destino,partida;
		Chofer chofer;
	public:
		Viaje(){}
		Viaje(string d, string p, Chofer c)
		{
			this->destino=d;
			this->partida=p;
			this->chofer = c;
		}
		~Viaje(){}
		void set_destino(string d){this->destino = d;}
		void set_partida(string d){this->partida = d;}
		void set_chofer(Chofer c){this->chofer = c;}
		string get_destino(){return this->destino;}
		string get_partida(){return this->partida;}
		Chofer get_chofer(){return this->chofer;}
};
#endif