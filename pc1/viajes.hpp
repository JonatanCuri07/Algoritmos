#include "chofer.hpp"
#include "Listas.hpp"
class CViaje
{
private:
    string destino;
    string partida;
    CChofer chofer;
    CListaEnlazada<CChofer> choferes;
public:
    CViaje();
    CViaje(string d, string p, CChofer c):destino(d),partida(p),chofer(c){};
    ~CViaje();

    void SetDestino(string destino){
        this->destino=destino;
    }

    void SetPartida(string partida){
        this->partida=partida;
    }

    void SetChofer(CChofer chofer){
        this->chofer=chofer;
    }

    string GetDestino(){
        return destino;
    }

    string GetPartida(){
        return partida;
    }
    
    CChofer GetChofer(){
        return chofer;
    }

    int GetAsignado(){
        int pos=0;
        for (int i = 0; i < choferes.getTamano(); i++)
        {
        if (choferes.getInicio()->getDato().GetDisponible() && this->partida==choferes.getInicio()->getDato().GetDistrito())
        {
            cout<<"\nNombre: "<<choferes.encontrar(i).GetNombre();
        }else
            choferes.setInicio(choferes.getInicio()->getNext());
        }
        cout<<"Que chofer deseas: ";cin>>pos;
        return pos;
        }
        
};

