#include <iostream>

#include<string>

#include<fstream> //libreria para lectura y escritura de datos

using namespace std;

//ARCHIVOS BINARIOS

//ofstream osalida;

//ifstream oentrada;

//fstream oea;

typedef struct Persona

{

  int dni;

  int edad;

  double peso;

  double altura;

};



void main() {

  ifstream entrada;

  Persona p;

   //abrir el achivo

  entrada.open("miArchivo.txt", ios::in||ios::binary);

  if (entrada.is_open())

  { //10 15 18 15 19

    entrada.seekg(0 * sizeof(p), ios::beg );

    entrada.seekg(1* sizeof(p), ios::beg );

    entrada.read((char*)&p, sizeof(Persona)); //lso datos en p

    cout << p.altura << endl;

    cout << p.dni << endl;

    cout << p.edad << endl;

    cout << p.peso << endl;

    entrada.close();

  }

  system("pause>>NULL");

}