#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//ofstream oentrada;
//ifstream osalida;
//fstream oea;

int main(){
    ifstream salida;
    char caracter;
    
    salida.open("test.txt", ios::in);
    if (salida.is_open())
    {
        while (!salida.eof())
        {
            caracter=salida.get();
            cout<<caracter;
        }
        
    }
}