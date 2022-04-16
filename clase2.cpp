#include <iostream>
using namespace std;

template<class T>
class CCuadrado
{
private:
    T lado;
public:
    CCuadrado(T l){lado = l;};
    ~CCuadrado();

    T area()
    {
        return lado * lado;
    }
};

/*
template<typename numero>
numero suma(numero a,numero b){
    return a+b;
}
*/

int main()
{
    CCuadrado<double> *o = new CCuadrado<double>(11.3);
    cout << o->area();
    return 0;
}
