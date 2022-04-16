#include<vector>
#include<iterator>
#include<iostream>
#include<algorithm>
//HACER UN RECCORRIDO DESDE DERECHA A LA  IZQUIERDA
//RECORRIDO EN REVERSA
using namespace std;

template <typename T>
class CNodo {
private :
    T dato; //int, double, float, lo quiera el usaurio
    CNodo* siguiente;
public:
    //seters y geters
    T getDato() {
        return dato;
    }
    void setDato(T dato) {
        this->dato = dato;
    }

    CNodo * getSiguiente() {
        return siguiente;
            }

    void setSiguiente(CNodo* siguiente) {
        this->siguiente = siguiente;
    }
    //Contructores  destructores 
    CNodo(T dato, CNodo* siguiente) {
        this->dato = dato;
        this->siguiente = siguiente;
    }
    ~CNodo() {}
    //comportamientos

};

template <typename T>
class ClistaEnlazada {
private:
    int tamanio;
    CNodo<T>  *inicio; //inicio apunta al primer elemento de la lista
public:
    //seters y geters
    int getTamanio() {
        return tamanio;
    }
    void setTamanio(int tamanio) {
        this->tamanio = tamanio;
    }

    CNodo<T>* getInicio() {
        return inicio;
    }

    void setInicio(CNodo<T> *inicio) {
        this->inicio = inicio;
    }
    //constructores
    ClistaEnlazada() {
        this->tamanio = 0;
        this->inicio = nullptr;
    }
    ~ClistaEnlazada() {
        }
    //comportamientos
    void agregaInicio(T valor) {
        CNodo<T>* nuevo = new CNodo<T>(valor, this->inicio);
        this->inicio = nuevo;
        this->tamanio++;

    }
    void agregaFinal(T valor) {
        CNodo<T>* nuevo = new CNodo<T>(valor, nullptr);
            if (this->inicio) //verificar sis  la lista esta vacia
            {
                CNodo<T>* actual = this->inicio; //iniclaizamos en el primer nodo
                while (actual->getSiguiente())
                {

                    actual = actual->getSiguiente();
                }
                actual->setSiguiente(nuevo);
            }
            else { //lista vacia
                this->inicio = nuevo;
            }
        this->tamanio++;
    }

    void agregaPorIndice(int indice, T valor) {
        if (indice >= 0 && indice <= this->tamanio){
            if (indice == 0)
            {
                agregaInicio(valor);
            }
            else if (indice == this->tamanio) {
                agregaFinal(valor);
            }


            else { // la lista ya tenga mas de un elemento
                    CNodo<T>* actual = this->inicio;
                    CNodo<T>* previo;
                    for (int i = 0; i < indice; i++)
                    {
                        previo = actual;  //
                        actual = actual->getSiguiente(); //
                    }
                
                CNodo<T>* nuevo = new CNodo<T>(valor, actual);
                previo->setSiguiente(nuevo);
                this->tamanio++;
            }

        }
        else {
            cout<<"Indice fuera del Limite ";
        }
    }

    void imprimeDatos() {
        //actual es un iterador
        CNodo<T>* actual = this->inicio;
        while (actual != nullptr)
        {
            cout << actual->getDato() << " ";
            actual = actual->getSiguiente();//apuntado elemento a alemento
        }
    }

};



int main()
{
    ClistaEnlazada<int>* o = new ClistaEnlazada<int>();
    o->agregaInicio(10);
    o->agregaFinal(20);
    o->agregaFinal(30);
    o->agregaFinal(40);
    o->agregaFinal(50);
    o->imprimeDatos();
    cout<<"\n";
    o->agregaPorIndice(2,25);
    o->imprimeDatos();

}