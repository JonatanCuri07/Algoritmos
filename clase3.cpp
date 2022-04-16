#include <iostream>
using namespace std;

/*float suma(float a, float b){
    return a+b;
}

float resta(float a, float b){
    return a-b;
}

float division(float a, float b){
    return a/b;
}

float producto(float a, float b){
    return a*b;
}*/

int main()
{
	/*float a, b;
	//Así se declara un puntero a una funcion
	//el puntero se llama operacion
	float (*operacion)(float, float);
	char op;
	cout << "Indique una operacion + - / * : ";
	cin >> op;
	switch (op)
	{
	case '+':
		operacion = suma;
		break;
	case '/':
		operacion = division; //funcion division
		break;
	case '*':
		operacion = producto;
		break;
	case '-':
		operacion = resta;
		break;
	}

	//Usar el puntero y a traves de él
	//pasarle los parametro
	cout << "resultado " << operacion(20.5, 30.5) << endl;*/
    
    float(*suma)(float, float) = [](float a ,float b){ return a+b;};
    cout<<suma(10.5, 30.7) << endl;
	return 0;

}