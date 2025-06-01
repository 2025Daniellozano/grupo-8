#include <iostream>
#include <string>
using namespace std;

struct Linea {
    int totalLlamadas = 0;
    float totalDuracion = 0;
    float totalCosto = 0;

    int matrizLlamadas[3][1] = {{0}, {0}, {0}};

    float calcularCostoLlamada(const string& tipo, float duracion) {
        float costo = 0;
        if (tipo == "Local") {
            costo = duracion * 35;
            matrizLlamadas[0][0]++;
        }
        else if (tipo == "Larga Distancia") {
            costo = duracion * 380;
            matrizLlamadas[1][0]++;
        }
        else if (tipo == "Celular") {
            costo = duracion * 999;
            matrizLlamadas[2][0]++;
        }
        totalLlamadas++;
        totalDuracion += duracion;
        totalCosto += costo;
        return costo;
    }
};

struct GestorLLamadas {
    
    Linea lineas[3];

    void agregarLlamada() {
        int numero;
        string tipo;
        float duracion;

        cout << "Ingrese numero de linea telefonica (0-2): ";
        cin >> numero;
        if (numero < 0 or numero >= 3) {      
            cout << "Error: El numero de linea debe estar entre 0 y 2." << endl;
            return;
        }

        bool tipoValido = false;
        while (!tipoValido) {
            cout << "Ingrese tipo de llamada (Local/Larga Distancia/Celular): ";
            cin >> ws;
            getline(cin, tipo);
            if (tipo == "Local" or tipo == "Larga Distancia" or tipo == "Celular") {
                tipoValido = true;
            }
            else {
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
        cout << "Llamada registrada. Costo:$" << costo << " pesos." << endl;
    }

    void consultarLinea() {
        int numero;
        cout << "Ingrese el numero de linea que quiere consultar (0-2): ";
        cin >> numero;
        if (numero < 0 or numero >= 3) {
            cout << "Error: Linea invalida." << endl;
            return;
        }

        cout << "\n=== Estadisticas de la linea " << numero << " ===" << endl;
        cout << "- Llamadas Locales: " << lineas[numero].matrizLlamadas[0][0] << endl;
        cout << "- Llamadas Larga Distancia: " << lineas[numero].matrizLlamadas[1][0] << endl;
        cout << "- Llamadas a Celular: " << lineas[numero].matrizLlamadas[2][0] << endl;
        cout << "Total general: " << lineas[numero].totalLlamadas << " llamadas" << endl;
        cout << "Duracion total: " << lineas[numero].totalDuracion << " minutos" << endl;
        cout << "Costo total: $" << lineas[numero].totalCosto << " pesos" << endl;
    }

    void consultarConsolidado() {
        int totalLlamadas = 0;
        float totalDuracion = 0;
        float totalCosto = 0;
        for (int i = 0; i < 3; i++) {
            totalLlamadas += lineas[i].totalLlamadas;
            totalDuracion += lineas[i].totalDuracion;
            totalCosto += lineas[i].totalCosto;
        }
        float costoPromedio = (totalDuracion != 0) ? totalCosto / totalDuracion : 0;
        cout << "\n=== Informacion agrupada y consolidada de todas las lineas ===" << endl;
        cout << "Total de llamadas: " << totalLlamadas << endl;
        cout << "Duracion total: " << totalDuracion << " minutos" << endl;
        cout << "Costo total: $" << totalCosto << " pesos" << endl;
        cout << "Costo promedio por minuto: $" << costoPromedio << " pesos/minuto" << endl;
    }

    void reiniciarLlamadas() {
        char confirmacion;
        cout << "¿Quiere reiniciar toda la informacion de llamadas? (s/n): ";
        cin >> confirmacion;
        if (confirmacion == 's' or confirmacion == 'S') {
            for (int i = 0; i < 3; i++) {
                lineas[i] = Linea();
            }
            cout << "Toda la informacion de llamadas ha sido reiniciada correctamente." << endl;
        }
        else {
            cout << "Cancelado. No se reinicio ninguna informacion." << endl;
        }
    }
};

int main() {
    system("cls"); 
    cout << "====================================" << endl;
    cout << "     SISTEMA DE GESTION DE LLAMADAS" << endl;
    cout << "          Autores del programa:" << endl;
    cout << "     - Daniel Rojas Lozano" << endl;
    cout << "     - Jeronimo Vaca Vallejo" << endl;
    cout << "     - Miguel Colmenares Ortiz" << endl;
    cout << "====================================\n" << endl;

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
        switch (opcion) {
        case 1: gestor.agregarLlamada(); break;
        case 2: gestor.consultarLinea(); break;
        case 3: gestor.consultarConsolidado(); break;
        case 4: gestor.reiniciarLlamadas(); break;
        case 5: cout << "Saliendo del programa..." << endl; break;
        default: cout << "Opcion invalida. Intentelo de nuevo." << endl;
        }
    } while (opcion != 5);

    cout << "Gracias por usar el sistema de llamadas <3" << endl;
    return 0;
}
