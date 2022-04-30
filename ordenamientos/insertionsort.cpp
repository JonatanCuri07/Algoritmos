#include <iostream>
using namespace std;

template <typename T>
void exchange(T *a, T *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

template <typename T>
void insertionsort(T conjunto[], int n){
   int k,aux;
   for (int i = 1; i < n; i++)
   {
       aux=conjunto[1];
       k = i-1;
       while (k >= 0 && aux< conjunto[k])
       {
           conjunto[k+1]=conjunto[k];
           k--;
       }
       conjunto[k+1] = aux;

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
    insertionsort(baraja,t);
    show(baraja,t);
    

}