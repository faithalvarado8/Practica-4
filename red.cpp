#include "red.h"

void Red::agregarEnrutador(const string& nombre) {
    if (enrutadores.find(nombre) == enrutadores.end()) {
        enrutadores[nombre] = Enrutador(nombre);
    }
}

void Red::eliminarEnrutador(const string& nombre) {
    //Elimina el enrutador del mapa de enrutadores
    enrutadores.erase(nombre);

    //Elimina las rutas hacia el enrutador eliminado en las tablas de otros enrutadores
    for (auto& [nombreEnrutador, enrutador] : enrutadores) {
        map<string, int>& tabla = enrutador.getTabla();
        auto it = tabla.find(nombre);
        if (it != tabla.end()) {
            tabla.erase(it);
        }
    }
}

void Red::agregarRuta(const string& origen, const string& destino, int costo) {
    agregarEnrutador(origen);
    agregarEnrutador(destino);
    enrutadores[origen].costoRuta(destino, costo);
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
        int costo;

        if (streamLinea >> origen >> destino >> costo) {
            agregarRuta(origen, destino, costo);
        }
    }

    archivo.close();
}

void Red::mostrarRed() const {
    for (const auto& [nombre, enrutador] : enrutadores) {
        enrutador.mostrarTabla();
    }
}
