//suma con funcion lambda usando puntero a funcion
#include <iostream>
using namespace std;



int main(){

    auto suma = [](float a, float b){
        return a + b;
    };
    cout << suma(10.5,30.7)<<endl;
	return 0;
}