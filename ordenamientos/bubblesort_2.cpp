#include <iostream>
using namespace std;

template <typename T>
void exchange(T *a, T *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

template <typename T>
void bubblesort(T conjunto[], int n){
    bool ordenado;
    for (int i = 0; i < n-1; i++)
    {
        ordenaod = true;
        for (int j = 0; j < n-i-1; j++)
        {
            if (conjunto[j]>conjunto[j+1])
            {
                exchange(&conjunto[j],&conjunto[j+1]);         
                ordenado = false;   
            }
            if (ordenado)
                break;
            
        }
        //desordenados
        int p;
        for (p = 0; p <= n-i-1; p++)
        {
            cout<<conjunto[p]<< " ";
        }
        cout<<" |";
        //ordenados
        for (int q = p; q < n; q++)
        {
            cout<<conjunto[q]<< " ";
        }
        cout<<" |\n";
    }
}

int main(){
    //desordenamiento
    int baraja[] = {10,4,12,6,43,13,25,33,54,2,5};
    int t = sizeof(baraja)/sizeof(baraja[0]);
    
    bubblesort(baraja,t);

    for (int i = 0; i < t; i++)
    {
        cout<<"\nbaraja "<<i+1<<": "<<baraja[i]<<endl;
    }

}