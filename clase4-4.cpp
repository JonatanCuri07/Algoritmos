#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

int F_recursivo(int n){
    if (n == 0 || n == 1)
    {
        return 1;
    }else{
        return n* F_recursivo(n-1);
    };    
}

int main()
{
   cout<<F_recursivo(4);
}
