#ifndef PASAJERO_HPP_
#define PASAJERO_HPP_
#include "Lista.hpp"
#include "Viaje.hpp"
#include "Pila.hpp"
#include <string>
#define ll long long
class Pasajero {
	private:
		string nombre;
		ll dni;
	public:
		Stack<Viaje> *p_viaje;
		Pasajero(){
			this->nombre = "";
			this->dni = 0;
			this->p_viaje = new Stack<Viaje>();
		}
		Pasajero(string n,ll dni)
		{
			this-> nombre=n;
			this->dni=dni;
			this->p_viaje = new Stack<Viaje>();
		}
		string get_nombre(){return this->nombre;}
		ll get_dni(){return this->dni;}
		void agregar_viaje(string dest, string part, Chofer c)
		{
				p_viaje->push(Viaje(dest,part,c));
		}
		void show_viajes()
		{
			int aux_viaje_size = p_viaje->size();
			if(p_viaje->size() != 0)
			{
				cout<<"\nChofer\t"<<"\tCarro\t"<<"\tPlaca\t"<<"\tPartida\t"<<"\tDestino\t";
				for(int i = 0;i<p_viaje->size();i++)
				{
					cout<<"\n"<<p_viaje->top().get_chofer().get_nombre();
					cout<<"\t\t"<<p_viaje->top().get_chofer().get_coche();
					cout<<"\t\t"<<p_viaje->top().get_chofer().get_placa();
					cout<<"\t\t"<<p_viaje->top().get_chofer().get_distrito();
					cout<<"\t\t"<<p_viaje->top().get_destino();
					p_viaje->pop();
				}
				//IMPORTAR TODOS LOS VIAJES DEL ARCHIVO HACIA LA PILA O(N)
				/*
				 for(i<aux_viaje_size){
					//exportas pichulas
					Viajes aux = Viaje(lectura de archivos{destino,partica,Chofer});
					p_viaje->push(aux);
				 }
				 */
			}else{cout<<"No has hecho ningun viaje aun"<<endl;}
		}
		
};
#endif
