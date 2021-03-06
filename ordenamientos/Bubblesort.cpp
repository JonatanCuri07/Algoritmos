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
    int i,j;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (conjunto[i]>conjunto[j])
            {
                exchange(&conjunto[i],&conjunto[j]);            
            }
        }
        int p;
        for (p = 0; p <= i; p++)
        {
            cout<<conjunto[p]<< " ";
        }
        cout<<" |";
        //desordenados
        for (int q = p; q < n; q++)
        {
            cout<<conjunto[q]<< " ";
        }
        cout<<" |\n";
    }
}

int main(){
    //desordenamiento
    int baraja[] = {10,4,12,6,43};
    int t = sizeof(baraja)/sizeof(baraja[0]);
    
    bubblesort(baraja,t);

    for (int i = 0; i < t; i++)
    {
        cout<<"\nbaraja "<<i+1<<": "<<baraja[i]<<endl;
    }

}