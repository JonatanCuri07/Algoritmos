#include <iostream>
#include <vector>   
using namespace std;

struct Node
{
    int dato;
    Node* next;
    Node* prev;
};

Node* primero, * ultimo;
void addNode(){
    Node* nuevo = new Node();
    cout << "Valor: ";
    cin>>nuevo->dato;
    if (primero==nullptr)
    {
        primero= nuevo;
        primero->next=nullptr;
        ultimo = primero;
    }
    else
    {
        ultimo->next = nuevo;
        nuevo->next= nullptr;
        nuevo->prev=ultimo;
        ultimo = nuevo;
    }

}

void showA(){
    Node* actual = new Node();
    actual=primero;
    if(primero!=nullptr)
    {
        while (actual!=nullptr)
        {
            cout<< actual->dato<<" ";
            actual=actual->next;
        }
        
    }else
    {
        cout<<"La lista esta vacia";
    }
}

void showB(){
    Node* actual = new Node();
    actual=ultimo;
    if(ultimo!=nullptr)
    {
        while (actual!=nullptr)
        {
            cout<< actual->dato<<" ";
            actual=actual->prev;
        }
        
    }else
    {
        cout<<"La lista esta vacia";
    }
}

void search()
{
    Node* actual = new Node();
    actual = primero;
    bool wanted = false;
    int valor;
    cout<<"Nodo que se busca: ";
    cin>>valor;
    if(primero!=nullptr)
    {
        while (actual!=nullptr && wanted!=true)
        {
            if (actual->dato==valor)
            {
                cout<<"El numero "<<valor<<" fue encontrado";
                wanted=true;
            }
            actual = actual->next;
        }
        if (!wanted)
        {
            cout<<"No lo encuentro";
        }
        
        
    }else
    {
        cout<<"La lista está vacia";
    }
}

void change(){
Node* actual = new Node();
    actual = primero;
    bool wanted = false;
    int valor;
    cout<<"Nodo que se va a cambiar: ";
    cin>>valor;
    if(primero!=nullptr)
    {
        while (actual!=nullptr && wanted!=true)
        {
            if (actual->dato==valor)
            {
                cout<<"Ingrese nuevo dato: ";
                cin>>actual->dato;
                cout<<"\nYa se cambio de el dato\n";
                wanted=true;
            }
            actual = actual->next;
        }
        if (!wanted)
        {
            cout<<"No lo encuentro :c ";
        }
        
        
    }else
    {
        cout<<"\nLa lista está vacia";
    }

}

void borrar()
{
    Node* actual = new Node();
        actual = primero;
    Node* previo = new Node();
        previo = nullptr;
        bool wanted = false;
        int valor;
        cout<<"Nodo que se va a eliminar: ";
        cin>>valor;
        if(primero!=nullptr)
        {
            while (actual!=nullptr && wanted!=true)
            {
                if (actual->dato==valor)
                {
                    if (actual==primero)//solo un nodo
                    {
                        primero = primero->next;
                        primero->prev=nullptr;
                    }
                    else if(actual==ultimo){//cuando esta al final
                        previo->next= nullptr;
                        ultimo = previo;
                    }
                    else
                    {
                        previo->next=actual->next;
                        actual->next->prev = previo;
                    }
                    cout<<"\nNodo eliminado\n";
                    
                    wanted=true;
                }
                previo = actual;
                actual = actual->next;
            }
            if (!wanted)
            {
                cout<<"No lo encuentro :c ";
            }
            
            
        }else
        {
            cout<<"\nLa lista está vacia";
        }

}


int main(){

    addNode();
    addNode();
    addNode();
    addNode();
    addNode();
    addNode();
    showB();
    cout<<"\n---------------\n";
    search();
    cout<<"\n---------------\n";
    change();
    showB();
    cout<<"\n---------------\n";
    borrar();
    showB();
}