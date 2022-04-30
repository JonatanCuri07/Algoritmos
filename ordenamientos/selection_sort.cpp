#include <iostream>
using namespace std;

template <typename T>
void exchange(T *a, T *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

template <typename T>
void selectionsort(T conjunto[], int n){
    int k, menor;
    int i,j;
    for (int i = 0; i < n-1; ++i)
    {
        k=i;
        menor = conjunto[i];
        for (int j = i+1; j < n; j++)
        {
            if (conjunto[j]<menor)
            {
                menor = conjunto[j];
                k=j;
            }
            
        }
        conjunto[k]=conjunto[i];
        conjunto[i]=menor;
    
        //desordenados
        cout<<endl;
        int p;
        for (p = 0; p <= i; p++)
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
template <typename T>
void show(T baraja[],int t)
{
    for (int i = 0; i < t; i++)
    {
        cout<<baraja[i]<<" ";
    }
    cout<<endl;
}

int main(){
    //desordenamiento
    int baraja[] = {10,4,12,6,23,13,2,5};
    int t = sizeof(baraja)/sizeof(baraja[0]);
    
    show(baraja,t);
    selectionsort(baraja,t);
    show(baraja,t);
    

}