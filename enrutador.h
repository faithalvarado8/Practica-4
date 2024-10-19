#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <string>
#include <map>
using namespace std;

class Enrutador{
private:
    string nombre;
    map<string, int> tablaEnrutamiento;

public:
    Enrutador(const string& nombreEnrutador);
    void agregarRuta(const string& destino, int costo);
    void actualizarRuta(const string& destino, int nuevoCosto);
    void mostrarTabla() const;
    string getNombre() const;
};

#endif // ENRUTADOR_H
