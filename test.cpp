#include <iostream>
using namespace std;

class CPunto
{
private:
    int x,y;
public:
    CPunto(){
        x=4;
        y=10;
    };
    ~CPunto(){};

void show(){
    cout<<"X: "<<x<<endl;
    cout<<"Y: "<<y<<endl;

}

};

int main(){
    /*CPunto o;     //memoria estatica*/
    CPunto *o = new CPunto();//memoria dinamica
    o->show();

     
}