#include "viajes.hpp"
char menu()
{
    char tecla;

    cout<<"\t\t\tMenu\n";
    cout<<"1: Agregar Pasajero\n";    
    cout<<"2: Agregar Chofer\n";
    cout<<"3: Ingresar Usuario\n";
    cout<<"4: Ingresar Usuario\n";
    cout<<"5: Ingresar Usuario\n";
    cout<<"6: Ingresar Usuario\n";
    cout<<"7: Salir\n";
    cin>>tecla;
    return tecla;
}

int main()
{
    for(bool flag=false; !flag;)
    {
        switch (menu())
        {
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
            flag=true;
            break;
        default:
            break;
        }
    }







}

