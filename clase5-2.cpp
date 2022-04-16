#include <iostream>
#include <fstream>
using namespace std;
//ofstream oentrada;
//ifstream osalida;
//fstream oea;

int main(){
    ifstream salida;
    int notas;
    
    salida.open("test.txt", ios::in);
    if(salida.is_open())
    {
        /* while (salida>>notas)   //cada dato lo ponemos a la variable notas
        {
            cout<<notas<<endl;
        }*/
        while (!salida.eof())
        {   
            salida>>notas;
            if (notas>15)
            {
            cout<<notas<<endl;
            }
            
        }
        
        salida.close();
    }

}