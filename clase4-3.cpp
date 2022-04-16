#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void negarTodo(vector<T> &v){
    for_each(v.begin(),v.end(),
    [](T d){ d=-d;}
    );
}

template <typename T>
void show(vector<T> &v){
    for_each(v.begin(),v.end(),
    [](T d){ cout<<d<<" ";}
    );
}

int main()
{
    vector<double> datos;
    datos.push_back(4);
    datos.push_back(7);
    datos.push_back(8);
    datos.push_back(9);
    cout<<"Lista de datos: ";
    show(datos);
    negarTodo(datos);
    cout<<endl<<"Lista de datos cambiados: ";
    show(datos);
}