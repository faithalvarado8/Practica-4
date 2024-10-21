#ifndef RED_H
#define RED_H

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include "Enrutador.h"
using namespace std;

class Red {
private:
    map<string, Enrutador> enrutadores;

public:
    // Métodos
    void agregarEnrutador(const string& nombre);
    void eliminarEnrutador(const string& nombre);
    void agregarRuta(const string& origen, const string& destino, int costo);
    void cargarDesdeArchivo(const string& nombreArchivo);
    void mostrarRed() const;
};

#endif // RED_H
