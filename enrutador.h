#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Enrutador {
private:
    string nombre;
    map<string, int> tablaEnrutamiento;  // Destino y costo

public:
    // Constructor
    Enrutador();
    Enrutador(const string& nombreEnrutador);

    // Metodos
    void costoRuta(const string& destino, int costo);
    map<string, int> getTabla() const;
    string getNombre() const;
    void mostrarTabla() const;
};

#endif // ENRUTADOR_H
