#include "Enrutador.h"

Enrutador::Enrutador(){
}

Enrutador::Enrutador(const string& nombreEnrutador) : nombre(nombreEnrutador) {}

void Enrutador::costoRuta(const string& destino, float costo) {
    tablaEnrutamiento[destino] = costo;
}

map<string, float>& Enrutador::getTabla() {
    return tablaEnrutamiento;
}

string Enrutador::getNombre() const {
    return nombre;
}

void Enrutador::mostrarTabla() const {
    cout << "Tabla de enrutamiento para " << nombre << ":\n";
    for (const auto& entrada : tablaEnrutamiento) {
        cout << nombre << " -> " << entrada.first << " (Costo: " << entrada.second << ")" << endl;
    }
}

