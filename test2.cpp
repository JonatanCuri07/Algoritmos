#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>

using namespace std;

class Pacient {
private:
	string name;
	int age;
	int dni;
	string genero;
public:
	Pacient(string name, int age, int dni, string genero);
	 ~Pacient();
	 void SetEdad(int);
	 void SetNombre(string);
	 void Setdni(int);
	 void SetGenero(string);	

	 int GetEdad();
	 string GetNombre();
	 int Getdni();
	 string GetGenero();
};

Pacient::Pacient(string name, int age, int dni, string genero)
{
}
Pacient::~Pacient()
{
}
void Pacient::SetEdad(int age)
{
	this->age = age;
}
void Pacient::SetNombre(string name)
{
	this->name = name;
}
void Pacient::Setdni(int dni)
{
	this->dni = dni;
}
void Pacient::SetGenero(string genero)
{
	this->genero = genero;
}
int Pacient::GetEdad()
{
	return age;
}
string Pacient::GetNombre()
{
	return name;
}
int Pacient::Getdni()
{
	return dni;
}
string Pacient::GetGenero()
{
	return genero;
}

void agregar() {

}
void eliminar() {

}
void listar() {

}
int menu() {
	char op, op2;
	do {
		cout << "<<-------Doctoralia------->>" << endl << endl;
		cout << "1. Registrar Paciente" << endl;
		cout << "2. Agendar Cita" << endl;
		cout << "3. Salir" << endl << endl;
		cout << "ingresa una opci" << char(162) << "n: "; cin >> op;
		if (op != '1' && op != '2' && op != '3') {
			cout << endl << "Error al ingresar valores.Presione una tecla para volver a ingresar..";
			_getch();
			system("cls");
		}
	} while (op !=	 '1' && op != '2' && op != '3');
	//MENU-Registrar Paciente
	if (op == '1') {
		system("cls");
		do {
			cout << "<<-------Registrar Paciente------->>" << endl << endl;
			cout << "1. Agregar" << endl;
			cout << "2. Eliminar" << endl;
			cout << "3. Listar" << endl;
			cout << "4. volver" << endl << endl;
			cout << "ingresa una opci" << char(162) << "n: "; cin >> op2;
			if (op2 != '1' || op2 != '2' || op2 != '3' || op2 != '4') {
				cout << endl << "Error al ingresar valores.Presione una tecla para volver a ingresar..";
				_getch();
			}
		} while (op2 != '1' && op2 != '2' && op2 != '3' && op2 != '4');
		if (op2 == '1')
			agregar();
		if (op2 == '2')
			eliminar();
		if (op2 == '3')
			listar();
		if (op2 == '4')
			return menu();
	}
	if (op == '3') {
		exit(0);
	}
	/*//MENU-Agendar Cita
	if (op = '2') {
	system("cls");
	do {
	cout << "<<-------Agendar Cita------->>" << endl << endl;
	cout << "1. Ingresar DNI" << endl;
	cout << "2. Eliminar" << endl;
	cout << "3. Listar" << endl;
	cout << "4. Salir" << endl << endl;
	cout << "ingresa una opci" << char(162) << "n: "; cin >> op2;
	if (op != '1' && op != '2' && op != '3' && op != '4') {
	cout << endl << "Error al ingresar valores.Presione una tecla para volver a ingresar..";
	_getch();
	}
	} while (op2 != '1' && op2 != '2' && op2 != '3' && op2 != '4');
	if (op2 == '1')
	ingresar();
	if (op2 == '2')
	eliminar();
	if (op2 == '3')
	listar();
	}
	*/
}

int main() {
	ofstream Esc;
	menu();
	_getch();
}