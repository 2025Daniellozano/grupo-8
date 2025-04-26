#include <iostream>
using namespace std;

struct Cliente {
    string nombre;
    int minutos;
    int costo;
    int tipoLlamada; // 1 = Local, 2 = Larga distancia, 3 = Celular
};

int main() {
    int c;
    cout << "Ingrese el número de llamadas:\n";
    cin >> c;
    Cliente listaClientes[c];
    int total = 0;

    for (int x = 0; x < c; x++) {
        cout << "Ingrese el nombre del cliente:\n";
        cin >> listaClientes[x].nombre;
        cout << "Seleccione el tipo de llamada:\n";
        cout << "1. Local ($35 por minuto)\n";
        cout << "2. Larga distancia ($380 por minuto)\n";
        cout << "3. Celular ($999 por minuto)\n";
        cin >> listaClientes[x].tipoLlamada;
        cout << "Ingrese los minutos de la llamada:\n";
        cin >> listaClientes[x].minutos;

        if (listaClientes[x].tipoLlamada == 1) {
            listaClientes[x].costo = listaClientes[x].minutos * 35;
        } else if (listaClientes[x].tipoLlamada == 2) {
            listaClientes[x].costo = listaClientes[x].minutos * 380;
        } else if (listaClientes[x].tipoLlamada == 3) {
            listaClientes[x].costo = listaClientes[x].minutos * 999;
        } else {
            cout << "Tipo de llamada inválido. Se asignará costo 0.\n";
            listaClientes[x].costo = 0;
        }

        total += listaClientes[x].costo;
    }

    cout << "\nTotal recaudado: $" << total << endl;
    cout << "Promedio por llamada: $" << total / c << endl;
}



