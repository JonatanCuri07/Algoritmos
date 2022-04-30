#ifndef LISTA_HPP_
#define LISTA_HPP_

#include <iostream>
#include <vector>
#include <functional>
#include <fstream>
using namespace std;

template<typename T>
class Lista
{
    struct Nodo
    {
        Nodo* next;
        T elem;
        Nodo(T elem, Nodo* next=nullptr):elem(elem), next(next){}
    };
private:
    Nodo*head;
    int len;
public:
    Lista():head(nullptr), len(0) {}
    ~Lista() {
        Nodo* currentNode = this->head;
        while (currentNode)
        {
            Nodo* aux = currentNode->next;
            delete currentNode;
            currentNode = aux;
        }
    }
    int size()
    {
        return len;
    }
    bool empty()
    {
        return len == 0;
    }
    
    void addfirst(T elem)
    {
        head= new Nodo(elem,head);
        len++;
    }
    void addpos(T elem,int pos)
    {
        if (pos<0 || pos>len)
              return;
        if (pos == 0)
              addfirst(elem);
        else
        {
            Nodo* aux = head;
            for (int i = 1; i < pos; i++)
            {
                aux = aux->next;
            }
            aux->next = new Nodo(elem, aux->next);
            len++;
        }
    }
    void addlast(T elem)
    {
        addpos(elem, len);
    }

    void removefirst()
    {
        if (len > 0)
        {
            Nodo* aux = head;
            head = head->next;
            delete aux;
            --len;
        }
    }
    void removepos(int pos)
    {
        if (pos<0 || pos>len)
            return;
        if (pos == 0)
            removefirst();
        else
        {
            Nodo* aux = head;
            for (int i = 0; i < pos-1; i++)
            {
                aux = aux->next;
            }
            Nodo* aux2 = aux->next;
            aux->next = aux2->next;
            delete aux2;
            --len;
        }
    }
    void removelast()
    {
        removepos(len - 1);
    }

    void editfirst(T elem)
    {
        if (len > 0)
        {
            head->elem = elem;
        }
    }
    void editpos(int pos,T elem)
    {
        if (pos < 0 || pos >= len)
            return;
        Nodo* aux = head;
        for (int i = 0; i < pos; i++)
        {
            aux = aux->next;
        }
        aux->elem = elem;
    }
    void editlast(T elem)
    {
        editpos(len - 1, elem);
    }

    T getfirst()
    {
        if (len > 0)
        {
            return head->elem;
        }
        else
            - .0;
    }
    T get(int pos)
    {
        Nodo* aux = head;
        for (int i = 0; i < pos; i++)
        {
            aux = aux->next;
        }
        return aux->elem;
    }
    T getlast()
    {
        return get(len - 1);
    }

    void find(T elem)
    {
        Nodo* aux = head;
        bool found=false;
        for (int i = 0; i < len; i++)
        {
            if (aux->elem == elem)
            {
                cout<<"El elemento fue encontrado en la posicion: "<< i<<endl;
                found = true;
                return;
            }
            aux = aux->next;
        }
        if(found==false)
            cout << "El elemento no fue encontrado"<<endl;
    }

    void mostrarCri(std::function<void(T)> crit)
    {
        Nodo* aux = head;
       for (int i = 0; i < len; i++)
        {
            crit(aux->elem);
            aux = aux->next;
        }
    }

     void Exportar_chofer(std::function<string(T)> crit)
    {
        ofstream o;
        o.open("choferes.txt");
        Nodo* aux = head;
       for (int i = 0; i < len; i++)
        {
            o<<crit(aux->elem)<<"\n";
            aux = aux->next;
        }
        o.close();
    }
};



#endif 
