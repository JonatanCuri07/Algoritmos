#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void muestra(int i){
    cout<< i << " ";
}

/*int main(){
    int p=2, q=3;
    vector<int> v{ 10,20,30,24,15 };

    for_each(v.begin(),v.end(),[&](int i){//[=] tanto p y q son inmutables
                                          //[&] tanto p y q son mutables
        p++;
        ++q;
        cout<< p*i*q<<" ";});
}*/

/*int main(){
    vector<int> v{ 10,20,30,24,15 };

    sort(v.begin(),v.end(),
    [](int a, int b){
        return a>b;
    }
    );

    for_each(v.begin(),v.end(),[](int i){
        cout<<i<<" ";});
}*/

int main(){
    auto f1 = [](int a, int b) {
        return a+b;
    };
    cout<<f1(4,5)<<endl;
    function<int(int, int)> f2 = [](int a, int b){
        return a+b;
    };
    cout<< f2(4,5)<<endl;

    auto f3 = [](int a) {return a*a;}(10);
    cout<< f3<<endl;
    return 0;
}