#include "red.h"

void Red::agregarEnrutador(const string& nombre) {
    if (enrutadores.find(nombre) == enrutadores.end()) {
        enrutadores[nombre] = Enrutador(nombre);
    }
}

void Red::eliminarEnrutador(const string& nombre) {
    enrutadores.erase(nombre);

    for (auto& [nombreEnrutador, enrutador] : enrutadores) {
        map<string, float>& tabla = enrutador.getTabla();
        auto it = tabla.find(nombre);
        if (it != tabla.end()) {
            tabla.erase(it);
        }
    }
}

void Red::agregarRuta(const string& origen, const string& destino, float costo) {
    if (enrutadores.find(origen) == enrutadores.end()) {
        enrutadores[origen] = Enrutador(origen);
    }
    if (enrutadores.find(destino) == enrutadores.end()) {
        enrutadores[destino] = Enrutador(destino);
    }

    enrutadores[origen].costoRuta(destino, costo);
    enrutadores[destino].costoRuta(origen, costo);

    cout << "Ruta agregada: " << origen << " -> " << destino << " (Costo: " << costo << ")" << endl;
}


void Red::cargarDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo " << nombreArchivo << "\n";
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        istringstream streamLinea(linea);
        string origen, destino;
        float costo;

        if (streamLinea >> origen >> destino >> costo) {
            agregarRuta(origen, destino, costo);
        }
    }

    archivo.close();
}

void Red::caminoMasCorto(string origen, string destino) {
    if (enrutadores.find(origen) == enrutadores.end() || enrutadores.find(destino) == enrutadores.end()) {
        cout << "Uno de los enrutadores no existe en la red." << endl;
        return;
    }

    map<string, float> distancias;
    map<string, string> anterior;
    set<pair<float, string>> fila;

    for (const auto &enrutador : enrutadores) {
        distancias[enrutador.first] = numeric_limits<float>::infinity();
    }
    distancias[origen] = 0;
    fila.insert({0, origen});

    while (!fila.empty()) {
        auto actual = *fila.begin();
        fila.erase(fila.begin());
        string enrutadorActual = actual.second;

        if (enrutadorActual == destino) {
            break;
        }

        for (const auto &vecino : enrutadores[enrutadorActual].getTabla()) {
            string enrutadorVecino = vecino.first;
            float costoRuta = vecino.second;

            if (distancias[enrutadorActual] + costoRuta < distancias[enrutadorVecino]) {
                fila.erase({distancias[enrutadorVecino], enrutadorVecino});
                distancias[enrutadorVecino] = distancias[enrutadorActual] + costoRuta;
                anterior[enrutadorVecino] = enrutadorActual;
                fila.insert({distancias[enrutadorVecino], enrutadorVecino});
            }
        }
    }

    if (distancias[destino] == numeric_limits<float>::infinity()) {
        cout << "No hay un camino disponible desde " << origen << " hasta " << destino << "." << endl;
    } else {
        cout << "El costo minimo desde " << origen << " hasta " << destino << " es: " << distancias[destino] << endl;
        cout << "El camino es: ";

        vector<string> camino;
        for (string enrutador = destino; enrutador != origen; enrutador = anterior[enrutador]) {
            camino.push_back(enrutador);
        }
        camino.push_back(origen);

        for (auto it = camino.rbegin(); it != camino.rend(); ++it) {
            cout << *it;
            if (it + 1 != camino.rend()) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
}


void Red::mostrarRed() const {
    for (const auto& [nombre, enrutador] : enrutadores) {
        enrutador.mostrarTabla();
    }
}

void Red::borrarRed() {
    enrutadores.clear();
    cout << "Todos los datos de la red han sido borrados." << endl;
}

