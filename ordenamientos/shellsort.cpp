#include <iostream>
using namespace std;

template <typename T>
void exchange(T *a, T *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

template <typename T>
void shellsort(T conjunto[], int n){
   int i,j,k,tmp;
   int intervalo = n/2;

   while (intervalo>0)
   {
       for (int i = intervalo; i < n; i++)
       {
            j=i-intervalo;   
            while (j>=0)
            {
                k = j+ intervalo;
                if (conjunto[j]<conjunto[k])
                {
                    j=-1;
                }else
                {
                    tmp=conjunto[j];
                    conjunto[j]=conjunto[k];
                    conjunto[k]=tmp;
                    j = j - intervalo;
                }   
            }    
       }
       intervalo = intervalo / 2; 


   //desordenados
        cout<<endl;
        int p;
        for (p = 0; p < i; p++)
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
    shellsort(baraja,t);
    show(baraja,t);
    

}