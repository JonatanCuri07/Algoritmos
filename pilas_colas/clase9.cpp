#include <iostream>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

struct Nodo
{
    int dato;
    Nodo* next;
};

void add(Nodo *&pila, int n)
{
    Nodo *nuevo=new Nodo();
    nuevo->dato=n;
    nuevo->next=pila;
    pila=nuevo;
    cout<<"Se agrego correctamente";
}

void remove(Nodo *&tope, int &n){
    Nodo* actual=tope;
    n = actual->dato;
    tope = actual->next;
    delete actual;
    cout<<"\n"<<n<<" ";
}

void remove_all(Nodo *& tope, int &n){
    while (tope!=nullptr)
    {
        remove(tope,n);
        if (tope!=nullptr)
        {
            cout<<n<<" ";
        }else
        {
            cout<<n<<"."<<endl;
        }
    }  
}

void show(Nodo *&tope){
    Nodo* actual = tope;
    while (actual!=nullptr)
    {
        if (actual!=nullptr)
        {
            cout<<actual->dato<<" ";
        }else{
            cout<<actual->dato<<".";
        }
        actual=actual->next;
    }
    
}

int main()
{
    Nodo* tope = nullptr;
    int n;
    char salir;
    do
    {
        cout<<"\nNumero: ";cin>>n;
        add(tope,n);
        cout<<"\nDesea ingresar otro elemento s/n?";cin>>salir;
    } while (salir!='n');

    do
    {
        remove(tope,n);
        show(tope);
        cout<<"\nDesea quitar otro elemento s/n?";cin>>salir;
    } while (toupper(salir=='s') && tope!=nullptr);
    
}
