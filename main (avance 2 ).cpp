#include <iostream>
using namespace std;

int main() {
	int opcion;

	do {
		cout << "\nMenu de opciones:" << endl;
		cout << "1. Opcion 1" << endl;
		cout << "2. Opcion 2" << endl;
		cout << "3. Agregar una llamada" << endl;
		cout << "4. Consultar informacion de una linea telefonica" << endl;
		cout << "5. Consultar informacion consolidada de todas las lineas" << endl;
		cout << "6. Reiniciar informacion de llamadas" << endl;
		cout << "7. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			cout << "Ha seleccionado la Opcion 1." << endl;
			break;
		case 2:
			cout << "Ha seleccionado la Opcion 2." << endl;
			break;
		case 3:
			cout << "funcion agregarLlamada." << endl;
			break;
		case 4:
			cout << "funcion consultarLinea." << endl;
			break;
		case 5:
			cout << "funcion consultarconsolidado." << endl;
			break;
		case 6:
			cout << "funcion reiniciarllamadas." << endl;
			break;
		case 7:
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opcion invalida. Intentelo de nuevo." << endl;
		}
	} while (opcion != 7);

	cout << "Gracias por usar mi app\n";

	return 0;
}
