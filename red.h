#ifndef RED_H
#define RED_H

#include "enrutador.h"
#include <vector>
#include <algorithm>

class Red{
private:
    vector<Enrutador> enrutadores;
public:
    void agregarEnrutador(const Enrutador& enrutador);
    void eliminarEnrutador(const string& nombreEnrutador);
    void mostrarRed() const;
};

#endif // RED_H
