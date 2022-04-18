#include <string>
#include "viajes.hpp"
#include "Listas.hpp"
#define ll long long
using namespace std;

class CPasajero
{
private:
    string nombre;
    ll dni;
    CListaEnlazada<CViaje> viajes;
public:
    CPasajero(){};
    CPasajero(string nombre, ll dni){
        this->nombre=nombre;
        this->dni=dni;
    };
    ~CPasajero();

    void SetNombre(string nombre){
        this->nombre=nombre;   
    }

    void SetDni(ll dni){
        this->dni=dni;   
    }

    string GetNombre()
    {
        return nombre;
    }

    ll GetDni()
    {
        return dni;
    }
    
};

