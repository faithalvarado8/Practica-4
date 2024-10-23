#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Enrutador {
private:
    string nombre;
    map<string, float> tablaEnrutamiento;  // Destino y costo


public:
    Enrutador();
    Enrutador(const string& nombreEnrutador);

    void costoRuta(const string& destino, float costo);
    map<string, float>& getTabla();
    string getNombre() const;
    void mostrarTabla() const;
};

#endif // ENRUTADOR_H
