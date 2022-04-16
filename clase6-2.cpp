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
    Nodo* actual = new Nodo();
    actual=lista;
    while (actual!=nullptr)
    {
        cout<<actual->dato << " - ";
        actual=actual->next;
    }
    
}

void buscar(int buscado)
{
    bool resultado=false;
    Nodo* actual = new Nodo();
    actual = lista;
    while ((actual!=nullptr) && (actual->dato<=buscado))
    {
        if (actual->dato==buscado)
        {
            resultado= true;
        }
        actual = actual->next;
    }
    if (resultado==true)
    {
        cout<<"El resultado se encuentra en la lista"<<endl;
    }else{
        cout<<"El dato no se encuentra en la lista"<<endl;
    }
    
    
}

void eliminar(int eliminado){

    if (lista!=nullptr)
    {
        Nodo* ptrborrar;
        Nodo* anterior=nullptr;
        ptrborrar=lista;
        while ((ptrborrar!=nullptr) && (ptrborrar->dato!=eliminado))
        {
            anterior=ptrborrar;
            ptrborrar=ptrborrar->next;
        }
        if (ptrborrar=nullptr)
        {
            cout<<"El elemento no se esta en la lista"<<endl;
        }
        else if (anterior==nullptr)
        {
            lista=lista->next;
            delete ptrborrar;
        }else
        {
            anterior->next=ptrborrar->next;
            delete ptrborrar;
        }        
    }
}


int main()
{
    int d;
    char si;
    while (true)
    {
        cout<<"Inserte un dato: "; cin>>d;
        addNodoLista(d);
        cout<<"Desea insertar otro dato? ";cin>> si;
        if (toupper(si)=='N')
        {   
            break;
        }
        
    }
    
    show();
    
    cout<<"\nDato a buscar: ";cin>>d;
    buscar(d);

    cout<<"\nDato a eliminar: ";cin>>d;
    eliminar(d);
    cout<<"Nueva lista: ";
    show();
}