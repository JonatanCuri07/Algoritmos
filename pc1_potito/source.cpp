#include <iostream>
#include <iomanip>
#include "Headers/Pasajero.hpp"
#include "Headers/Agencia.hpp"
using namespace std;
template<typename T>
//just for couting vectors
ostream& operator<<(ostream& os, vector<T>& vec) {
    os << "[ ";
    for (auto e : vec) {
        os << e << " ";
    }
    os << "]";
    return os;
}
ostream& operator<<(ostream& os, Chofer* c) {
    os << "\n{ "
       << setw(10) << c->get_nombre() << " "
       << setw(10) << c->get_coche() << " "
       << setw(10) << c->get_placa() << " "
       << setw(10) << c->get_distrito() << " "
       << " }";
    return os;
}

int menu()
{
	int tecla;

	cout<<"\n\tMenu\n";
    cout<<"1: Agregar Pasajero\n";    
    cout<<"2: Agregar Chofer\n";
    cout<<"3: Mostrar Choferes\n";
    cout<<"4: Mostrar Pasajeros\n";
    cout<<"5: Mostrar Viajes\n";
    cout<<"6: Pedir taxi\n";
	cout<<"7: Exportar pasajeros al txt\n";
	cout<<"8: Exportar choferes al txt\n";
    cout<<"9: Importar pasajeros del txt\n";
	cout<<"10: Importar choferes del txt\n";
	cout<<"11: Mostrar ranking de estrellas\n";
	cout<<"12: Salir\n";
    cin>>tecla;
    return tecla;
}

int main()
{
	Agencia *agent = new Agencia();
	string nombre,placa,coche,distrito;
	ll dni;
	int pos;
	char stop;
	for(bool flag=false; !flag;system("clear"))
		{
			switch(menu())
			{
			case 1:
				cout<<"\nIngrese el nombre: ";cin>>nombre;
				cout<<"Ingrese el dni: ";cin>>dni;
				agent->add_pasajeros(Pasajero(nombre,dni));
				break;
			case 2:
				cout<<"\nIngrese el nombre: ";cin>>nombre;
				cout<<"Ingrese la placa: ";cin>>placa;
				cout<<"Ingrese el coche: ";cin>>coche;
				cout<<"Ingrese el distrito: ";cin>>distrito;
				agent->add_chofer(Chofer(nombre,true,placa,distrito,coche));
				break;
			case 3:
				cout<<"\n";agent->show_chofers();
				cout<<"1 para regresar: ";cin>>stop;
				break;
			case 4:
				cout<<"\n";agent->show_pasajeros();
				cout<<"1 para regresar: ";cin>>stop;
				break;
			case 5:
				cout<<"Escoja el pasajero a revisar: ";cin>>pos;
				cout<<"\n";agent->get_pasajero_front().show_viajes();
				cout<<"\n1 para regresar: ";cin>>stop;
				break;
			case 6:
				if(!agent->chofer_empty())
					{
						string chofer_name="";
						string dist="";
						string dest="";
						bool viaje_creado=false;
						cout<<"Escoge tu partida: ";cin>>dist;
						cout<<"Escoge tu destino: ";cin>>dest;
						cout<<"\n";agent->show_chofer_dist(dist);
						cout<<"\nEscoge tu chofer: ";cin>>chofer_name;
						for(int i=0; i<agent->get_chofer_size();i++){
							if(chofer_name==agent->chofer_registrados->get(i).get_nombre() && agent->chofer_registrados->get(i).get_distrito()==dist
									&& agent->chofer_registrados->get(i).get_disponible())
							{
								if (!agent->pasajero_empty())
								{
									agent->pasajeros_registrados->front().agregar_viaje(dest,dist, agent->get_chofer(i));
									cout<<"Se agrego el viaje correctamente\n";
									viaje_creado=true;
									break;
								}else
								{
									cout<<"No se encuentran pasajeros"<<endl;
								}
								
							}
						}
						if (viaje_creado==false)
						{
							cout<<"Revise correctamente los choferes disponibles\n";
						}
							
					}else{cout<<"No se encuentran choferes"<<endl;}	
					cout<<"\n1 para regresar: ";cin>>stop;		
				break;
			case 7:
				agent->Exportar_Pas();
				break;
			case 8:
				agent->Exportar_Chofer();
				break;
			case 9:
			//importar pasajeros
				agent->Exportar_Pas();
				break;
			case 10:
			//importar choferes
				agent->Exportar_Chofer();
				break;
			case 11:
			//mostrar por criterio de estrellas
				flag=true;
				break;
			case 12:
				flag=true;
				break;
			default:
				break;
			}
		}
	
	delete agent;
	return 0;
}
