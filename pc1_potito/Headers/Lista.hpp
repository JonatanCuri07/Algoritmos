#ifndef LISTA_HPP_
#define LISTA_HPP_

#include <iostream>
#include <vector>
#include <functional>
#include <fstream>
#include <sstream>
using namespace std;

template<typename T>
class Lista
{
    struct Node
    {
        Node* next;
        T elem;
        Node(T elem, Node* next=nullptr):elem(elem), next(next){}
    };
private:
    Node*head;
	Node *tail;
    int len;
public:
    Lista():head(nullptr), len(0),tail(nullptr) {}
    ~Lista() {
        Node* currentNode = this->head;
        while (currentNode)
        {
            Node* aux = currentNode->next;
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
    
    void push_back(T e){
        if (len==0)
        {
            head=tail=new Node(e);
        }else
        {
            Node* aux= new Node(e);
            tail->next=aux;
            tail=aux;
        }
        
        len++;
    }

    void removefirst()
    {
        if (len > 0)
        {
            Node* aux = head;
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
            Node* aux = head;
            for (int i = 0; i < pos-1; i++)
            {
                aux = aux->next;
            }
            Node* aux2 = aux->next;
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
        Node* aux = head;
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
    T& get(int pos)
    {
        Node* aux = head;
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
        Node* aux = head;
        bool found=false;
        for (int i = 0; i < len; i++)
        {
            if (aux->elem == elem)
            {
                cout<<"El elem fue encontrado en la posicion: "<< i<<endl;
                found = true;
                return;
            }
            aux = aux->next;
        }
        if(found==false)
            cout << "El elem no fue encontrado"<<endl;
    }

    void mostrarCri(std::function<void(T)> crit)
    {
        Node* aux = head;
       for (int i = 0; i < len; i++)
        {
            crit(aux->elem);
            aux = aux->next;
        }
    }

     void Exportar_chofer(std::function<string(T)> crit){
        ofstream o;
        o.open("choferes.txt");
        Node* aux = head;
       for (int i = 0; i < len; i++)
        {
            o<<crit(aux->elem)<<"\n";
            aux = aux->next;
        }
        o.close();
    }
	private:
    Node* parition(Node *first, Node *last,const function<bool(T, T)>& f)
    {
        Node *pivot = first;
        Node *front = first;
        T temp;
        while (front != nullptr && front != last)
        {
            if (f(front->elem,last->elem)){
                pivot = first;
                temp = first->elem;
                first->elem = front->elem;
                front->elem = temp;
                first = first->next;
            }
            front = front->next;
        }
        temp = first->elem;
        first->elem = last->elem;
        last->elem = temp;
        return pivot;
    }
	//_quick_sort para la lista con un criterio(calificacion)
	void _quick_sort(Node* first, Node* last,const function<bool(T, T)>& f) {
        if (first == last)
        {
            return;
        }
        Node *pivot = parition(first, last,f);
        if (pivot != NULL && pivot->next != NULL)
        {
            _quick_sort(pivot->next, last,f);
        }
        if (pivot != NULL && first != pivot)
        {
            _quick_sort(first, pivot,f);
        }
    }


	public:
	void mostrar_criterio(const function<void(T&)>& criterio = [](T e){std::cout << e << "\n";}){
        Node* aux = head;
        while (aux->next != nullptr) {
            criterio(aux->elem);
            aux = aux->next;
        }
        criterio(aux->elem);
    }    

    void quick_sort(const function<bool(T, T)>& f = [](T a, T b){ return a > b; }) {
        _quick_sort(head, tail, f);
    }
};



#endif 
