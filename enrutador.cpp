#include "Enrutador.h"

Enrutador::Enrutador(){
}

Enrutador::Enrutador(const string& nombreEnrutador) : nombre(nombreEnrutador) {}

void Enrutador::costoRuta(const string& destino, int costo) {
    tablaEnrutamiento[destino] = costo;
}

map<string, int> Enrutador::getTabla() const {
    return tablaEnrutamiento;
}

string Enrutador::getNombre() const {
    return nombre;
}

void Enrutador::mostrarTabla() const {
    cout << "Tabla de enrutamiento para " << nombre << ":\n";
    for (const auto& entrada : tablaEnrutamiento) {
        cout << "Destino: " << entrada.first << " - Costo: " << entrada.second << "\n";
    }
}
