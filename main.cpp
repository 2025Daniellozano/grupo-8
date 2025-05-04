#include <iostream>
#include <string>
using namespace std;

struct Llamada {
    string tipo;
    float duracion;
    float costo;
};

struct Linea {
    int totalLlamadas = 0;
    float totalDuracion = 0;
    float totalCosto = 0;

    float calcularCostoLlamada(const string& tipo, float duracion) {
        if (tipo == "Local")           return duracion * 35;
        else if (tipo == "Larga Distancia") return duracion * 380;
        else if (tipo == "Celular")     return duracion * 999;
        else                               return 0;
    }
};

struct GestorLLamadas {
    Linea lineas[1000];

    void agregarLlamada() {
        int numero;
        string tipo;
        float duracion;

        cout << "Ingrese numero de linea telefonica (0-999): ";
        cin >> numero;
        if (numero < 0 || numero >= 1000) {
            cout << "Error: El numero de linea debe estar entre 0 y 999." << endl;
            return;
        }

        bool tipoValido = false;
        while (!tipoValido) {
            cout << "Ingrese tipo de llamada (Local/Larga Distancia/Celular): ";
            cin >> tipo;
            if (tipo == "Local" || tipo == "Larga Distancia" || tipo == "Celular") {
                tipoValido = true;
            } else {
                cout << "Error: Tipo de llamada no valido. Intente de nuevo." << endl;
            }
        }

        cout << "Ingrese duracion de la llamada en minutos: ";
        cin >> duracion;
        if (duracion <= 0) {
            cout << "Error: La duracion debe ser mayor a 0." << endl;
            return;
        }

        float costo = lineas[numero].calcularCostoLlamada(tipo, duracion);
        lineas[numero].totalLlamadas++;
        lineas[numero].totalDuracion += duracion;
        lineas[numero].totalCosto += costo;

        cout << "Llamada registrada. Costo: $" << costo << " pesos." << endl;
    }

    void consultarLinea() {
        int numero;
        cout << "Ingrese el numero de linea a consultar (0-999): ";
        cin >> numero;
        if (numero < 0 || numero >= 1000) {
            cout << "Error: Linea invalida." << endl;
            return;
        }
        cout << "Numero total de llamadas: " << lineas[numero].totalLlamadas << endl;
        cout << "Duracion total de llamadas: " << lineas[numero].totalDuracion << " minutos" << endl;
        cout << "Costo total de llamadas: $" << lineas[numero].totalCosto << " pesos" << endl;
    }

    void consultarConsolidado() {
        int totalLlamadas = 0;
        float totalDuracion = 0;
        float totalCosto = 0;
        for (int i = 0; i < 1000; i++) {
            totalLlamadas += lineas[i].totalLlamadas;
            totalDuracion += lineas[i].totalDuracion;
            totalCosto += lineas[i].totalCosto;
        }
        float costoPromedio = (totalDuracion != 0) ? totalCosto / totalDuracion : 0;
        cout << "\n=== Informacion consolidada de todas las lineas ===" << endl;
        cout << "Total de llamadas: " << totalLlamadas << endl;
        cout << "Duracion total: " << totalDuracion << " minutos" << endl;
        cout << "Costo total: $" << totalCosto << " pesos" << endl;
        cout << "Costo promedio por minuto: $" << costoPromedio << " pesos/minuto" << endl;
    }

    void reiniciarLlamadas() {
        char confirmacion;
        cout << "¿Esta seguro que desea reiniciar toda la informacion de llamadas? (s/n): ";
        cin >> confirmacion;
        if (confirmacion == 's' || confirmacion == 'S') {
            for (int i = 0; i < 1000; i++) {
                lineas[i] = Linea();
            }
            cout << "La informacion de llamadas ha sido reiniciada correctamente." << endl;
        } else {
            cout << "Operacion cancelada. No se ha reiniciado ninguna informacion." << endl;
        }
    }
};

int main() {
    GestorLLamadas gestor;
    int opcion;
    do {
        cout << "\nMenu de opciones:" << endl;
        cout << "1. Agregar una llamada" << endl;
        cout << "2. Consultar informacion de una linea telefonica" << endl;
        cout << "3. Consultar informacion consolidada de todas las lineas" << endl;
        cout << "4. Reiniciar informacion de llamadas" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion) {
            case 1: gestor.agregarLlamada(); break;
            case 2: gestor.consultarLinea(); break;
            case 3: gestor.consultarConsolidado(); break;
            case 4: gestor.reiniciarLlamadas(); break;
            case 5: cout << "Saliendo del programa..." << endl; break;
            default: cout << "Opcion invalida. Intentelo de nuevo." << endl;
        }
    } while(opcion != 5);

    cout << "Gracias por usar el sistema de llamadas" << endl;
    return 0;
}
