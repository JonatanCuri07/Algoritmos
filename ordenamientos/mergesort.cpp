#include <iostream>
using namespace std;

void merge(int *v1, int *v2, int *v, int n){
    int i,j,k;
    int mitad = n/2;
    while (i<mitad && j<n-mitad)
    {
        if (v1[i]<v2[j])
        {
            v[k]=v1[i];
            i++;
            k++;
        }
        else
        {
            v[k]=v2[j];
            j++;
            k++;
        } 
    }

    while (i<mitad)
    {
        v[k]=v1[i];
        i++;
        k++;  
    }
    
    while (j<n-mitad)
    {
        v[k]=v2[j];
        j++;
        k++; 
    }
    
    
}

void mergesort(int *v, int n){
    if(n>1){
        int mitad=n/2;
        int *v1 = new int[mitad];
        int *v2 = new int[n-mitad];
        for (int i = 0; i < mitad; i++)
        {
            v1[i]=v[i];
        }

        for(int i= mitad; i<n;i++){
            v2[i-mitad] = v[i];
        }

        mergesort(v1,mitad);

        mergesort(v2,n-mitad);

        merge(v1,v2,v,n);
    }

}

int partition(int *v, int p, int r){
    int x = v[r];
    int i = p-1;
    for (int j = p; j < r; j++)
    {
        if (v[j]<=x)
        {
            i++;
            swap(v[i], v[j]);
        }     
    }
    swap(v[i+1],v[r]);
    return i + 1;
}

void quicksort(int *v, int p, int r){
    int q;
    if(p<r){
        q=partition(v,p,r);

        quicksort(v,p,q-1);

        quicksort(v,q+1,r);
    }
}

void show(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    
}

int main(){

    int conjunto[] = {13,15,19,10,16,25};
    int n=sizeof(conjunto)/sizeof(conjunto[0]);
    show(conjunto,n);
    quicksort(conjunto,0,n-1);
    show(conjunto,n);

}