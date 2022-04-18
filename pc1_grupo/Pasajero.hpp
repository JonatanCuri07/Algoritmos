#ifndef PASAJERO_HPP_
#define PASAJERO_HPP_
#include "Lista.hpp"
#include "Viaje.hpp"
#include <string>
#define ll long long
class Pasajero {
	private:
		string nombre;
		ll dni;
	public:
		Lista<Viaje> *l_viaje;
		Pasajero(){}
		Pasajero(string n,ll dni)
		{
			this-> nombre=n;
			this->dni=dni;
			this->l_viaje = new Lista<Viaje>();
		}
		string get_nombre(){return this->nombre;}
		ll get_dni(){return this->dni;}
		void agregar_viaje(string dest, string part, Chofer c)
		{
				l_viaje->addlast(Viaje(dest,part,c));
		}
		void show_viajes()
		{
			if(l_viaje->size() != 0)
			{
					cout<<"\nChofer\t"<<"\tCarro\t"<<"\tPlaca\t"<<"\Partida"<<"\tDestino\t";
				for(int i = 0;i<l_viaje->size();i++)
				{
					cout<<"\n"<<l_viaje->get(i).get_chofer().get_nombre();
					cout<<"\t\t"<<l_viaje->get(i).get_chofer().get_coche();
					cout<<"\t\t"<<l_viaje->get(i).get_chofer().get_placa();
					cout<<"\t\t"<<l_viaje->get(i).get_chofer().get_distrito();
					cout<<"\t\t"<<l_viaje->get(i).get_destino();
					
				}
			}else{cout<<"No has hecho ningun viaje aun"<<endl;}
		}
};
#endif
