#include <iostream>
#include "Headers/Lista.hpp"

int main()
{
    Lista<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(7);
    a.push_back(2);
    a.push_back(6);
    a.quick_sort();
    a.mostrar_criterio();
}