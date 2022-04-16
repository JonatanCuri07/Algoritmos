#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

class CEscala
{
private:
    int escala;

public:
    CEscala(int _escala): escala(_escala)//escala = _escala;
    {};
    ~CEscala(){};

    void aplicarE(const vector<int> &v){
        for_each(v.begin(), v.end(),
        [=](int d){cout<< escala*d << " ";}
        );
    }
};


int main()
{
    vector<int> datos;
    datos.push_back(4);
    datos.push_back(7);
    datos.push_back(8);
    datos.push_back(9);
    CEscala e(3);
    e.aplicarE(datos);

}