#include <iostream>
#include <vector>   
using namespace std;

struct Node
{
    int dato;
    Node* ptr;
};



int main(){

    Node* n1 = new Node();
    n1->dato = 10;
    Node* n2 = new Node();
    n2->dato = 15;
    n1=n2;
    n1->ptr=n2;
}