#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//ofstream oentrada;
//ifstream osalida;
//fstream oea;

int main(){
    ifstream salida;
    string linea;
    
    salida.open("test.txt", ios::in);
    if (salida.is_open())
    {
        while (!salida.eof())
        {
            getline(salida,linea);
            cout<<linea<<endl;
        }
        
    }
}