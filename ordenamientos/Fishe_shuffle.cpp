#include <iostream>
using namespace std;

template <typename T>
void exchange(T *a, T *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

template <typename T>
void merge(T conjunto[], int n){
    for (int i = 0; i < n; i++)
    {
        int j= rand() % (i+1);
        exchange(&conjunto[j],&conjunto[i]);        
    }
    
}

int main(){
    //desordenamiento
    srand(time(NULL));
    char baraja[] = {'A','B','C','D','E'};
    int t = 5;
    
    merge(baraja,t);

    for (int i = 0; i < t; i++)
    {
        cout<<"baraja "<<i+1<<": "<<baraja[i]<<endl;
    }

}