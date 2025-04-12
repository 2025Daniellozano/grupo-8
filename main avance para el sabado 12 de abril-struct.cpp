#include <iostream>
using namespace std;

struct Llamada {
    string tipo;
    float duracion;
    float costo;
};

struct Linea {
    int totalLlamadas;
    float totalDuracion;
    float totalCosto;
};

Linea lineas[1000];

float calcularCosto(string tipo, float duracion) {
    if (tipo == "Local") return duracion * 0.5;
    else if (tipo == "Larga Distancia") return duracion * 1.0;
    else if (tipo == "Celular") return duracion * 1.5;
    else return 0;
}

void agregarLlamada() {
    int numero;
    string tipo;
    float duracion;

    cout << "Ingrese numero de linea telefonica (0-999): ";
    cin >> numero;

    cout << "Ingrese tipo de llamada (Local/Larga Distancia/Celular): ";
    cin >> tipo;

    cout << "Ingrese duracion de la llamada en minutos: ";
    cin >> duracion;

    float costo = calcularCosto(tipo, duracion);

    lineas[numero].totalLlamadas++;
    lineas[numero].totalDuracion += duracion;
    lineas[numero].totalCosto += costo;

    cout << "Costo de la llamada: $" << costo << " pesos" << endl;
}

void consultarLinea() {
    int numero;
    cout << "Ingrese el numero de linea a consultar (0-999): ";
    cin >> numero;

    cout << "Numero total de llamadas: " << lineas[numero].totalLlamadas << endl;
    cout << "Duracion total de llamadas: " << lineas[numero].totalDuracion << " minutos" << endl;
    cout << "Costo total de llamadas: $" << lineas[numero].totalCosto << " pesos" << endl;
}

void consultarConsolidado() {
    int totalLlamadas = 0;
    float totalDuracion = 0;
    float totalCosto = 0;
    int i = 0;

    while(i < 1000) {
        totalLlamadas += lineas[i].totalLlamadas;
        totalDuracion += lineas[i].totalDuracion;
        totalCosto += lineas[i].totalCosto;
        i++;
    }

    float costoPromedio = (totalDuracion != 0) ? totalCosto / totalDuracion : 0;

    cout << "\n=== Información consolidada de todas las líneas ===" << endl;
    cout << "Total de llamadas: " << totalLlamadas << endl;
    cout << "Duración total: " << totalDuracion << " minutos" << endl;
    cout << "Costo total: $" << totalCosto << " pesos" << endl;
    cout << "Costo promedio por minuto: $" << costoPromedio << " pesos/minuto" << endl;
}

void reiniciarLlamadas() {
    char confirmacion;

    cout << "¿Está seguro que desea reiniciar toda la información de llamadas? (s/n): ";
    cin >> confirmacion;

    if (confirmacion == 's' || confirmacion == 'S') {
        int i = 0;
        while (i < 1000) {
            lineas[i].totalLlamadas = 0;
            lineas[i].totalDuracion = 0;
            lineas[i].totalCosto = 0;
            i++;
        }
        cout << "La información de llamadas ha sido reiniciada correctamente." << endl;
    } else {
        cout << "Operación cancelada. No se ha reiniciado ninguna información." << endl;
    }
}


