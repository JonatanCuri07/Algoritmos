#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
/*
int main()
{
    int a,f;
        auto factorial = [&](int a, int fact){
            if(a<0) fact =0;
            else if(a==0) fact=1;
            else{
                 for (int i = 1; i <= a; i++){
                 fact = fact*i;
      }
      cout<<fact;
   }
    };
    cin>>a;
    factorial(a,1);
}
*/
int main()
{
    int num;
    auto fib=[](int num){
    int a,b, c, cont;
    a = 0;
    b = 1;
    c = 0;
    cont = 0;
    while (cont < num) {
        a = b;
        b = c;
        c = a+b;
        cont = cont+1;
    }   

    cout<<c;
    };
    cin>>num;
    cout<<"El numero en esa posicion es: ";fib(num);
}
