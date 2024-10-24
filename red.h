#ifndef RED_H
#define RED_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <limits>
#include <fstream>
#include <sstream>
#include "Enrutador.h"
using namespace std;

class Red {
private:
    map<string, Enrutador> enrutadores;

public:
    void agregarEnrutador(const string& nombre);
    void eliminarEnrutador(const string& nombre);
    void agregarRuta(const string& origen, const string& destino, float costo);
    void cargarDesdeArchivo(const string& nombreArchivo);
    void caminoMasCorto(string origen, string destino);
    void mostrarRed() const;
    void borrarRed();
};

#endif // RED_H

