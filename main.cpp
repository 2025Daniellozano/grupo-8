#include <iostream>
using namespace std;
int main() {
    int opcion;


    cout << "Menu de opciones:" << endl;
    cout << "1. Opcion 1" << endl;
    cout << "2. Opcion 2" << endl;
    cout << "3. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    
    switch (opcion) {
        case 1:
           cout << "Has seleccionado la Opcion 1." << endl;
            break;
        case 2:
           cout << "Has seleccionado la Opcion 2." << endl;
            break;
        case 3:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
           cout << "Opcion invalida. Intente de nuevo." << endl;
    }
    
    return 0;
}
