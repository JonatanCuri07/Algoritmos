#ifndef AGENCIA_HPP
#define AGENCIA_HPP
#include "Lista.hpp"
#include "Cola.hpp"
#include "Chofer.hpp"
#include "Pasajero.hpp"
class Agencia
{
	public:
	string lugar;
	Lista<Chofer> *chofer_registrados;
	Queue<Pasajero> *pasajeros_registrados;
public:
	Agencia(){
		this->chofer_registrados = new Lista<Chofer>();
		this->pasajeros_registrados = new Queue<Pasajero>();
	};
	Agencia(string l)
	{
		this->lugar = l;
		this->chofer_registrados = new Lista<Chofer>();
		this->pasajeros_registrados = new Queue<Pasajero>();
	}
	~Agencia(){
		delete this->chofer_registrados;
		delete this->pasajeros_registrados;
	}
	void add_pasajeros(Pasajero p){pasajeros_registrados->push(p);}
	void show_pasajeros()
	{
		if(!pasajeros_registrados->empty())
		{
			int aux_size_pasajeros = pasajeros_registrados->get_size();
			cout<<"NOMBRE\t\t"<<"Dni\n";
			for(int i=0;i<aux_size_pasajeros;i++)
			{
				cout<<pasajeros_registrados->front().get_nombre();
				cout<<"\t\t"<<pasajeros_registrados->front().get_dni()<<endl;
				pasajeros_registrados->pop();
			}
		}else {
			cout<<"No hay pasajeros"<<endl;
		}
	}

	Pasajero get_pasajero_front()
	{
		return pasajeros_registrados->front();
	}
	bool pasajero_empty(){return pasajeros_registrados->empty();}
	int get_pasajero_size(){return pasajeros_registrados->get_size();}
	void add_chofer(Chofer c) {chofer_registrados->addfirst(c);}
	void show_chofers()
	{
		if(!chofer_registrados->empty())
		{
			cout<<"NOMBRE\t"<<"Placa\t"<<"Marca\n";
			for(int i=0;i<chofer_registrados->size();i++)
			{
				cout<<chofer_registrados->get(i).get_nombre();
				cout<<"\t"<<chofer_registrados->get(i).get_placa();				
				cout<<"\t"<<chofer_registrados->get(i).get_coche()<<endl;
			}
		}else {
			cout<<"No hay choferes"<<endl;
		}
		
	}

	void Exportar_Pas(){
		auto pas_tostring= [](Pasajero p){
		return p.get_nombre()+" "+to_string(p.get_dni());
		};
		pasajeros_registrados->Exportar(pas_tostring);
	}

	void Exportar_Chofer(){
		auto chofer_tostring= [](Chofer c){
		return c.get_nombre()+" "+c.get_placa()+" "+c.get_coche()+" "+c.get_distrito();
		};
		chofer_registrados->Exportar_chofer(chofer_tostring);
	}

	void show_chofer_dist(string dist){
		cout<<"NOMBRE\t"<<"Placa\t"<<"Marca\n";
		chofer_registrados->mostrarCri(
			[&](Chofer chofer){
				if (chofer.get_distrito()==dist)
				{
					cout<<chofer.get_nombre();
					cout<<"\t"<<chofer.get_placa();				
					cout<<"\t"<<chofer.get_coche()<<endl;
				}
				
			}
		);
	}

	Chofer get_chofer(int pos){return chofer_registrados->get(pos);}
	bool chofer_empty(){return chofer_registrados->empty();}
	int get_chofer_size(){return chofer_registrados->size();}
};
#endif
