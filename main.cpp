#include "red.h"

#include <iostream>
#include <fstream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()
#include <set>
#include <vector>

using namespace std;

void generarRedAleatoria(const string& nombreArchivo, unsigned int numNodos, unsigned int numRutas) {

    srand(time(0));


    vector<char> nodos;
    for (unsigned int i = 0; i < numNodos; ++i) {
        nodos.push_back('A' + i);
    }

    set<pair<char, char>> rutasGeneradas;

    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }

    for (unsigned int i = 0; i < numRutas; ++i) {
        char origen, destino;
        float costo;

        do {
            origen = nodos[rand() % numNodos];
            destino = nodos[rand() % numNodos];
        } while (origen == destino || rutasGeneradas.count({origen, destino}) > 0);

        costo = static_cast<float>(rand() % 100 + 1);

        rutasGeneradas.insert({origen, destino});
        rutasGeneradas.insert({destino, origen});

        archivo << origen << " " << destino << " " << costo << endl;
        archivo << destino << " " << origen << " " << costo << endl;
    }

    archivo.close();
    cout << "Red aleatoria generada exitosamente" << endl;
}


void menuConfiguracionPorConsola(Red &red) {
    string nombre, origen, destino;
    float costo;
    unsigned int opcion;

    do {
        cout << "------------------------------------" << endl;
        cout << "       MENU CONFIGURAR RED          " << endl;
        cout << "------------------------------------" << endl << endl;
        cout << "1. Agregar enrutador" << endl;
        cout << "2. Eliminar enrutador" << endl;
        cout << "3. Mostrar red" << endl;
        cout << "4. Costo de envio" << endl;
        cout << "5. Regresar al menu principal" << endl;
        cout << "------------------------------------" << endl;

        cout << "Ingrese la opcion: ";
        cin >> opcion;
        cout << endl << endl;

        switch (opcion) {
        case 1:
            cout << "Ingrese " << endl;
            cout << "Nodo origen: ";
            cin >> origen;
            cout << "Nodo destino: ";
            cin >> destino;
            cout << "Costo de ruta: ";
            cin >> costo;
            red.agregarRuta(origen, destino, costo);
            break;
        case 2:
            cout << "Ingrese nombre de enrutador a eliminar: ";
            cin >> nombre;
            red.eliminarEnrutador(nombre);
            cout << "Enrutador eliminado exitosamente." << endl;
            break;
        case 3:
            red.mostrarRed();
            break;
        case 4:
            cout << "Ingrese enrutador origen: ";
            cin >> origen;
            cout << "Ingrese enrutador destino: ";
            cin >> destino;
            red.caminoMasCorto(origen, destino);
            break;
        case 5:
            cout << "Regresando al menu principal..." << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }

        cout << endl;

    } while (opcion != 5);
}

int main() {
    Red red;
    unsigned int opcion;
    string archivo, nombreArchivo;
    unsigned int numNodos, numRutas;

    do {
        cout << "------------------------------------" << endl;
        cout << "          MENU PRINCIPAL            " << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Configurar red desde archivo" << endl;
        cout << "2. Configurar red por consola" << endl;
        cout << "3. Generar red aleatoria" << endl;
        cout << "4. Borrar red" << endl;
        cout << "5. Salir" << endl;
        cout << "------------------------------------" << endl;

        cout << "Ingrese la opcion: ";
        cin >> opcion;
        cout << endl << endl;

        switch (opcion) {
        case 1:
            cout << "Ingrese el nombre del archivo: ";
            cin >> archivo;
            nombreArchivo = "C:/Users/faith/OneDrive/Documents/Info2/P4_Laboratorio/" + archivo;
            red.cargarDesdeArchivo(nombreArchivo);
            menuConfiguracionPorConsola(red);
            break;
        case 2:
            menuConfiguracionPorConsola(red);
            break;
        case 3:
            cout << endl;
            cout << "Ingrese el nombre del archivo: ";
            cin >> archivo;
            nombreArchivo = "C:/Users/faith/OneDrive/Documents/Info2/P4_Laboratorio/" + archivo;
            cout << "Numero de nodos: ";
            cin >> numNodos;
            cout << "Numero de rutas: ";
            cin >> numRutas;
            cout << endl;
            generarRedAleatoria(nombreArchivo, numNodos, numRutas);
            break;
        case 4:
            red.borrarRed();
            break;
        case 5:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }

        cout << endl;

    } while (opcion != 5);

    return 0;
}
