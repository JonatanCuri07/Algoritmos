#ifndef CHOFER_HPP_
#define CHOFER_HPP_
#include <string>
#include "Lista.hpp"
using namespace std;
class Chofer{
	private:
		string nombre;
		bool disponible;
		Lista<float> list_cal;
		string placa;
		string distrito;
		string coche;
	public:
		Chofer(){};
		Chofer(string n, bool d, string p, string dist, string coche){
			this->nombre=n;
			this->disponible=d;
			this->placa=p;
			this->distrito=dist;
			this->coche=coche;
			this->list_cal=Lista<float>();
		}
	void set_disponible(bool disponible){
        this->disponible=disponible;
    }

    void set_placa(string placa){
        this->placa = placa;
    }

    void set_distrito(string distrito){
        this->distrito=distrito;
    }

    void set_coche(string coche){
        this->coche=coche;
    }

    string get_nombre()
    {
        return nombre;
    }

    bool get_disponible()
    {
        return disponible;
    }

    string get_placa()
    {
        return placa;
    }

    string get_distrito()
    {
        return distrito;
    }

    string get_coche(){
        return coche;
    }
	void add_cal(float t){
		list_cal.addlast(t);
	}
	
	float get_prom_cal(){
		float aux = 0.0f;
		for(int i=0;i<list_cal.size();i++){
			aux +=list_cal.get(i);
		}
		return (aux/list_cal.size());
	}
};

#endif
