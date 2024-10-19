#include "red.h"
#include <iostream>
#include <vector>
#include <algorithm>

void Red::agregarEnrutador(const Enrutador& enrutador) {
    enrutadores.push_back(enrutador);
}

void Red::eliminarEnrutador(const string& nombreEnrutador) {
    enrutadores.erase(remove_if(enrutadores.begin(), enrutadores.end(),
    [&](const Enrutador& enrutador) { return enrutador.getNombre() == nombreEnrutador; }),
    enrutadores.end());
}

void Red::mostrarRed() const {
    cout << "Estado de la red: " << endl;
    for (const auto& enrutador : enrutadores) {
        enrutador.mostrarTabla();
    }
}
