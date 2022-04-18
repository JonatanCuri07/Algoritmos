#include <iostream>
#include <string>
using namespace std;

class CChofer
{
private:
    string nombre;
    bool disponible;
    string placa;
    string distrito;
    string coche;
public:
    CChofer(){};
    CChofer(string nombre, bool disponible, string placa, string distrito, string coche){
        this->nombre=nombre;
        this->disponible=disponible;
        this->placa=placa;
        this->distrito=distrito;
        this->coche=coche;
    };
    ~CChofer();

    void SetNombre(string nombre){
        this->nombre=nombre;   
    }

    void SetDisponible(bool disponible){
        this->disponible=disponible;   
    }
    
    void SetPlaca(string placa){
        this->placa = placa;   
    }

    void SetNombre(string distrito){
        this->distrito=distrito;   
    }

    void SetCoche(string coche){
        this->coche=coche;
    }

    string GetNombre()
    {
        return nombre;
    }

    bool GetDisponible()
    {
        return disponible;
    }
    
    string GetPlaca()
    {
        return placa;
    }

    string GetDistrito()
    {
        return distrito;
    }

    string GetCoche(){
        return coche;
    }
};

