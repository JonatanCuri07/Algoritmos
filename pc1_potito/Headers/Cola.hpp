#ifndef __COLA_HPP__
#define __COLA_HPP__
#include <iostream>
using namespace std;
template <class T>
class Node{
	public: 
	
		T v; 
		Node<T> *next;
		
		Node(T x)
		{
			v = x;
			next = NULL;
		}
		
};
template <class T>
class Queue{
	Node<T> *start;
	int size;
	Node<T> *end; 
	public:
		Queue()
		{
			start = end = NULL;
			this->size = 0;
		}
	
		bool empty()
		{
			return start==NULL;
		}

		void push(T v)
		{
			Node<T> *temp = new Node<T>(v);
			if(empty())
			{
				start = end = temp;
				this->size++;
			}
			else
			{
				end->next = temp;
				end = temp;
				this->size++;
			}
		}

		T front()
		{
			return start->v;	
		} 

		void pop()
		{
			if(empty())
			{
				cout<<"Queue is Empty"<<endl;
			}
			else if(start==end)
			{
	
				delete start;
				start = end = NULL;
				this->size--;
			}
			else
			{

				Node<T> *temp = start;
				start = start->next;
				this->size--;
				delete temp;
			}
		}

		int get_size(){return this->size;}

		void Exportar(std::function<string(T)> crit)
    	{
        ofstream o;
        o.open("pasajeros.txt");
        Node<T>* aux = start;
			for (int i = 0; i < size; i++)
			{
				o<<crit(aux->v)<<"\n";
				aux = aux->next;
			}
			o.close();
		}
	
};
#endif

