#ifndef CHOFER_HPP_
#define CHOFER_HPP_
#include <string>
#include "Lista.hpp"
using namespace std;
class Chofer{
	private:
		string nombre;
		bool disponible;
        float cal;
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
	
	float get_prom_cal(){
        if (cal>0)
        {
            return cal;
        }else return 0;
        
	}

    void set_cal(float c)
    {
        this->cal=c;
    }
};

#endif
