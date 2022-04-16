#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream entrada;
    int numero = 100;
    char caracter = 'S';
    double numeroReal = 15.8;
    entrada.open("miArchivo.txt", ios::out);
    if (entrada.is_open())
    {
        entrada<<"Edad: "<<numero<<endl;
        entrada<<"Sexo: "<<caracter<<endl;
        entrada<<"Peso: "<<numeroReal<<endl;
        entrada.close();
    }
    else
    {
        cout<<"!!!!!Error al abrir el archivo!!!!!!!!";
    }
    
    
}