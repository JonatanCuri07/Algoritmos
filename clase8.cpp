#include <iostream>
#include<iterator>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> conjunto {10,68,15,53,58};
    vector<int>::iterator it = conjunto.begin();
    cout<<"Impresion de datos: "<<endl;
    for (auto x:conjunto)
    {
        cout<< x<<" ";
    }
    cout<<"\nOrdenado: "<<endl;
    sort(conjunto.begin(), conjunto.end());
        for (auto x:conjunto)
    {
        cout<< x<<" ";
    }
    //un iterator es un puntero
    cout<<"\nExperimentos con el conjunto usando el iterator"<<endl;
    cout<<"conjunto.begin(): "<<*(conjunto.begin())<<endl;
    cout<<"conjunto.begin(): "<<*(conjunto.begin()+3)<<endl;
    cout<<"En reversa:"<<endl;
    cout<<"conjunto.begin(): "<<*(conjunto.rbegin())<<endl;
    cout<<"conjunto.begin(): "<<*(conjunto.rbegin()+3)<<endl;
    //simplificado
    //auto it = conjunto.begin();

}