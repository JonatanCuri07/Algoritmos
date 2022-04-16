#include <iostream>
#include <functional>
using namespace std;

/*int main()
{
    auto duplicarDosVeces = [](int x){
        return [](int y){
            return y * 2;
            }(x)*2;
    };

    cout<< "a: "<<duplicarDosVeces(5) <<endl;
}*/

//funciones de orden superior
int main(){
    auto add= [](int x)->function<int(int)> {
        return [=](int y){
            return x*y;
        };
    };
    
    auto ordenSup = [](const function<int(int)> &f, int z) {
            return  f(z);
    };

    auto resp = ordenSup(add(2),3);

    cout<< "a: "<< resp <<endl;
}