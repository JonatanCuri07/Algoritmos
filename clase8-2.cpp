#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
class CNodo
{
private:
    T dato;
    CNodo<T>* next;
public:
    CNodo(T dato, CNodo<T>* next){
        this->dato=dato;
        this->next=next;
    }
    ~CNodo(){};

    T getDato(){
        return dato;
    }
    void setDato(T dato){
        this->dato=dato;
    }

    CNodo<T>* getNext(){
        return next;
    }

    void setNext(CNodo<T>* next){
        this->next=next;
    }
};

template <typename T>
class CListaEnlazada
{
private:
    int tamano;
    CNodo<T>* inicio;
public:
    CListaEnlazada(){
        this->tamano=0;
        this->inicio=nullptr;
    }
    ~CListaEnlazada(){};


    int getTamano(){
        return tamano;
    }
    void setTamano(int tamano){
        this->tamano=tamano;
    }

    CNodo<T>* getInicio(){
        return inicio;
    }

    void setInicio(CNodo<T>* inicio){
        this->inicio=inicio;
    }

    void agregaInicio(T valor){
        CNodo<T>* nuevo=new CNodo<T>(valor, this->inicio);
        this->inicio=nuevo;
        this->tamano++;
    }

    void agregaFinal(T valor){
        CNodo<T>* nuevo=new CNodo<T>(valor, nullptr);
        if (this->inicio)//si la lista está vacia
        {
            CNodo<T>* actual= this->inicio;
            while(actual->getNext())
            {
                actual=actual->getNext();
            }
            actual->setNext(nuevo);
        }else//lista vacia
        {
            this->inicio=nuevo;
            this->tamano++;
        }
        this->tamano++;
    }

    void agregarPos(int indice, T valor){
        if (indice>= 0 && indice<= this->tamano)
        {
            if (indice == 0)
            {
                agregaInicio(valor);
            }
            else if(indice==this->tamano){
                agregaFinal(valor);
            }
            else
            {
                CNodo<T>* actual = this->inicio;
                    CNodo<T>* previo;
                    for (int i = 0; i < indice; i++)
                    {
                        previo = actual;  //
                        actual = actual->getNext(); //
                    }
                
                CNodo<T>* nuevo = new CNodo<T>(valor, actual);
                previo->setNext(nuevo);
                this->tamano++;
            }
            
            
        }else
        {
            cout<<"\nIndice fuera del limite;"<<endl;
        }
        
    }

    T encontrar(int p){
        int pos=0;
        CNodo<T>* nuevo = inicio;
        while (nuevo!=nullptr)
        {
            if (p==pos)
            {
                return nuevo->getDato();
            }
            nuevo = nuevo->getNext();
            pos++;
        }
        return 0;
    }

    void show(){
        CNodo<T>* actual = this->inicio;

        while (actual !=nullptr)
        {
            cout<<actual->getDato()<<" ";
            actual = actual->getNext();
        }
        
    }
};

int main(){
    CListaEnlazada<int>* o = new CListaEnlazada<int>();
    o->agregaInicio(15);
    o->agregaFinal(20);
    o->agregaFinal(25);
    o->agregaFinal(30);
    o->agregaFinal(35);
    o->show();
    cout<<"\n";
    o->agregarPos(1,23);
    o->show();
    cout<<"\n"<<o->getTamano();
    cout<<"\n\nEncontrar en la posición: ";
    cout<<"\n"<<o->encontrar(3)<<"\n";
}
