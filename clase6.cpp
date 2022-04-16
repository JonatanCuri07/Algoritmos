#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
    int dato;
    Nodo* next;
};

Nodo* lista; //lista siempre va a tener la direccion del ultimo nodo insertado

void addNodoLista(int n){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = n;

    //
    Nodo* aux1 = lista;
    Nodo* aux2;

    //recorrido para buscar la dir o espacio para el nuevo dato
    while ((aux1!=nullptr) && (aux1->dato<=n))
    {
        aux2 = aux1;
        aux1 = aux1->next;
    }

    if (lista==aux1)//si la lista no tiene elementos
    {
        lista=nuevoNodo;
    }else
    {
        aux2->next=nuevoNodo;
    }
    
    
    nuevoNodo->next=aux1;
    
}

void show(){
    
}

int main()
{
    int d;
    cout<<"Inserte dato: ";cin>>d;
    Nodo n1;
    n1.dato=d;
    n1.next=nullptr;
    lista= &n1;


    cout<<"Inserte dato: ";cin>>d;
    Nodo n2;
    n2.dato=d;
    n2.next=&n1;
    lista= &n2;

    cout<<"Inserte dato: ";cin>>d;
    Nodo n3;
    n3.dato=d;
    n3.next=&n2;
    lista= &n3;

}