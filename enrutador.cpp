#include "enrutador.h"

#include <iostream>
#include <map>
#include <string>

Enrutador::Enrutador(const string& nombreEnrutador) : nombre(nombreEnrutador) {}

void Enrutador::agregarRuta(const string& destino, int costo) {
    tablaEnrutamiento[destino] = costo;
}

void Enrutador::actualizarRuta(const string& destino, int nuevoCosto) {
    if (tablaEnrutamiento.find(destino) != tablaEnrutamiento.end()) {
        tablaEnrutamiento[destino] = nuevoCosto;
    }
}

void Enrutador::mostrarTabla() const {
    cout << "Tabla de enrutamiento para " << nombre << ":" << endl;
    for (const auto& entrada : tablaEnrutamiento) {
        cout << "Destino: " << entrada.first << " - Costo: " << entrada.second << endl;
    }
    cout << endl << endl;
}

string Enrutador::getNombre() const {
    return nombre;
}

